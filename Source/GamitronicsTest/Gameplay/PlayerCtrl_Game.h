
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "W_HUD.h"
#include "W_GameOver.h"
#include "PlayerCtrl_Game.generated.h"

UCLASS()
class GAMITRONICSTEST_API APlayerCtrl_Game : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APlayerCtrl_Game();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UW_HUD* HUD;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UW_GameOver* GameOverUI;

	UFUNCTION(BlueprintImplementableEvent)
		void GameOver(int32 Kills);
	
};
