// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Delegates/Delegate.h"
#include "Runtime/CoreUObject/Public/UObject/Class.h"
#include "AntColonySimulation.generated.h"


UCLASS()
class ANTALGORITHMS_API UAntColonySimulation : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UAntColonySimulation();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE bool HasParameterChanged() const
	{
		return bChangedParameters;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetDistanceStrength() const
	{
		return DistanceStrength;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetPheromoneStrength() const
	{
		return DistanceStrength;
	}

	UFUNCTION(BlueprintCallable)
	void SetDistanceStrength(float NewDistanceStrength);

	UFUNCTION(BlueprintCallable)
	void SetPheromoneStrength(float NewPheromoneStrength);
private:
	float DistanceStrength;
	float PheromoneStrength;

	bool bChangedParameters;
};
