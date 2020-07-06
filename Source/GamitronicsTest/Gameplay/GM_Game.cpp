#include "GM_Game.h"
#include "GamitronicsTest/Actors/Char_Game.h"
#include "PlayerCtrl_Game.h"
#include "UObject/ConstructorHelpers.h"

AGM_Game::AGM_Game()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBP(TEXT("/Game/Blueprints/Actors/Chars/PlayerChar_Game"));

	if (PlayerPawnBP.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBP.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerCtrl(TEXT("/Game/Blueprints/Gameplay/Ctrl_Game"));

	if (PlayerCtrl.Class != NULL)
	{
		PlayerControllerClass = PlayerCtrl.Class;
	}

	//PlayerControllerClass = APlayerCtrl_Game::StaticClass();
		
}
