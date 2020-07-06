#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "CharEnemy.generated.h"


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

	//void OnDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(float Damage);

	UFUNCTION(BlueprintCallable)
		void OnDeath();

	bool bOnce;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

};
