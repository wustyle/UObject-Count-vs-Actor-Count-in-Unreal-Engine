// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestingPlayerController.generated.h"

/**
 * 
 */
 // Declare a Blueprint-friendly multicast delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FUpdateNumActors,
    int32, Value
);

// Declare a Blueprint-friendly multicast delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FUpdateNumObjects,
    int32, Value
);

class AComponentActor;



UCLASS()
class UOBJECT_VS_ACTOR_API ATestingPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
    ATestingPlayerController();

    /** Called by UI to start a benchmark run */
    UFUNCTION(BlueprintCallable, Category = "Benchmark")
    void RunActorOnlyScenario();

    /** Called by UI to start a benchmark run */
    UFUNCTION(BlueprintCallable, Category = "Benchmark")
    void RunActorWithComponentsScenario();

    UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
    int32 ActorCount;

    UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
    int32 ActorCountScaled;

    UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
    int32 ComponentsPerActor;

    // Exposed to Blueprints so they can bind to it
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FUpdateNumActors UpdateNumActors;

    // Exposed to Blueprints so they can bind to it
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FUpdateNumObjects UpdateNumObjects;

protected:
    virtual void BeginPlay() override;


private:

    void OnDelayCompleted();
    
    FTimerHandle DelayTimerHandle;
};
