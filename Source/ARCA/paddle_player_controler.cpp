// Fill out your copyright notice in the Description page of Project Settings.


#include "paddle_player_controler.h"


#include"Kismet/GameplayStatics.h"
#include"Camera/CameraActor.h"

#include"paddle.h"
#include"Ball.h"


Apaddle_player_controler::Apaddle_player_controler()
{


}

void Apaddle_player_controler::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();
	

}
void Apaddle_player_controler::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);
	// hacemos las referencias (buscamos en blueprint)
	InputComponent->BindAxis("MoveHorizontal", this, &Apaddle_player_controler::MoveHorizontal);
	// solo para la bola 
	InputComponent->BindAction("Launch", IE_Pressed, this, &Apaddle_player_controler::Launch);

	
}

void Apaddle_player_controler::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<Apaddle>(GetPawn());
	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}

}

void Apaddle_player_controler::Launch()
{
	MyBall->Launch();
}

void Apaddle_player_controler::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;
	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);
	}
}
