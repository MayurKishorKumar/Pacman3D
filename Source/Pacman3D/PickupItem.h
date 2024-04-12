#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PickupItem.generated.h"

UENUM()
enum FRUIT_TYPE
{
	Cherry		UMETA(DisplayName = "Cherry"),
	Pear		UMETA(DisplayName = "Pear"),
	Orange		UMETA(DisplayName = "Orange"),
};

UCLASS()
class PACMAN3D_API APickupItem : public APawn
{
	GENERATED_BODY()

public:
	APickupItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Pickup Variables")
	TEnumAsByte<FRUIT_TYPE> FruitType;

	UPROPERTY(EditAnywhere, Category = "Pickup Variables")
	float fDuration;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Variables", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Variables", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup Variables", meta = (AllowPrivateAccess = "true"))
	float fPickupRotationSpeed = 10.f;

};
