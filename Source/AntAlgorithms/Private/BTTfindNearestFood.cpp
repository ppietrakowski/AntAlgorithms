// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTfindNearestFood.h"
#include "Kismet/GameplayStatics.h"
#include "AntColonySimulation.h"
#include <BehaviorTree/BlackboardComponent.h>

EBTNodeResult::Type UBTTfindNearestFood::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
    UAntColonySimulation* Simulation = Cast<UAntColonySimulation>(UGameplayStatics::GetGameInstance(this));
    AAIController* AIOwner = OwnerComponent.GetAIOwner();
    
    TArray<AActor*> Actors;

    UGameplayStatics::GetAllActorsWithInterface(this, UAntFood::StaticClass(), Actors);

    if (Actors.IsEmpty())
    {
        return EBTNodeResult::Failed;
    }

    BestScore = 0.0f;
    BestMove = {};

    for (AActor* Actor : Actors)
    {
        IAntFood* Food = Cast<IAntFood>(Actor);
        UE_DEBUG_BREAK();

        FVector AntLocation = AIOwner->GetPawn()->GetActorLocation();
        FVector FoodLocation = Food->Execute_GetLocationInWorld(Actor);
            
        float PheromonePart = powf(Food->Execute_GetPheromoneStrength(Actor), Simulation->GetPheromoneStrength());
        float DistancePart = powf(1.0f / FVector::Distance(AntLocation, FoodLocation), Simulation->GetDistanceStrength());

        float Score = PheromonePart * DistancePart;

        if (Score > BestScore)
        {
            BestScore = Score;
            BestMove = FoodLocation;
        }
    }
    UBlackboardComponent* Blackboard = OwnerComponent.GetBlackboardComponent();

    Blackboard->SetValueAsVector(OutPositionKey.SelectedKeyName, BestMove);

    return EBTNodeResult::Succeeded;
}
