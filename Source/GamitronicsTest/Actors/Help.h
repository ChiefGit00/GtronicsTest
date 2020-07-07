#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Help.generated.h"

UCLASS()
class GAMITRONICSTEST_API AHelp : public AActor
{
	GENERATED_BODY()
	
public:	
	AHelp();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText HelpText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bText;

	UFUNCTION()
		void DisplayHelp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void HideHelp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
