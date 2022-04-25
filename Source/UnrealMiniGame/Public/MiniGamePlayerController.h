// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MiniGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALMINIGAME_API AMiniGamePlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	TWeakPtr<APawn> OwnerPawn;
	TWeakPtr<ACharacter> OwnerCharacter;
public:
	AMiniGamePlayerController();

protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void AddControllerYawInput(float Val);
	void AddControllerPitchInput(float Val);

	void Jump();
	void StopJumping();
protected:
	virtual void SetupInputComponent() override;
};
