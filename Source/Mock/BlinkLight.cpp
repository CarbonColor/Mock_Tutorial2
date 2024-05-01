// Fill out your copyright notice in the Description page of Project Settings.


#include "BlinkLight.h"
#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"

// Sets default values
ABlinkLight::ABlinkLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our Default Components
	PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
	LightTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("LightTimelineComp"));
	LightOverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("LIghtOverlapVolume"));

	//Setup our Attachments
	RootComponent = LightOverlapVolume;
	PointLightComp->AttachToComponent(LightOverlapVolume, FAttachmentTransformRules::KeepRelativeTransform);

	//Initialize Brightness Multiplier
	BrightnessMultiplier = 20.0f;

}

void ABlinkLight::UpdateLightBringhtness(float BrightnessOutput)
{
	PointLightComp->SetLightBrightness(BrightnessOutput * 20.0f);
}

void ABlinkLight::UpdateLightColor(FLinearColor ColorOutput)
{
	PointLightComp->SetLightColor(ColorOutput);
}


// BeginPlay() Ç∆ Tick() 
//--------------------------------------------------------------------------
// Called when the game starts or when spawned
void ABlinkLight::BeginPlay()
{
	Super::BeginPlay();

	//Binding our float and color track to their respective funcions
	//ñÛÅj
	
}

// Called every frame
void ABlinkLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//--------------------------------------------------------------------------
