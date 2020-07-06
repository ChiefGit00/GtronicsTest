#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Char_Game.h"
#include "PlayerCharAnimInstance.generated.h"

UCLASS()
class GAMITRONICSTEST_API UPlayerCharAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Angle;

	AChar_Game* OwningPawn;
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DelataTimeX) override;
		
};
