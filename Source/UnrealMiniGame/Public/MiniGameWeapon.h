// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniGameWeapon.generated.h"

UCLASS()
class UNREALMINIGAME_API AMiniGameWeapon : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnyWhere, Category = Weapon)
	USkeletalMeshComponent* Weapon;

public:	
	// Sets default values for this actor's properties
	AMiniGameWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
