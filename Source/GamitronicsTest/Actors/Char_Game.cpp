
#include "Char_Game.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCtrl_Game.h"
#include "Kismet/KismetMathLibrary.h"

AChar_Game::AChar_Game()
{
	PrimaryActorTick.bCanEverTick = true;
	SKGunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("GunMuzzle"));

	SKGunMesh->SetupAttachment(GetMesh(), FName(TEXT("Weapon")));
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->TargetArmLength = 800.0f;
	Muzzle->SetupAttachment(SKGunMesh);
	Muzzle->SetRelativeLocation(FVector(0.0f, 58.0f, 11.0f));

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	bUseControllerRotationYaw = false;
	bOnce = true;
	AttackPoint = 20.0f;
}

void AChar_Game::BeginPlay()
{
	Super::BeginPlay();
	MaxAmmo = Ammo = 20;
	MaxHealth = Health = 100;
	CurrentHitPoint = TotalHitPoints = 0;
	CurrentPower = MaxPower = 100;
	
}

void AChar_Game::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;
	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursor(ECC_Visibility, true, HitResult))
	{
		Angle = UKismetMathLibrary::NormalizedDeltaRotator(
				UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), HitResult.ImpactPoint), GetActorRotation()).Yaw;
		
	}
	
}

void AChar_Game::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AChar_Game::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AChar_Game::MoveRight);
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &AChar_Game::Fire);
}

void AChar_Game::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (Cast<APlayerCtrl_Game>(NewController))
	{
		Ctrl = Cast<APlayerCtrl_Game>(NewController);
		/*Ctrl->HUD->UpdateAmmo(Ammo);
		Ctrl->HUD->UpdateHealth(Health / MaxHealth);
		Ctrl->HUD->UpdateHitPoints(CurrentHitPoint);*/
	}
}

void AChar_Game::MoveForward(float Value)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void AChar_Game::MoveRight(float Value)
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
}

void AChar_Game::Fire()
{
	if (Ammo > 0)
	{
		if (BulletClass)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			GetWorld()->SpawnActor<AGunProjectile>(BulletClass, Muzzle->GetComponentLocation(), FRotator (0.0f, Muzzle->GetComponentRotation().Yaw + 90.0f, 0.0f), SpawnParams);
			Ammo -= 1;
			Ctrl->HUD->UpdateAmmo(Ammo/MaxAmmo);
		}		
	}
}

void AChar_Game::AddHPonHit(int32 HitPoint)
{
	TotalHitPoints += HitPoint;
	Level = TotalHitPoints / 4;
	CurrentHitPoint = TotalHitPoints % 4;
	if (CurrentHitPoint == 0)
		CurrentHitPoint = 4;
	
	Ctrl->HUD->UpdateLevel(Level);
	Ctrl->HUD->UpdateHitPoints(CurrentHitPoint/4);

	if (Level > 0)
		AttackPoint += (Level * 5);

	OnEnemyHitUpdate();
	
}

void AChar_Game::TakeHealth(float Amount)
{
	Health += Amount;
		if (Health > MaxHealth)
			Health = MaxHealth;
	Ctrl->HUD->UpdateHealth(Health/MaxHealth);
}

void AChar_Game::TakeAmmo(float Amount)
{
	Ammo += Amount;
	if (Ammo > MaxAmmo)
		Ammo = MaxAmmo;
	Ctrl->HUD->UpdateAmmo(Ammo / MaxAmmo);
}

void AChar_Game::TakePower(float Amount)
{
	CurrentPower += Amount;
		if (CurrentPower > MaxPower)
			CurrentPower = MaxPower;
	Ctrl->HUD->UpdatePower(CurrentPower/MaxPower);
}

void AChar_Game::TakeDamage(float Amount)
{
	Health -= Amount;
	if (Health <= 0)
	{
		Health = 0;
		Ctrl->HUD->UpdateHealth(Health / MaxHealth);
		FTimerHandle tTimer;
		if (bOnce)
		{
			bOnce = false;
			GetMesh()->PlayAnimation(DeathAnim, false);
			GetCharacterMovement()->DisableMovement();
			Ctrl->GameOver();
			GetWorldTimerManager().SetTimer(tTimer, this, &AChar_Game::Death, 1.8f, false);
		}
	
	}
	else
		Ctrl->HUD->UpdateHealth(Health / MaxHealth);
}

void AChar_Game::Death()
{
	GetMesh()->SetVisibility(false);
	SKGunMesh->SetVisibility(false);
}
