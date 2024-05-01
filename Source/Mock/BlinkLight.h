// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkLight.generated.h"
#include "Components/TimelineComponent.h"

UCLASS()
class MOCK_API ABlinkLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlinkLight();

	UPROPERTY(EditAnywhere)
		UCurveFloat* PointLightFloatCurve;

	UPROPERTY(EditAnywhere)
		UCurveLinearColor* PointLightColorCurve;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//TimelineComponent to animate the point light component.
	//訳）ポイントライトコンポーネントのアニメーション化
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UTimelineComponent* LightTimelineComp;

	//BoxComponent which will be used as our proximity overlap volume.
	//訳）当たり判定用のボックスコンポーネント（入ったらライトアニメージョンが始まる感じ）
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* LightOverlapVolume;

	UPROPERTY(EditAnuwhere, BlueprintReadWrite)
		class UPointLightComponent* PointLightComp;

	//Track used for Pointlight brightness
	//訳）ポイントライトの明るさ変更に使われるやつ
	FOnTimelineFloat UpdateBrightnessTrack;

	//Track used for Pointlight brightness
	//訳）ポイントライトの色変更に使われるやつ
	FOnTimelineFloat UpdateColorTrack;

	//Function to Update Light's brightness relative to UpdateBrightnessTrack
	//訳）「UpdateBrightnessTrack」を基準にライトの明るさを更新する関数
	UFUNCTION()
		void UpdateLightBringhtness(float BrightnessOutput);

	//Function to Update Light's color relative to UpdateColorTrack
	//訳）「UpdateColorTrack」を基準にライトの色を更新する関数
	UFUNCTION()
		void UpdateLightColor(FLinearColor ColorOutput);

	UPROPERTY(EditDefaultsOnly)
		float BrightnessMultiplier;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
