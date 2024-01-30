// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ZCCGameData.h"
#include "ZCCObjectMgr.h"
#include "ZCCGameSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ACC_API UZCCGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

protected:

	UPROPERTY(BlueprintReadOnly, Category="ZCC|Game")
	UZCCGameData* GameData;
	
	UPROPERTY(BlueprintReadOnly, Category="ZCC|Game")
	TSet<UZCCObjectMgr*> OwnedManagers;


public:

	UFUNCTION(BlueprintPure, Category = "ZCC|Game")
	UZCCGameData* GetGameData();

	virtual UZCCObjectMgr* FindManagerByClass(const TSubclassOf<UZCCObjectMgr> ManagerClass) const;

	UFUNCTION(BlueprintCallable, Category = "ZCC|Object", meta = (DeterminesOutputType = "ManagerClass"))
	UZCCObjectMgr* AddManagerByClass(TSubclassOf<UZCCObjectMgr> ManagerClass);

	UFUNCTION(BlueprintPure, Category = "ZCC|Object", meta = (DeterminesOutputType = "ManagerClass"))
	UZCCObjectMgr* GetManagerByClass(TSubclassOf<UZCCObjectMgr> ManagerClass);


	/** Templatized version of AddObjectByClass that handles casting for you */
	template<class T>
	T* AddManagerByClass()
	{
		static_assert(TPointerIsConvertibleFromTo<T, const UZCCObjectMgr>::Value, "'T' template parameter to AddManagerByClass must be derived from UACCObjectMgr");

		return (T*)AddManagerByClass(T::StaticClass());
	}

	/** Templatized version of GetObjectByClass that handles casting for you */
	template<class T>
	T* GetManagerByClass()
	{
		static_assert(TPointerIsConvertibleFromTo<T, const UObject>::Value, "'T' template parameter to GetObjectByClass must be derived from UObject");

		return (T*)GetManagerByClass(T::StaticClass());
	}
};
