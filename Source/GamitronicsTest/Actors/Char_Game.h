#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Actors/GunProjectile.h"
#include "Char_Game.generated.h"

UCLASS()
class GAMITRONICSTEST_API AChar_Game : public ACharacter
{
	GENERATED_BODY()

public:
	AChar_Game();

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USkeletalMeshComponent* SKGunMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Ammo;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Muzzle;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGunProjectile> BulletClass;

	UFUNCTION()
	void Fire();
	

};
