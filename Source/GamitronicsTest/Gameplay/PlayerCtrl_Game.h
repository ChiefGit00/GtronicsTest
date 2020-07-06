
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCtrl_Game.generated.h"

UCLASS()
class GAMITRONICSTEST_API APlayerCtrl_Game : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APlayerCtrl_Game();
	
};
