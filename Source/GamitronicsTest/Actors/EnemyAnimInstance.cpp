// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwningPawn = Cast<ACharEnemy>(TryGetPawnOwner());
}

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	if (!OwningPawn)
	{
		return;
	}
	Speed = OwningPawn->GetVelocity().Size();
	Angle = OwningPawn->EnemyAngle;

}

