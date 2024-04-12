#pragma once

#include "CoreMinimal.h"
#include "GameCharacter.h"
#include "Pacman.generated.h"

UENUM()
enum PACMAN_STATE
{
	Normal		UMETA(DisplayName = "Normal"),
	SpeedUp		UMETA(DisplayName = "SpeedUp"),
	PoweredUp	UMETA(DisplayName = "PoweredUp"),
};

UCLASS()
class PACMAN3D_API APacman : public AGameCharacter
{
	GENERATED_BODY()

public:
	APacman();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float fPowerUpDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float fTimeSincePowerup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Lives;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsDead;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pacman Variables", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pacman Variables", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pacman Variables", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<PACMAN_STATE> PacmanState;

	void PowerUp(AActor* Pickup);


};
