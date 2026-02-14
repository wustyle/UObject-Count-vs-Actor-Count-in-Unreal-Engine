// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ControlWidget.generated.h"

/**
 * 
 */
class ATestingPlayerController;

UCLASS()
class UOBJECT_VS_ACTOR_API UControlWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** Called by UI to start a benchmark run */
	UFUNCTION(BlueprintCallable, Category = "Benchmark")
	void RunActorOnlyScenario();

	/** Called by UI to start a benchmark run */
	UFUNCTION(BlueprintCallable, Category = "Benchmark")
	void RunActorWithComponentsScenario();

	/** Called by UI to start a benchmark run */
	UFUNCTION(BlueprintCallable, Category = "Benchmark")
	void GarbageCleanup();

	UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
	int32 ActorCount;

	UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
	int32 ActorCountScaled;

	UPROPERTY(BlueprintReadWrite, Category = "Benchmark")
	int32 ComponentsPerActor;

	//UPROPERTY(EditAnywhere, Category = "Benchmark")
	ATestingPlayerController* Controller;
	
};
