// Fill out your copyright notice in the Description page of Project Settings.


#include "ZCCObjectMgr.h"

UObject* UZCCObjectMgr::FindObjectByClass(const TSubclassOf<UObject> ObjectClass) const
{
	UObject* FoundObject = nullptr;

	if (UClass* TargetClass = ObjectClass.Get())
	{
		for (UObject* Object : OwnedObjects)
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
