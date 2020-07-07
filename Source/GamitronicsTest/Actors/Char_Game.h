#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Actors/GunProjectile.h"
#include "PlayerCtrl_Game.h"
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

	virtual void PossessedBy(AController* NewController) override;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 LevelThreshold;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Muzzle;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGunProjectile> BulletClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 TotalHitPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentHitPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MaxPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		APlayerCtrl_Game* Ctrl;

	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;
	
	UPROPERTY(VisibleAnywhere)
		float LevelDelta;

	UPROPERTY(VisibleAnywhere)
		float AttackPoint;

	UPROPERTY(VisibleAnywhere)
		int32 Kills;

	UPROPERTY()
		FTimerHandle BulletTimer;
	UPROPERTY()
		bool bBulletTime;

	UFUNCTION()
		void Fire();

	UFUNCTION()
		void AddHPonHit(int32 HitPoint);

	UFUNCTION(BlueprintImplementableEvent)
		void OnEnemyHitUpdate();

	UFUNCTION()
		void TakeHealth(float Amount);

	UFUNCTION()
		void TakeAmmo(float Amount);
	
	UFUNCTION()
		void TakePower(float Amount);

	UFUNCTION()
		void TakeDamage(float Amount);

	UFUNCTION()
		void AddKillPoint();

	UFUNCTION()
		void BulletTimeOn();
	UFUNCTION()
		void BulletTimeOff();

	UPROPERTY()
		bool bOnce;

	UFUNCTION()
		void Death();

};
