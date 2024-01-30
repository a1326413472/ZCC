// Fill out your copyright notice in the Description page of Project Settings.


#include "Creation/ZCCCreationComponent.h"

// Sets default values for this component's properties
UZCCCreationComponent::UZCCCreationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UZCCCreationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UZCCCreationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UZCCCreationComponent::InitEssentials()
{


}

void UZCCCreationComponent::LoadCreation(FZCCCharacterCreation InCharacterCreation)
{
	UE_LOG(LogTemp, Warning, TEXT("LoadCreation Exeture!!!"));
	// If First time
	if (!bWasFirstTimeLoad)
	{
		bWasFirstTimeLoad = true;
		InitEssentials();
		
	}
	Creation = InCharacterCreation;

}

