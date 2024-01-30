// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ZCCCoreLibraryStatic.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCCoreLibraryStatic : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	template <class T>
	static bool GetDataTableRow(const UDataTable* InDataTable, FName Identifier, T& OutData)
	{
		// name not none
		if (!Identifier.IsNone())
		{
			const T* Item = InDataTable->FindRow<T>(Identifier, "Get Datatable Row Data");
			if (Item != nullptr)
			{
				OutData = *Item;
				return true;
			}
			// Not valid
			return false;
		}
		return false;
	}


};
