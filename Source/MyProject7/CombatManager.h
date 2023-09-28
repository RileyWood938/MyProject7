// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatManager.generated.h"

UCLASS()
class MYPROJECT7_API ACombatManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatManager();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ACombatant* Combatant1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ACombatant* Combatant2;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION() void fight();
	UFUNCTION() bool dieRoll(int32 odds);
	UFUNCTION() void attack(ACombatant* attacker, ACombatant* defender);
	UFUNCTION() bool checkIfDead();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
