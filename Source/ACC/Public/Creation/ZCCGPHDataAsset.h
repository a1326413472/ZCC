// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ZCCParamHandler.h"
#include "ZCCGPHDataAsset.generated.h"

/// <summary>
/// Struct : Param handler Setting
/// </summary>
USTRUCT(BlueprintType)
struct FZCCParamHandlerSetting
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZCC|Param Handler")
	FName Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC|Param Handler")
	TSubclassOf<UZCCParamHandler> HandlerClass;
};

/**
 * 
 */
UCLASS()
class ACC_API UZCCParamHandlerDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZCC|Param Handler")
	TArray<FZCCParamHandlerSetting> HandlerSettings;

	UFUNCTION(BlueprintPure, Category = "ZCC|Param Handler")
	TSubclassOf<UZCCParamHandler> GetParamHandlerClass(FName Key);
};

/**
 *
 */
UCLASS()
class ACC_API UZCCGroupParamHandlerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ACC|Param Handler")
	TMap<FName, UZCCParamHandlerDataAsset*> GroupParamDataAssets;

	UFUNCTION(BlueprintPure, Category = "ZCC|Param Handler")
	UZCCParamHandlerDataAsset* GetGroupParamHandlerDataAsset(FName Key);

	UFUNCTION(BlueprintPure, Category = "ZCC|Param Handler")
	TSubclassOf<UZCCParamHandler> GetParamHandlerClass(FName GroupKey, FName Key);
};
