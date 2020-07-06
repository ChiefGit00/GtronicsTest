#include "PlayerCtrl_Game.h"


APlayerCtrl_Game::APlayerCtrl_Game()
{
	
}

void APlayerCtrl_Game::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	SetInputMode(FInputModeGameAndUI());
}
