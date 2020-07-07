
#include "CharEnemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "PIckUp.h"

ACharEnemy::ACharEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	//HealthBar = CreateDefaultSubobject <UWidgetComponent>(TEXT("HealthBar"));
	SenseComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("SenseComponent"));
	GunMesh->SetupAttachment(GetMesh(), FName(TEXT("Weapon")));
	Muzzle->SetupAttachment(GunMesh);

	Muzzle->SetRelativeLocation(FVector(0.0f, 58.0f, 11.0f));
	

}

void ACharEnemy::BeginPlay()
{
	Super::BeginPlay();
	//this->OnTakeAnyDamage.AddDynamic(this, &ACharEnemy::OnDamage);
	MaxHealth = 100.0f;
	Health = 100.0f;
	bOnce = true;
	SetEnemyType();

	SenseComponent->OnSeePawn.AddDynamic(this, &ACharEnemy::Attack);

}

void ACharEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//void ACharEnemy::OnDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
//{
//	//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, "TExt");
//}


float ACharEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;
	OnDamaged(DamageAmount);
	if (Health <= 0)
	{
		FTimerHandle FTimer;
		
		if(bOnce)
		{
			bOnce = false;
			GetMesh()->PlayAnimation(DeathAnim, false);
			GetWorldTimerManager().SetTimer(FTimer, this, &ACharEnemy::OnDeath, 1.8f, false);
		} 
	}
	return 0.0f;
}

void ACharEnemy::OnDeath()
{
	GetWorld()->SpawnActor<APIckUp>(PickUp, GetActorLocation(), GetActorRotation())->SetPickUpType(DropType);
	Destroy();
}

void ACharEnemy::Attack(APawn* Player)
{
	EnemyAngle = UKismetMathLibrary::NormalizedDeltaRotator(
			UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Player->GetActorLocation()), GetActorRotation()).Yaw;
	if (Enemy == EEnemyType::EnemyMove)
	{
		FollowPlayer(Player);
	}

	Fire();
}

void ACharEnemy::Fire()
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	GetWorld()->SpawnActor<AGunProjectile>(Bullet, Muzzle->GetComponentLocation(), FRotator(0.0f, Muzzle->GetComponentRotation().Yaw + 90.0f, 0.0f), Params);
}