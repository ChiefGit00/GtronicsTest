
#include "PIckUp.h"
#include "Char_Game.h"

APIckUp::APIckUp()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void APIckUp::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &APIckUp::OnPickUp);
	
}

void APIckUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APIckUp::OnPickUp(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AChar_Game>(OtherActor))
	{
		AChar_Game* Char = Cast<AChar_Game>(OtherActor);

		switch (PickUpType)
		{
		case EPickUpType::Health: Char->TakeHealth(50); break;
		case EPickUpType::Ammo: Char->TakeAmmo(20); break;
		case EPickUpType::BulletTime: Char->TakePower(50); break;
		}

		Destroy();
	}
}

