#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_HUD.generated.h"


UCLASS()
class GAMITRONICSTEST_API UW_HUD : public UUserWidget
{
	GENERATED_BODY()

	
public:	
	UFUNCTION(BlueprintImplementableEvent)
		void UpdateHealth(float Health);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateAmmo(float Ammo);
	
	UFUNCTION(BlueprintImplementableEvent)
		void UpdateLevel(int32 Level);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdateHitPoints(float HitPoints);

	UFUNCTION(BlueprintImplementableEvent)
		void UpdatePower(float Power);

	UFUNCTION(BlueprintImplementableEvent)
		void DisplayHelpText(bool Help);

	UFUNCTION(BlueprintImplementableEvent)
		void HideHelpText();
};
