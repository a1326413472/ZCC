// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ZCCGameData.h"
#include "ZCCSettings.generated.h"

/**
 * 
 */
UCLASS(config=Game, defaultconfig)
class ACC_API UZCCSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UZCCSettings(const FObjectInitializer& Initializer);

#if  WITH_EDITOR
	virtual FText GetSectionText() const override;
#endif //  WITH_EDITOR

	TSoftClassPtr<UZCCGameData> GetGameDataClass() const { return GameDataClass; }

private:

	/// <summary>
	/// @brief ACC Root Configuration
	/// </summary>
	UPROPERTY(Config, EditAnywhere, Category="Game Config")
	TSoftClassPtr<UZCCGameData> GameDataClass;
};
