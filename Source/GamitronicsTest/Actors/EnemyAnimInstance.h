// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharEnemy.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMITRONICSTEST_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Angle;

	ACharEnemy* OwningPawn;

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTimeX) override;
};
