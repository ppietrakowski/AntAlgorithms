// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTfindNearestFood.h"

EBTNodeResult::Type UBTTfindNearestFood::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{

    AAIController* AIOwner = OwnerComponent.GetAIOwner();
    
    UE_LOG(LogTemp, Warning, TEXT("Name %s"), *AIOwner->GetName());

    return EBTNodeResult::Succeeded;
}
