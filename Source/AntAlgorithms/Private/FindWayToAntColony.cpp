// Fill out your copyright notice in the Description page of Project Settings.


#include "FindWayToAntColony.h"
#include "AntColony.h"
#include "Kismet/GameplayStatics.h"
#include "AntColonySimulation.h"
#include <BehaviorTree/BlackboardComponent.h>

EBTNodeResult::Type UFindWayToAntColony::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
    TArray<AActor*> Actors;

    UGameplayStatics::GetAllActorsWithInterface(this, UAntColony::StaticClass(), Actors);

    if (Actors.IsEmpty())
    {
        return EBTNodeResult::Failed;
    }

    UBlackboardComponent* Blackboard = OwnerComponent.GetBlackboardComponent();

    Blackboard->SetValueAsVector(OutPositionKey.SelectedKeyName, Actors[0]->GetActorLocation());

    return EBTNodeResult::Succeeded;
}
