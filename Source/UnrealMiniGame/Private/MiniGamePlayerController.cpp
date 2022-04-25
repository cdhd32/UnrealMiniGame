// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniGamePlayerController.h"

#include "MiniGameCharacter.h"

#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"

#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AMiniGamePlayerController::AMiniGamePlayerController()
{

}

void AMiniGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = GetPawn();
	OwnerCharacter = GetCharacter();
}

void AMiniGamePlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		if (IsValid(OwnerPawn))
			OwnerPawn->AddMovementInput(Direction, Value);
	}
}

void AMiniGamePlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		if (IsValid(OwnerPawn))
			OwnerPawn->AddMovementInput(Direction, Value);
	}
}

void AMiniGamePlayerController::AddControllerYawInput(float Val)
{
	if(IsValid(OwnerPawn))
		OwnerPawn->AddControllerYawInput(Val);
}

void AMiniGamePlayerController::AddControllerPitchInput(float Val)
{
	if (IsValid(OwnerPawn))
		OwnerPawn->AddControllerPitchInput(Val);
}

void AMiniGamePlayerController::Jump()
{
	OwnerCharacter->Jump();
}

void AMiniGamePlayerController::StopJumping()
{
	OwnerCharacter->StopJumping();
}

void AMiniGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMiniGamePlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMiniGamePlayerController::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &AMiniGamePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMiniGamePlayerController::MoveRight);

	InputComponent->BindAxis("Turn", this, &AMiniGamePlayerController::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMiniGamePlayerController::AddControllerPitchInput);

	
}



