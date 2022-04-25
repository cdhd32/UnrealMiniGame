// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MiniGameCharacter.generated.h"

UCLASS()
class UNREALMINIGAME_API AMiniGameCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnyWhere, Category = Collision)
	class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnyWhere, Category = Visual)
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnyWhere, Category = Movement)
	class UCharacterMovementComponent* Movement;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnyWhere, Category = Animation)
	class UAnimInstance* AnimInstance;


protected:
	

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

public:
	// Sets default values for this character's properties
	AMiniGameCharacter();

	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetControlMode(int32 controlMode);

public:	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
