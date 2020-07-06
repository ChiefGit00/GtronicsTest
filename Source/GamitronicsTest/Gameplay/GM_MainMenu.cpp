#include "GM_MainMenu.h"
#include "PlayerCtrl_MainMenu.h"
#include "PlayerCtrl_MainMenu.h"
#include "UObject/ConstructorHelpers.h"

AGM_MainMenu::AGM_MainMenu()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerCtrlBP(TEXT("/Game/Blueprints/Gameplay/Ctrl_MainMenu"));
	if (PlayerCtrlBP.Class != NULL)
	{
		PlayerControllerClass = PlayerCtrlBP.Class;
	}
	
}

