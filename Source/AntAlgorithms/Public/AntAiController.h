// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <BehaviorTree/BlackboardComponent.h>
#include "AntAiController.generated.h"

/**
 *
 */
UCLASS()
class ANTALGORITHMS_API AAntAiController : public AAIController
{
    GENERATED_BODY()

public:

    void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    FORCEINLINE void SetBehaviourTreeAsset(UBehaviorTree* BehaviourTree)
    {
        this->BehaviourTreeAsset = BehaviourTree;
    }

    UFUNCTION(BlueprintCallable)
    void RunBTT();
private:
    UBehaviorTree* BehaviourTreeAsset{ nullptr };
};
