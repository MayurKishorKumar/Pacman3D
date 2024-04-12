#include "GameCharacter.h"
#include <Components/CapsuleComponent.h>


AGameCharacter::AGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("GameCharacter Capsule"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GameCharacter Mesh"));

	RootComponent = CapsuleComp;
	Mesh->SetupAttachment(CapsuleComp);

}

void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bTurnRight)
		TurnRightLoop(DeltaTime);
	if (bTurnLeft)
		TurnLeftLoop(DeltaTime);

}

void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameCharacter::MoveForward(float DeltaTime)
{
	FVector DeltaLocation(0.f);

	DeltaLocation.X = DeltaTime * fSpeed;
	AddActorLocalOffset(DeltaLocation, true);
}

void AGameCharacter::TurnRight()
{
	if (bTurnRight || bTurnLeft)
		return;
	bTurnRight = true;
	TargetRotation.Yaw += 90.f;

	UE_LOG(LogTemp, Warning, TEXT("Turning Right"));
}

void AGameCharacter::TurnLeft()
{
	if (bTurnLeft || bTurnRight)
		return;

	bTurnLeft = true;
	TargetRotation.Yaw -= 90.f;

	UE_LOG(LogTemp, Warning, TEXT("Turning Left"));
}

void AGameCharacter::TurnRightLoop(float DeltaTime)
{
	if (ceil(GetActorRotation().Yaw) < TargetRotation.Yaw)
	{
		SetActorRotation(FMath::RInterpConstantTo(GetActorRotation(), TargetRotation, DeltaTime * fDeltaTimeRotationConstant, fRotationSpeed));
		if (GetActorRotation().Yaw < 0 && TargetRotation.Yaw >= 180.f)
			TargetRotation.Yaw *= -1;
	}
	else
	{
		bTurnRight = false;
	}
}

void AGameCharacter::TurnLeftLoop(float DeltaTime)
{
	if (abs(TargetRotation.Yaw - GetActorRotation().Yaw) > 1.f)
	{
		SetActorRotation(FMath::RInterpConstantTo(GetActorRotation(), TargetRotation, DeltaTime * fDeltaTimeRotationConstant, fRotationSpeed));
		if (GetActorRotation().Yaw >= 0 && TargetRotation.Yaw <= -180.f)
			TargetRotation.Yaw += 360.f;
	}
	else
	{
		bTurnLeft = false;
	}
}

