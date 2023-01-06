// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"



//void AEnemyPawn::Hunt()
//{
//
//	State = EEnemyState::Default;
//
//	StateChangedEvent.Broadcast(State);
//
//}
//
//void AEnemyPawn::Idle()
//{
//
//
//	State = EEnemyState::Idle;
//
//	StateChangedEvent.Broadcast(State);
//}
//
//

AEnemyPawn::AEnemyPawn()
{

	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyPawn::BeginPlay()

{
	Super::BeginPlay();
}

void AEnemyPawn::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}

void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
