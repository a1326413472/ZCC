// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <ZCCDAOBase.h>
#include "ZCCGameplayStatics.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCGameplayStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "ACC|Object", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "DAOClass"))
	static UZCCDAOBase* GetDAOByClass(const UObject* WorldContextObject, TSubclassOf<UZCCDAOBase> DAOClass);

	/// <summary>
	/// Templated version of GetDAOByClass that handles casting for you.
	/// </summary>
	template <class T>
	static T* GetDAOByClass(const UObject* WorldContextObject)
	{
		return (T*)GetDAOByClass(WorldContextObject, T::StaticClass());
	}
	
};
