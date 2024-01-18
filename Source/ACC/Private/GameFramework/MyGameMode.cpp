// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyPawn::StaticClass();
	HUDClass = AMyHUD::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
	GameStateClass = AMyGameState::StaticClass();
	PlayerStateClass = AMyPlayerState::StaticClass();
	SpectatorClass = AMySpectatorPawn::StaticClass();
}
