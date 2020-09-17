// Fill out your copyright notice in the Description page of Project Settings.


#include "HeightMapGeneratorComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Materials/MaterialParameterCollection.h"


// Sets default values for this component's properties
UHeightMapGeneratorComponent::UHeightMapGeneratorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHeightMapGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();

	CaptureComponent = GetOwner()->FindComponentByClass<USceneCaptureComponent2D>();

}


// Called every frame
void UHeightMapGeneratorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHeightMapGeneratorComponent::CalcShaderParameters()
{
	if (!CaptureComponent)
		return;

	if (!CaptureComponent->TextureTarget)
		return;


	float WorldAreaSize = CaptureComponent->OrthoWidth;
	float TextureSize = CaptureComponent->TextureTarget->GetSurfaceWidth();

	FVector HeightMapUVOrginWorldPos = CaptureComponent->GetComponentLocation() + FVector(WorldAreaSize * 0.5f, WorldAreaSize * -0.5f, 0.0f);
	float UVUnit = 1 / TextureSize;
	FVector4 Vec_World2HeightmapOffsetAndScale = FVector4(-HeightMapUVOrginWorldPos, TextureSize / WorldAreaSize * UVUnit);


	World2HeightmapOffsetAndScale = FLinearColor(Vec_World2HeightmapOffsetAndScale);


	HeightMap2WorldZAdd = CaptureComponent->GetComponentLocation().Z;
	HeightMap2WorldZMul = -1.0f;
}

void UHeightMapGeneratorComponent::UpdateShaderParameters()
{
	if (!MatParamsCollection)
		return;


// 	const FCollectionVectorParameter* Parameter = MatParamsCollection->GetVectorParameterByName(TEXT("OffsetAndScale"));
// 	if (Parameter)
// 	{
// 		Parameter =
// 
// 	}
}

