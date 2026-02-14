// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentActor.generated.h"

UCLASS()
class UOBJECT_VS_ACTOR_API AComponentActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponentActor();

	//Number of components to create forthis actor
	UPROPERTY(EditAnywhere, Category = "Benchmark")
	int32 NumComponents;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateComponents();

private:

	TArray<USceneComponent*> Components;
	
};
