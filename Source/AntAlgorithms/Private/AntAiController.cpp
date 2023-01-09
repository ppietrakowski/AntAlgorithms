// Fill out your copyright notice in the Description page of Project Settings.


#include "AntAiController.h"

void AAntAiController::BeginPlay()
{
    Super::BeginPlay();
}

void AAntAiController::RunBTT()
{
    check(BehaviourTreeAsset != nullptr);
    RunBehaviorTree(BehaviourTreeAsset);
}
