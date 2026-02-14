// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingPlayerController.h"
#include "Engine/World.h"
#include "Engine.h"
#include "ComponentActor.h"
#include "TestActor.h"
#include "GameFramework/Actor.h"
#include "UObject/UObjectArray.h"
#include "Engine/Engine.h"


ATestingPlayerController::ATestingPlayerController()
{
    PrimaryActorTick.bCanEverTick = false;

    bShowMouseCursor = true;
    bEnableClickEvents = false;
    bEnableMouseOverEvents = false;

    // Sensible defaults for testing
    
    ActorCount = 1;
    ComponentsPerActor = 1;
}

void ATestingPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Do not possess a pawn
    SetPawn(nullptr);
}

void ATestingPlayerController::OnDelayCompleted()
{

    

    // Code to execute after the delay
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            5.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            TEXT("Timer Ended")
        );
    }

    FCsvProfiler::Get()->EndCapture();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            5.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            TEXT("CSV Profiler Completed.")
        );
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            25.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            FString::Printf(TEXT("CSV Profiler Completed.Actor Count = %d . Object Count = %d"), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum())
        );
    }

    UE_LOG(LogTemp, Log, TEXT("CSV Profiler Completed.Actor Count = %d . Object Count = %d"), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum());

    UpdateNumObjects.Broadcast(GUObjectArray.GetObjectArrayNum());
    UpdateNumActors.Broadcast(GetWorld()->GetActorCount());

    // Optional: clear the timer if it's a one-shot timer and you don't need it again
    GetWorldTimerManager().ClearTimer(DelayTimerHandle);

}

void ATestingPlayerController::RunActorOnlyScenario()
{

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    

    for (int32 i = 0; i < ActorCount; ++i)
    {
        World->SpawnActor<ATestActor>();
    }

    // Stabilize
    FPlatformProcess::Sleep(10.0f);


    FCsvProfiler::Get()->BeginCapture();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            25.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            FString::Printf(TEXT("CSV Profiler Started. Actor Count = %d. Object Count = %d."), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum())
        );
    }

    UE_LOG(LogTemp, Log, TEXT("CSV Profiler Started. Actor Count = %d. Object Count = %d."), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum());


    float DelayDuration = 120.0f; // 3 seconds
    bool bLooping = false; // Set to true if you want the timer to repeat

    GetWorld()->GetTimerManager().SetTimer(
        DelayTimerHandle,                 // The Timer Handle to use
        this,                             // The object to call the function on
        &ATestingPlayerController::OnDelayCompleted,      // The function to call
        DelayDuration,                    // The duration of the delay
        bLooping                          // Whether the timer should loop
    );



    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            5.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            TEXT("Timer Started.")
        );
    }

}

void ATestingPlayerController::RunActorWithComponentsScenario()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    

    for (int32 i = 0; i < ActorCountScaled; ++i)
    {
        AComponentActor* Actor =
            World->SpawnActor<AComponentActor>();

        if (Actor)
        {
            Actor->NumComponents = ComponentsPerActor;
            Actor->GenerateComponents();

            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(
                    -1,            // Key (-1 = new message each time)
                    5.0f,          // Time on screen (seconds)
                    FColor::Green, // Text color
                    TEXT("Actor Spawned")
                );
            }
        }
    }

    // Stabilize
    FPlatformProcess::Sleep(10.0f);

    FCsvProfiler::Get()->BeginCapture();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            25.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            FString::Printf(TEXT("CSV Profiler Started. Actor Count = %d. Object Count = %d."), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum())
        );
    }

    UE_LOG(LogTemp, Log, TEXT("CSV Profiler Started. Actor Count = %d. Object Count = %d."), GetWorld()->GetActorCount(), GUObjectArray.GetObjectArrayNum());


    float DelayDuration = 120.0f; // 3 seconds
    bool bLooping = false; // Set to true if you want the timer to repeat

    GetWorld()->GetTimerManager().SetTimer(
        DelayTimerHandle,                 // The Timer Handle to use
        this,                             // The object to call the function on
        &ATestingPlayerController::OnDelayCompleted,      // The function to call
        DelayDuration,                    // The duration of the delay
        bLooping                          // Whether the timer should loop
    );

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,            // Key (-1 = new message each time)
            5.0f,          // Time on screen (seconds)
            FColor::Green, // Text color
            TEXT("Timer Started.")
        );
    }
}



