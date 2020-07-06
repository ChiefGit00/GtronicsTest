#include "PlayerCharAnimInstance.h"

void UPlayerCharAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwningPawn = Cast<AChar_Game>(TryGetPawnOwner());
}


void UPlayerCharAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	if (!OwningPawn)
	{
		return;
	}

	Speed = OwningPawn->GetVelocity().Size();
	Angle = OwningPawn->Angle;
}

