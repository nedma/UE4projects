// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActorComponent.h"
#include "Templates/SharedPointerTesting.inl"
#include "MyTest.h"


// Sets default values for this component's properties
UMyTestActorComponent::UMyTestActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTestActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTestActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UMyTestActorComponent::Test()
{

	//SharedPointerTesting::TestSharedPointer<ESPMode::Fast>();

	LRValueTest();
}

