// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniGameWeapon.h"


// Sets default values
AMiniGameWeapon::AMiniGameWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT(
		"/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_Fencer/SK_Blade_Fencer.SK_Blade_Fencer"));

	if (SK_WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	}

	Weapon->SetCollisionProfileName(TEXT("NoCOllision"));  //충돌 프리셋 설정
}

// Called when the game starts or when spawned
void AMiniGameWeapon::BeginPlay()
{
	Super::BeginPlay();



	//CurWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);

}

// Called every frame
void AMiniGameWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

