// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HeightMapGeneratorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HEIGHTMAPTEST_API UHeightMapGeneratorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHeightMapGeneratorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void FindAllDependencies();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void CalcShaderParameters();

	UFUNCTION(BlueprintCallable)
		void UpdateShaderParameters();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor World2HeightmapOffsetAndScale;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float HeightMap2WorldZAdd;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float HeightMap2WorldZMul;


	UPROPERTY(BlueprintReadWrite)
		USceneCaptureComponent2D* CaptureComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialParameterCollection* MatParamsCollection;
};
