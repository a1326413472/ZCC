// Fill out your copyright notice in the Description page of Project Settings.


#include "Creation/ZCCCreationComponent.h"
#include <Creation/ZCCParamHandler.h>
#include "Creation/ZCCSpecieDataAsset.h"
#include <ZCCParamHandlerMgr.h>
#include <ZCCGameplayStatics.h>

// Sets default values for this component's properties
UZCCCreationComponent::UZCCCreationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UZCCCreationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UZCCCreationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UZCCSpecieDataAsset* UZCCCreationComponent::GetSpecieData()
{
	return CurrentSpecie;
}

UZCCParamHandler* UZCCCreationComponent::GetParamHandler(FName GroupKey, FName Key)
{
	//TODO
	if (UZCCSpecieDataAsset* SpecieData = GetSpecieData())
	{
		if (UZCCParamHandlerMgr* ParamHandlerMgr = UZCCGameplayStatics::GetParamHandlerMgr(this))
		{
			if (UZCCParamHandler* ParamHandler = ParamHandlerMgr->GetParamHandler(
				SpecieData->GroupParamHandler->GetParamHandlerClass(GroupKey, Key)))
			{
				return ParamHandler;
			}
		}
	}
	return nullptr;
}

void UZCCCreationComponent::InitEssentials()
{


}

void UZCCCreationComponent::LoadCreation(FZCCCharacterCreation InCharacterCreation)
{
	UE_LOG(LogTemp, Warning, TEXT("LoadCreation Exeture!!!"));
	// If First time
	if (!bWasFirstTimeLoad)
	{
		bWasFirstTimeLoad = true;
		InitEssentials();
		
	}
	Creation = InCharacterCreation;

}

void UZCCCreationComponent::NotifyIntParam(FName GroupKey, FZCCIntParam IntParam)
{
	// now notify change and handler
	// ����֪ͨ���ĺʹ������
	if (UZCCParamHandler* ParamHandler = GetParamHandler(GroupKey, IntParam.Key))
	{
		// TODO
		ParamHandler->OnReceiveInt(this, IntParam);
		OnIntParamChange.Broadcast(this, GroupKey, IntParam);
	}
}

void UZCCCreationComponent::ChangeIntParam_Implementation(FName GroupKey, FZCCIntParam IntParam)
{
	// If found
	// ����ҵ�
	if (FZCCGroupParam* GroupParam = Creation.CreationBase.GetGroupParamRef(GroupKey))
	{
		// IF already here, check if value changed else ignore
		// ����Ѿ���������ֵ�Ƿ�ı䣬�������
		const int32 LastIndex = GroupParam->IntParams.Find(IntParam);
		if (LastIndex > -1)
		{
			// not change detected has the value are identical
			// δ��⵽�ĸ���ֵ��ͬ
			if (GroupParam->IntParams.FindByKey(IntParam)->Value == IntParam.Value)
			{
				return;
			}
		}
		// IF already exist
		// ����Ѿ�����
		if (GroupParam->IntParams.AddUnique(IntParam) == LastIndex)
		{
			// Replace
			// �滻
			GroupParam->IntParams[LastIndex] = IntParam;
		}
		// now notify change and handler
		// ����֪ͨ���ĺʹ������
		NotifyIntParam(GroupKey, IntParam);
	}
}

