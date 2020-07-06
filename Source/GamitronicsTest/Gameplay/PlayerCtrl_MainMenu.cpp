// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCtrl_MainMenu.h"

APlayerCtrl_MainMenu::APlayerCtrl_MainMenu()
{
	bShowMouseCursor = true;
	SetInputMode(FInputModeUIOnly());
}

void APlayerCtrl_MainMenu::BeginPlay()
{
	Super::BeginPlay();
}

