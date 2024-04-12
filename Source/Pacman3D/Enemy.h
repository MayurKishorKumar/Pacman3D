#pragma once

#include "CoreMinimal.h"
#include "GameCharacter.h"
#include "Enemy.generated.h"

UCLASS()
class PACMAN3D_API AEnemy : public AGameCharacter
{
	GENERATED_BODY()
	
private:
	AEnemy();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
