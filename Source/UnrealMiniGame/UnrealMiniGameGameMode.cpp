// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMiniGameGameMode.h"
#include "MiniGameCharacter.h"
#include "MiniGamePlayerController.h"
#include "UObject/ConstructorHelpers.h"


AUnrealMiniGameGameMode::AUnrealMiniGameGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	DefaultPawnClass = AMiniGameCharacter::StaticClass();
	PlayerControllerClass = AMiniGamePlayerController::StaticClass();


}
