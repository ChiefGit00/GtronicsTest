#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_GameOver.generated.h"

UCLASS()
class GAMITRONICSTEST_API UW_GameOver : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
		void Restart();

	UFUNCTION(BlueprintCallable)
		void MainMenu();

	public:
	UFUNCTION(BlueprintImplementableEvent)
		void KillPoints(int32 Kills);
	
};
