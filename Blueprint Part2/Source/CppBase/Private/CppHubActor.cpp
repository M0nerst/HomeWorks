// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHubActor.h"
#include "TimerManager.h"
#include "CppBaseActor.h"

// Sets default values
ACppHubActor::ACppHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppHubActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACppHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}










