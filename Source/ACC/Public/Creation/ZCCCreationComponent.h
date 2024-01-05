// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <ZCCCreationTypes.h>
#include "ZCCCreationComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACC_API UZCCCreationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZCCCreationComponent();

	/// <summary>
	/// @brief The character creation data
	/// </summary>
	UPROPERTY(BlueprintReadWrite, Category="ZCC|Data")
	FZCCCharacterCreation Creation;


	/// <summary>
	/// @brief Used in runtime to avoid reload some data for performance
	/// </summary>
	bool bWasFirstTimeLoad = false;





protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="ZCC|Creation")
	void LoadCreation(FZCCCharacterCreation InCharacterCreation);
};
