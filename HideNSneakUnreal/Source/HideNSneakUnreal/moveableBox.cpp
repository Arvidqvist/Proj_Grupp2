// Fill out your copyright notice in the Description page of Project Settings.


#include "moveableBox.h"
#include "Math/Vector.h"
// Sets default values for this component's properties
UmoveableBox::UmoveableBox()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UmoveableBox::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = SelfActor->GetTransform().GetLocation();
	EndPosition = endpoint->GetTransform().GetLocation();
	movementvecktor = (EndPosition - StartPosition).GetSafeNormal() * MovementSpeed;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("wtf"));
	// ...
}


// Called every frame
void UmoveableBox::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	/*if(SelfActor->ActorGetDistanceToCollision() <)*/
	//SelfActor->OnActorHit

	if ((EndPosition - SelfActor->GetTransform().GetLocation()).Size() < 10) {
		SelfActor->SetActorLocation(SelfActor->GetTransform().GetLocation() + movementvecktor);
	}
	//else {
	//	if (TargetPosition == EndPosition) {
	//		TargetPosition = StartPosition;
	//	}
	//	else
	//	{
	//		TargetPosition = EndPosition;
	//	}
	//	GEngine->AddOnScreenDebugMessage(-1, 0.25f, FColor::Yellow, TEXT("k�rs denna?"));
	//}
	///*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("wtf"));*/
		//SelfActor->GetTransform();
	// ...
}

