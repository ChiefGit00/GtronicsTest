
#include "PlayerHelp.h"

APlayerHelp::APlayerHelp()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerHelp::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerHelp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

