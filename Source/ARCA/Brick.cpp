// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include"Ball.h"


//libreria par el sonido
//#include "Sound/SoundCue.h"


// Sets default values
ABrick::ABrick()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));

	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_Collision;


}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);

	

	

}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//insertar sonido al chocar con la pelota
//void ABrick::Teletransporte(AActor* Actor)
//{
//
//	USceneComponent* TargetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));
//
//	UGameplayStatics::PlaySound2D(this, sonido_teletransporteB);
//
//	Actor->SetActorLocation(TargetSpawn->GetComponentLocation());
//}



void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappeComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType,
	bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);
		
		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 3.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		
		
		
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 1.1f, false);
DestroyBrick();
GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red,TEXT("un ladrillo destruido"));
		/*if (nuevo == 3) {
		
		}*/
		
	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}
