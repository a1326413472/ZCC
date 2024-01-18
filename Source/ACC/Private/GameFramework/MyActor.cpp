// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//¶¯Ì¬¼ÓÔØ½ÇÉ«
	UClass* MyTempCharacter = LoadClass<ACharacter>(this, TEXT("/Script/Engine.Blueprint'/Game/ZCC/Character/BP_ZCC_CharacterExample.BP_ZCC_CharacterExample_C'"));
	if (MyTempCharacter)
	{
		FVector const& Location = FVector(0, 0, 100);
		ACharacter* SpawnCharacter = GetWorld()->SpawnActor<ACharacter>(MyTempCharacter, Location, FRotator::ZeroRotator);
		if (SpawnCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("Load Character Success : %s"), *SpawnCharacter->GetName());
		}
	}

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

