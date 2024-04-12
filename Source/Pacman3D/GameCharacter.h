#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameCharacter.generated.h"

UCLASS()
class PACMAN3D_API AGameCharacter : public APawn
{
	GENERATED_BODY()

public:
	AGameCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector FV_StartLocation;

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Character Variables", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Character Variables", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Character Variables", meta = (AllowPrivateAccess = "true"))
	float fSpeed = 200.f;

	void MoveForward(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Character Variables", meta = (AllowPrivateAccess = "true"))
	float fDeltaTimeRotationConstant = 80.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Character Variables", meta = (AllowPrivateAccess = "true"))
	float fRotationSpeed = 10.f;

	void TurnRight();
	void TurnLeft();

	void TurnRightLoop(float DeltaTime);
	void TurnLeftLoop(float DeltaTime);

	bool bTurnRight = false;
	bool bTurnLeft = false;

	FRotator TargetRotation;
};
