#include "W_GameOver.h"
#include "Kismet/GameplayStatics.h"


void UW_GameOver::Restart()
{
	UGameplayStatics::OpenLevel(this, "Map");
}

void UW_GameOver::MainMenu()
{
	UGameplayStatics::OpenLevel(this, "MainMenu");
}

