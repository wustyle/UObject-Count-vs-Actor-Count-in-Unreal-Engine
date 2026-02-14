// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentActor.h"
#include "TestSceneComponent.h"
#include "Engine.h"


// Sets default values
AComponentActor::AComponentActor()
{
	// Creates our root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	

}

// Called when the game starts or when spawned
void AComponentActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AComponentActor::GenerateComponents()
{
	for (int32 i = 0; i < NumComponents; ++i)
	{
		UTestSceneComponent* Component = NewObject<UTestSceneComponent>(this);

		Component->RegisterComponent();
		Component->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

		Components.Add(Component);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,            // Key (-1 = new message each time)
				5.0f,          // Time on screen (seconds)
				FColor::Green, // Text color
				TEXT("Component created.")
			);
		}
	}
}

