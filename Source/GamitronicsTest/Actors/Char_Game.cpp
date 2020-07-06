
#include "Char_Game.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
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
}

void AChar_Game::BeginPlay()
{
	Super::BeginPlay();
	MaxAmmo = Ammo = 20;
	
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
		}		
	}
}

