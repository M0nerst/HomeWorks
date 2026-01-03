// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
    void SinMovement();

	UPROPERTY(EditInstanceOnly)
    float Amplitude = 3.0;

    UPROPERTY(EditInstanceOnly)
    float Frequency = 2.0;

    UPROPERTY(VisibleAnywhere)
    FVector InitialLocation;

	UPROPERTY(VisibleAnywhere)
	FString PlayerName = this-> GetActorNameOrLabel();

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditDefaultsOnly)
	float CurrengHealt = 57.3;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	void ShowActorInformation();
};
