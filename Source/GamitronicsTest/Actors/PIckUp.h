#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PIckUp.generated.h"

UENUM(BlueprintType)
enum class EPickUpType : uint8
{
	Ammo,
	Health,
	BulletTime
};

UCLASS()
class GAMITRONICSTEST_API APIckUp : public AActor
{
	GENERATED_BODY()
	
public:	
	APIckUp();
	APIckUp(EPickUpType PickUpType);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPickUpType PickUpType;

	UFUNCTION(BlueprintImplementableEvent)
		void SetPickUpType(EPickUpType PickUp);

	UFUNCTION()
		void OnPickUp(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

};
