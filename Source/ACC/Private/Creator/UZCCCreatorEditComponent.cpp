// Fill out your copyright notice in the Description page of Project Settings.


#include "Creator/UZCCCreatorEditComponent.h"

// Sets default values for this component's properties
UUZCCCreatorEditComponent::UUZCCCreatorEditComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UUZCCCreatorEditComponent::BeginPlay()
{
	// init
	Init();

	Super::BeginPlay();

	// ...
}

void UUZCCCreatorEditComponent::Init()
{
	// Add one default listener
	// 添加一个默认监听器
	Listener = NewObject<UZCCCreatorListener>(this);


	// Bind
	// 绑定
	Listener->OnIntParamChange.AddDynamic(this, &UUZCCCreatorEditComponent::NativeIntParamChange);
}

// Called every frame
void UUZCCCreatorEditComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUZCCCreatorEditComponent::NativeIntParamChange(UZCCCreationComponent* InCreationComponent, FName GroupKey, FZCCIntParam Param)
{
	if (IsValid(CreationComponent))
	{
		CreationComponent->ChangeIntParam(GroupKey, Param);
	}
}

void UUZCCCreatorEditComponent::SetCreationComponent(UZCCCreationComponent* InCreationComponent)
{
	// New
	CreationComponent = InCreationComponent;
	//TODO
	
}



