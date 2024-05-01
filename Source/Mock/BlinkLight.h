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
	//��j�|�C���g���C�g�R���|�[�l���g�̃A�j���[�V������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UTimelineComponent* LightTimelineComp;

	//BoxComponent which will be used as our proximity overlap volume.
	//��j�����蔻��p�̃{�b�N�X�R���|�[�l���g�i�������烉�C�g�A�j���[�W�������n�܂銴���j
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* LightOverlapVolume;

	UPROPERTY(EditAnuwhere, BlueprintReadWrite)
		class UPointLightComponent* PointLightComp;

	//Track used for Pointlight brightness
	//��j�|�C���g���C�g�̖��邳�ύX�Ɏg������
	FOnTimelineFloat UpdateBrightnessTrack;

	//Track used for Pointlight brightness
	//��j�|�C���g���C�g�̐F�ύX�Ɏg������
	FOnTimelineFloat UpdateColorTrack;

	//Function to Update Light's brightness relative to UpdateBrightnessTrack
	//��j�uUpdateBrightnessTrack�v����Ƀ��C�g�̖��邳���X�V����֐�
	UFUNCTION()
		void UpdateLightBringhtness(float BrightnessOutput);

	//Function to Update Light's color relative to UpdateColorTrack
	//��j�uUpdateColorTrack�v����Ƀ��C�g�̐F���X�V����֐�
	UFUNCTION()
		void UpdateLightColor(FLinearColor ColorOutput);

	UPROPERTY(EditDefaultsOnly)
		float BrightnessMultiplier;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
