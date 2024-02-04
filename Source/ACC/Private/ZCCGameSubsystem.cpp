// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCGameSubsystem.h"

#include "ZCCSettings.h"

void UZCCGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Get setting of plugin
	const UZCCSettings* Settings = GetDefault<UZCCSettings>();

	// Instance ACC Game Data from Given setting
	GameData = NewObject<UZCCGameData>(this, Settings->GetGameDataClass().LoadSynchronous());

}

UZCCGameData* UZCCGameSubsystem::GetGameData()
{
	return GameData;
}

UZCCParamHandlerMgr* UZCCGameSubsystem::GetParamHandlerMgr()
{
	return ParamHandlerMgr;
}

UZCCObjectMgr* UZCCGameSubsystem::FindManagerByClass(const TSubclassOf<UZCCObjectMgr> ManagerClass) const
{
	UZCCObjectMgr* FoundObject = nullptr;

	if (UClass* TargetClass = ManagerClass.Get())
	{
		for (UZCCObjectMgr* Object : OwnedManagers)
		{
			if (Object && Object->IsA(TargetClass))
			{
				FoundObject = Object;
				break;
			}
		}
	}

	return FoundObject;
}

UZCCObjectMgr* UZCCGameSubsystem::AddManagerByClass(TSubclassOf<UZCCObjectMgr> ManagerClass)
{
	UZCCObjectMgr* Object = NewObject<UZCCObjectMgr>(this, ManagerClass);

	OwnedManagers.Add(Object);

	return Object;
}

UZCCObjectMgr* UZCCGameSubsystem::GetManagerByClass(TSubclassOf<UZCCObjectMgr> ManagetClass)
{
	UZCCObjectMgr* Object = FindManagerByClass(ManagetClass);
	if (IsValid(Object))
	{
		return Object;
	}
	return AddManagerByClass(ManagetClass);
}
