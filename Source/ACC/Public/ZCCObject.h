// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ZCCObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ACC_API UZCCObject : public UObject
{
	GENERATED_BODY()

public:
	/// <summary>
	/// @brief Accessor to get the ZCCSubsystem (Core of asset)
	/// </summary>
	UFUNCTION(BlueprintPure, Category="ZCC")
	class UZCCGameSubsystem* GetZCCSubsystem();
	
	/// <summary>
	/// @brief Accessor to get the ACCSubsystem (Core of asset)
	/// </summary>
	/// <returns></returns>
	virtual UWorld* GetWorld() const override;

};
