// Fill out your copyright notice in the Description page of Project Settings.


#include "Creation/ZCCGPHDataAsset.h"

TSubclassOf<UZCCParamHandler> UZCCParamHandlerDataAsset::GetParamHandlerClass(FName Key)
{
	for (auto ParamHandlerSetting: HandlerSettings)
	{
		if (ParamHandlerSetting.Key == Key)
		{
			return ParamHandlerSetting.HandlerClass;
		}
	}
	return UZCCParamHandler::StaticClass();
}

UZCCParamHandlerDataAsset* UZCCGroupParamHandlerDataAsset::GetGroupParamHandlerDataAsset(FName Key)
{
	if (GroupParamDataAssets.Contains(Key))
	{
		return GroupParamDataAssets.FindChecked(Key);
	}
	return nullptr;
}

TSubclassOf<UZCCParamHandler> UZCCGroupParamHandlerDataAsset::GetParamHandlerClass(FName GroupKey, FName Key)
{
	if (UZCCParamHandlerDataAsset* ParamHandlerDataAsset = GetGroupParamHandlerDataAsset(GroupKey))
	{
		return ParamHandlerDataAsset->GetParamHandlerClass(Key);
	}
	return UZCCParamHandler::StaticClass();
}


