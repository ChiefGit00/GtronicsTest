
#include "Help.h"
#include "Char_Game.h"

AHelp::AHelp()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AHelp::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AHelp::DisplayHelp);
	Mesh->OnComponentEndOverlap.AddDynamic(this, &AHelp::HideHelp);
}

void AHelp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHelp::DisplayHelp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AChar_Game>(OtherActor))
	{
		Cast<AChar_Game>(OtherActor)->Ctrl->HUD->DisplayHelpText(bText	);
	}
}

void AHelp::HideHelp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AChar_Game>(OtherActor))
	{
		Cast<AChar_Game>(OtherActor)->Ctrl->HUD->HideHelpText();
	}
}
