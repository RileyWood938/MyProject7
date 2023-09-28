// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combatant.generated.h"

UCLASS(abstract)
class MYPROJECT7_API ACombatant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatant();
	UFUNCTION() int32 getHp();
	UFUNCTION() int32 getAtkEffect();
	UFUNCTION() int32 getDefence();
	UFUNCTION() int32 getDodgeChance();
	UFUNCTION() int32 getCritChance();
	UFUNCTION() int32 getCritEffect();
	UFUNCTION() void setHp(int32 newHP);
	UFUNCTION() void resetHp();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere) int32 hp;
	UPROPERTY(EditAnywhere) int32 atkEffect;
	UPROPERTY(EditAnywhere) int32 defence;
	UPROPERTY(EditAnywhere) int32 dodgeChance;
	UPROPERTY(EditAnywhere) int32 critChance;
	UPROPERTY(EditAnywhere) int32 critEffect;
	UPROPERTY(EditAnywhere) int32 maxHp;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
