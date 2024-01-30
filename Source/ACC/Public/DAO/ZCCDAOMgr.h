// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZCCObjectMgr.h"
#include "ZCCDAOBase.h"
#include "ZCCDAOMgr.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCDAOMgr : public UZCCObjectMgr
{
	GENERATED_BODY()

public:
	virtual UObject* AddObjectByClass_Implementation(TSubclassOf<UObject> ObjectClass) override;

	UFUNCTION(BlueprintPure, Category = "ACC|Object", meta = (DeterminesOutputType = "DAOClass"))
	UZCCDAOBase* GetDAOByClass(TSubclassOf<UZCCDAOBase> DAOClass);

	//template <class T>
	//T* GetDAOByClass()
	//{
	//	static_assert(TPointerIsConvertibleFromTo<T, const UACCDAOBase>::Value,
	//		"'T' template parameter to GetDAOByClass must be derived from UACCDAOBase");

	//	return (T*)GetDAOByClass(T::StaticClass());
	//}

};
