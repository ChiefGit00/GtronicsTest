// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCtrl_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class GAMITRONICSTEST_API APlayerCtrl_MainMenu : public APlayerController
{
	GENERATED_BODY()

	protected:
		virtual void BeginPlay() override;

	public:
		APlayerCtrl_MainMenu();
	
};
