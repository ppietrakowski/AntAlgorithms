// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindWayToAntColony.generated.h"

/**
 * 
 */
UCLASS()
class ANTALGORITHMS_API UFindWayToAntColony : public UBTTaskNode
{
	GENERATED_BODY()
public:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector OutPositionKey;
};
