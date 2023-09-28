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
	UFUNCTION(BlueprintCallable) int32 getHp();
	UFUNCTION(BlueprintCallable) int32 getAtkEffect();
	UFUNCTION(BlueprintCallable) int32 getDefence();
	UFUNCTION(BlueprintCallable) int32 getDodgeChance();
	UFUNCTION(BlueprintCallable) int32 getCritChance();
	UFUNCTION(BlueprintCallable) int32 getCritEffect();
	UFUNCTION() void setHp(int32 newHP);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere) int32 hp;
	UPROPERTY(EditAnywhere) int32 atkEffect;
	UPROPERTY(EditAnywhere) int32 defence;
	UPROPERTY(EditAnywhere) int32 dodgeChance;
	UPROPERTY(EditAnywhere) int32 critChance;
	UPROPERTY(EditAnywhere) int32 critEffect;





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
