// Copyright Epic Games, Inc. All Rights Reserved.

#include "Hack_n_Slash_ProjectGameMode.h"
#include "Hack_n_Slash_ProjectPlayerController.h"
#include "Hack_n_Slash_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHack_n_Slash_ProjectGameMode::AHack_n_Slash_ProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHack_n_Slash_ProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
// 	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
// 	if (PlayerPawnBPClass.Class != NULL)
// 	{
// 		DefaultPawnClass = PlayerPawnBPClass.Class;
// 	}
}