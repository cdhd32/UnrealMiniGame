// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniGameAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"

UMiniGameAnimInstance::UMiniGameAnimInstance()
{

}

void UMiniGameAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwnerPawn = TryGetPawnOwner();
	OwnerCharater = Cast<ACharacter>(OwnerPawn);

	SkeletalMesh = OwnerCharater->GetMesh();
	SkeletalMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);

	static ConstructorHelpers::FObjectFinder<UAnimSequence> ThirdPersonRun(TEXT("/Game/Mannequin/Animations/ThirdPersonRun.ThirdPersonRun"));
	if (ThirdPersonRun.Succeeded())
		RunAnimation = ThirdPersonRun.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> ThirdPersonIdle(TEXT("/Game/Mannequin/Animations/ThirdPersonIdle.ThirdPersonIdle"));
	if (ThirdPersonRun.Succeeded())
		IdleAnimation = ThirdPersonIdle.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> ThirdPersonJump_Start(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Start.ThirdPersonJump_Start"));
	if (ThirdPersonRun.Succeeded())
		JumpStartAnimation = ThirdPersonJump_Start.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> ThirdPersonJump_Loop(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_Loop.ThirdPersonJump_Loop"));
	if (ThirdPersonRun.Succeeded())
		JumpLoopAnimation = ThirdPersonJump_Loop.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> ThirdPersonJump_End(TEXT("/Game/Mannequin/Animations/ThirdPersonJump_End.ThirdPersonJump_End"));
	if (ThirdPersonRun.Succeeded())
		JumpEndAnimation = ThirdPersonJump_End.Object;

}

void UMiniGameAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(OwnerPawn))
	{
		CurrentPawnSpeed = OwnerPawn->GetVelocity().Size();
		
		if (OwnerCharater)
		{
			IsInAir = OwnerCharater->GetMovementComponent()->IsFalling();
		}
	}

	if (CurrentPawnSpeed > 0.f && IsPlayingSlotAnimation(RunAnimation, "Run"))
		PlaySlotAnimationAsDynamicMontage(RunAnimation, "Run");


}

void UMiniGameAnimInstance::PlayRunSequence()
{

}
