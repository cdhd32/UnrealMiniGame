// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniGamePlayerController.h"

#include "MiniGameCharacter.h"

#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"

#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AMiniGamePlayerController::AMiniGamePlayerController()
{
	OwnerPawn = MakeShared<APawn>(GetPawn());
	OwnerCharacter = MakeShared<ACharacter>(GetCharacter());
}

void AMiniGamePlayerController::MoveForward(float Value)
{

}

void AMiniGamePlayerController::MoveRight(float Value)
{

}

void AMiniGamePlayerController::AddControllerYawInput(float Val)
{
//#checkpoint
	if(OwnerPawn.IsValid())
		OwnerPawn.Pin()->AddControllerYawInput(Val);
}

void AMiniGamePlayerController::AddControllerPitchInput(float Val)
{

}

void AMiniGamePlayerController::Jump()
{

}

void AMiniGamePlayerController::StopJumping()
{

}

void AMiniGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up gameplay key bindings
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMiniGamePlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMiniGamePlayerController::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &AMiniGamePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMiniGamePlayerController::MoveRight);

	InputComponent->BindAxis("Turn", this, &AMiniGamePlayerController::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMiniGamePlayerController::AddControllerPitchInput);
}
