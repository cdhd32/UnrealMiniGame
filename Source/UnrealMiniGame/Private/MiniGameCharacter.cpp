// Fill out your copyright notice in the Description page of Project Settings.

#include "MiniGameCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "MiniGameAnimInstance.h"

// Sets default values
AMiniGameCharacter::AMiniGameCharacter()
{
	//PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	Capsule = GetCapsuleComponent();
	Capsule->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> PlayerModel(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));

	if (PlayerModel.Succeeded()) {
		GetMesh()->SetSkeletalMesh(PlayerModel.Object);
		SkeletalMesh = GetMesh();
	}

	SkeletalMesh->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -97.0), FRotator(0.f, -90.f, 0.f));
	
	SkeletalMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//AnimInstance = Cast<UMiniGameAnimInstance>(SkeletalMesh->GetAnimInstance());
	static ConstructorHelpers::FClassFinder<UAnimInstance> ThirdPerson_AnimBP_C(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP_C"));
	
	if (ThirdPerson_AnimBP_C.Succeeded())
	{
		SkeletalMesh->SetAnimInstanceClass(ThirdPerson_AnimBP_C.Class);
	}
	

	
	
	//#BPÁ¦°Å
	/*SkeletalMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance>  ThirdPersonAnimBP(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));

	if (ThirdPersonAnimBP.Succeeded())
	{
		SkeletalMesh->SetAnimInstanceClass(ThirdPersonAnimBP.Class);
	}*/

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	Movement->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	Movement->JumpZVelocity = 600.f;
	Movement->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->AddRelativeLocation(FVector(0.f, 0.f, 120.f));
	CameraBoom->AddRelativeRotation(FRotator(0.f, 45.f, 0.f));

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AMiniGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	//Animation Test
	/*GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	UAnimationAsset* AnimAsset = LoadObject<UAnimationAsset>(nullptr, TEXT("/Game/Mannequin/Animations/ThirdPersonRun.ThirdPersonRun"));

	if (AnimAsset != nullptr)
	{
		SkeletalMesh->PlayAnimation(AnimAsset, true);
	}*/
}

void AMiniGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMiniGameCharacter::SetControlMode(int32 controlMode)
{
	if (controlMode == 0)
	{
		CameraBoom->TargetArmLength = 450.0f;
		CameraBoom->SetRelativeRotation(FRotator::ZeroRotator);
		CameraBoom->bUsePawnControlRotation = true;
		CameraBoom->bInheritPitch = true;
		CameraBoom->bInheritRoll = true;
		CameraBoom->bInheritYaw = true;
		CameraBoom->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	}
}

// Called to bind functionality to input
//void AMiniGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//	// Set up gameplay key bindings
//	check(PlayerInputComponent);
//	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
//	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
//
//	PlayerInputComponent->BindAxis("MoveForward", this, &AMiniGameCharacter::MoveForward);
//	PlayerInputComponent->BindAxis("MoveRight", this, &AMiniGameCharacter::MoveRight);
//
//	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
//	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
//
//}

//void AMiniGameCharacter::MoveForward(float Value)
//{
//	if ((Controller != nullptr) && (Value != 0.0f))
//	{
//		// find out which way is forward
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//		// get forward vector
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
//		AddMovementInput(Direction, Value);
//	}
//}
//
//void AMiniGameCharacter::MoveRight(float Value)
//{
//	if ((Controller != nullptr) && (Value != 0.0f))
//	{
//		// find out which way is right
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//		// get right vector 
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
//		// add movement in that direction
//		AddMovementInput(Direction, Value);
//	}
//}
