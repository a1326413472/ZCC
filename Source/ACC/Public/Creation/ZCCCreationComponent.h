// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <ZCCCreationTypes.h>
#include "ZCCCreationComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACC_API UZCCCreationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UZCCCreationComponent();

	/// <summary>
	/// @brief The current specie (the root of all creation data parameters)
	/// @摘要 当前的物种(所有创建数据参数的根)
	/// </summary>
	UPROPERTY(BlueprintReadOnly, Category = "ZCC|DataAsset")
	class UZCCSpecieDataAsset* CurrentSpecie;

	/// <summary>
	/// @brief The character creation data
	/// </summary>
	UPROPERTY(BlueprintReadWrite, Category="ZCC|Data")
	FZCCCharacterCreation Creation;


	/// <summary>
	/// @brief Used in runtime to avoid reload some data for performance
	/// </summary>
	bool bWasFirstTimeLoad = false;





protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "ZCC|Getter")
	UZCCSpecieDataAsset* GetSpecieData();




	UFUNCTION(BlueprintPure, Category = "ZCC|Getter")
	class UZCCParamHandler* GetParamHandler(FName GroupKey, FName Key);




	/// <summary>
	/// @brief Used for init all sub object and default utilities (not called in begin play cause replication)
	/// @摘要 用于初始化所有子对象和默认实用程序(未在begin play中调用引起同步)
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "ZCC|Creation")
	void InitEssentials();

	UFUNCTION(BlueprintCallable, Category="ZCC|Creation")
	void LoadCreation(FZCCCharacterCreation InCharacterCreation);


	/// <summary>
	/// @brief Attempt to edit Int Param and call the param handler within
	/// @摘要 尝试编辑Int参数并调用参数处理程序
	/// </summary>
	/// <param name="GroupKey">Associated Group(相关的组)</param>
	/// <param name="IntParam">Value(值)</param>
	UFUNCTION(BlueprintCallable, Category="ZCC|Params")
	void NotifyIntParam(FName GroupKey, FZCCIntParam IntParam);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ZCC|Params")
	void ChangeIntParam(FName GroupKey, FZCCIntParam IntParam);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "ZCC|EventDispatchers")
	FACCIntParamChangeSignature OnIntParamChange;

};
