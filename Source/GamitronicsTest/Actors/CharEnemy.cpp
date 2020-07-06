
#include "CharEnemy.h"

ACharEnemy::ACharEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	//HealthBar = CreateDefaultSubobject <UWidgetComponent>(TEXT("HealthBar"));
	SenseComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("SenseComponent"));
	//GunMesh->SetupAttachment(GetMesh(), FName(TEXT("Weapon")));

}

void ACharEnemy::BeginPlay()
{
	Super::BeginPlay();
	//this->OnTakeAnyDamage.AddDynamic(this, &ACharEnemy::OnDamage);
	MaxHealth = 100.0f;
	Health = 100.0f;
	bOnce = true;

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
	Destroy();
}
