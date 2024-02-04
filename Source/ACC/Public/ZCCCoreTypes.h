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

/// <summary>
/// Struct : Int Param
/// </summary>
USTRUCT(BlueprintType)
struct ACC_API FZCCIntParam : public FZCCParam
{
	GENERATED_BODY()

	FZCCIntParam() : Value(0)
	{
	}
	FZCCIntParam(FName InKey) : FZCCParam(InKey)
	{
	}
	FZCCIntParam(FName InKey, FName InCustomInfo) : FZCCParam(InKey, InCustomInfo)
	{
	}
	FZCCIntParam(FName InKey, FName InCustomInfo, int32 InValue) : FZCCParam(InKey, InCustomInfo), Value(InValue)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	int32 Value;
};

USTRUCT(BlueprintType)
struct ACC_API FZCCGroupParam
{
	GENERATED_BODY()

	FZCCGroupParam() : Key()
	{
	}

	FZCCGroupParam(FName InIdentifier) : Key(InIdentifier)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	FName Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	TArray<FZCCIntParam> IntParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZCC")
	TArray<FName> Tags;

	bool operator!=(const FZCCGroupParam Other) const
	{
		return !Equals(Other);
	}

	bool operator==(const FZCCGroupParam Other) const
	{
		return Equals(Other);
	}

	bool Equals(const FZCCGroupParam Other) const
	{
		return (Key == Other.Key);
	}

	bool IsValid() const
	{
		return (!Key.IsNone());
	}

	FZCCIntParam GetIntParam(const FName InKey)
	{
		const int32 Index = IntParams.Find(FZCCIntParam(InKey));
		if (Index != INDEX_NONE)
		{
			return IntParams[Index];
		}
		return FZCCIntParam();
	}

	FZCCIntParam GetIntParamWithCI(const FName InKey, const FName InCustomInfo)
	{
		const int32 Index = IntParams.Find(FZCCIntParam(InKey, InCustomInfo));
		if (Index != INDEX_NONE)
		{
			return IntParams[Index];
		}
		return FZCCIntParam();
	}

};