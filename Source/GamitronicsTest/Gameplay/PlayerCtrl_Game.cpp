#include "PlayerCtrl_Game.h"


APlayerCtrl_Game::APlayerCtrl_Game()
{
	
}

void APlayerCtrl_Game::BeginPlay()
{
	bShowMouseCursor = true;
	SetInputMode(FInputModeGameAndUI());
}
