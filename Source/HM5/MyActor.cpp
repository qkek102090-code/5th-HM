// MyActor.cpp


#include "MyActor.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FVector ActorLocation = GetActorLocation();

	SetActorLocation(FVector(0, 50, 0));
	PrintLogLocation();
    for (int32 i = 0; i < 10; i++)
    {
        int32 RandomAction = FMath::RandRange(0, 1);

        if (RandomAction == 0) {
            Move();
        }
        else {
            Turn();
        }
    }
}

void AMyActor::Move()
{
    float RandomX = FMath::RandRange(-MoveDistance, MoveDistance);
    float RandomY = FMath::RandRange(-MoveDistance, MoveDistance);

    FVector NewLocation = GetActorLocation() + FVector(RandomX, RandomY, 0.0f);

    SetActorLocation(NewLocation);

    PrintLogLocation();
}

void AMyActor::Turn()
{
    FRotator NewRotation = GetActorRotation() + FRotator(0.0f, RotationAngle, 0.0f);
    SetActorRotation(NewRotation);

    PrintLogLocation();
}

void AMyActor::PrintLogLocation()
{
    FVector Loc = GetActorLocation();
    FString LogMsg = FString::Printf(TEXT("Location: X=%.2f, Y=%.2f, Z=%.2f"), Loc.X, Loc.Y, Loc.Z);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, LogMsg);
    }
}

