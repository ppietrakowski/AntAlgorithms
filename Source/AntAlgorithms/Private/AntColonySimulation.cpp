// Fill out your copyright notice in the Description page of Project Settings.


#include "AntColonySimulation.h"

UAntColonySimulation::UAntColonySimulation():
    DistanceStrength(0.1f),
    PheromoneStrength(0.1f),
    EvaporationRate(0.1f),
    EvaporationTime(2.0f)
{
}

void UAntColonySimulation::SetDistanceStrength(float NewDistanceStrength)
{
    this->DistanceStrength = NewDistanceStrength;
}

void UAntColonySimulation::SetPheromoneStrength(float NewPheromoneStrength)
{
    this->PheromoneStrength = NewPheromoneStrength;
}

void UAntColonySimulation::SetEvaporationRate(float NewEvaporationRate)
{
    EvaporationRate = NewEvaporationRate;
}

void UAntColonySimulation::SetEvaporationTime(float NewEvaporationTime)
{
    EvaporationTime = NewEvaporationTime;
}
