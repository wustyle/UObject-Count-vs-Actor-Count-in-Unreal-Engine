// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlWidget.h"
#include "TestingPlayerController.h"
#include "UObject/GarbageCollection.h"
#include "Engine.h"



void UControlWidget::RunActorOnlyScenario()
{
	Controller = Cast<ATestingPlayerController>(GetOwningPlayer());

	Controller->ActorCount = ActorCount;

	Controller->RunActorOnlyScenario();
}

void UControlWidget::RunActorWithComponentsScenario()
{
	Controller = Cast<ATestingPlayerController>(GetOwningPlayer());

	Controller->ActorCountScaled = ActorCountScaled;

	Controller->ComponentsPerActor = ComponentsPerActor;

	Controller->RunActorWithComponentsScenario();

}

void UControlWidget::GarbageCleanup()
{
	
	// Stabilize
	FPlatformProcess::Sleep(1.0f);

	// Force GC before measurement
	CollectGarbage(RF_NoFlags);

	// Notify Garbage Cleaned


	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,            // Key (-1 = new message each time)
			5.0f,          // Time on screen (seconds)
			FColor::Green, // Text color
			TEXT("Garbage Cleaned")
		);
	}
}

