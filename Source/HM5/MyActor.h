// MyActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HM5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();
	void Move();
	void Turn();
	void PrintLogLocation();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveDistance = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationAngle = 45.0f;
protected:
	virtual void BeginPlay() override;

private:

};
