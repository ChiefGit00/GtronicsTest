#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerHelp.generated.h"

UCLASS()
class GAMITRONICSTEST_API APlayerHelp : public AActor
{
	GENERATED_BODY()
	
public:	
	APlayerHelp();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
