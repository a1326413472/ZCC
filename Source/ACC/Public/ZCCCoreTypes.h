// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCCoreTypes.generated.h"

UENUM(BlueprintType)
enum class EZCCGender : uint8
{
	Male,
	Female,
	Other
};

UENUM(BlueprintType)
enum class EZCCMaturity : uint8
{
	Baby,
	Kid,
	Adult,
	Custom
};


USTRUCT(BlueprintType)
struct ACC_API FZCCParam : public FTableRowBase
{
	GENERATED_BODY()

	FZCCParam(FName InKey, FName InCustomInfo) : Key(InKey), CustomInfo(InCustomInfo)
	{
	}

	FZCCParam(FName InKey) : Key(InKey), CustomInfo(FName())
	{
	}

	FZCCParam() : Key(FName()), CustomInfo(FName())
	{
	}

	/**
	 * @brief Generally associated to the param handler key
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ACC")
	FName Key;

	/**
	 * @brief For additional info
	 * Example : Type = Morph, but need to know which morph target we want edit , so CustomInfo will be this info
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ACC")
	FName CustomInfo;

	bool operator!=(const FZCCParam Other) const
	{
		return !Equals(Other);
	}

	bool operator==(const FZCCParam Other) const
	{
		return Equals(Other);
	}

	bool Equals(const FZCCParam Other) const
	{
		return (Key == Other.Key && CustomInfo == Other.CustomInfo);
	}

	bool IsValid() const
	{
		return (!Key.IsNone());
	}
};