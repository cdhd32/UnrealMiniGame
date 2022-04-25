// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MiniGameAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALMINIGAME_API UMiniGameAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	class ACharacter* OwnerCharater = nullptr;
	class APawn* OwnerPawn = nullptr;
	class USkeletalMeshComponent* SkeletalMesh = nullptr;
public:
	UMiniGameAnimInstance();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void SetPawnSpeed(float NewPawnSPeed) { CurrentPawnSpeed = NewPawnSPeed; }

	void PlayRunSequence();
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir = false;

	UAnimSequence* RunAnimation;
	UAnimSequence* IdleAnimation;
	UAnimSequence* JumpStartAnimation;
	UAnimSequence* JumpLoopAnimation;
	UAnimSequence* JumpEndAnimation;
};
