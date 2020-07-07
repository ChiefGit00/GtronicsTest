#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "PIckUp.h"
#include "GunProjectile.h"
#include "CharEnemy.generated.h"

UENUM()
enum class EEnemyType : uint8
{
	EnemyTurret,
	EnemyMove,
	EnemyMoveII
};


UCLASS()
class GAMITRONICSTEST_API ACharEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ACharEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* GunMesh;

	//UPROPERTY(VisibleAnywhere)
	//	UWidgetComponent* HealthBar;

	UPROPERTY(VisibleAnywhere)
		UPawnSensingComponent* SenseComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EnemyAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* DeathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class APIckUp> PickUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyType Enemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPickUpType DropType;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGunProjectile> Bullet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Muzzle;

	//void OnDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(float Damage);

	UFUNCTION(BlueprintCallable)
		void OnDeath();

	bool bOnce;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent)
		void SetEnemyType();

	UFUNCTION()
		void Attack(APawn* Player);

	UFUNCTION(BlueprintImplementableEvent)
		void FollowPlayer(APawn* Player);

	UFUNCTION()
		void Fire();
};
