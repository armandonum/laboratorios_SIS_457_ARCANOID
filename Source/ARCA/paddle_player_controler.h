// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "paddle_player_controler.generated.h"

class ABall;
/**
 * 
 */
UCLASS()
class ARCA_API Apaddle_player_controler : public APlayerController
{
	GENERATED_BODY()

		Apaddle_player_controler();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);

	// referencias a ball
	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;
	ABall* MyBall;

	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

public:

	void SpawnNewBall();
};
