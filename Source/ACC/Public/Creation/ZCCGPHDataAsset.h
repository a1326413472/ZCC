// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
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

};
