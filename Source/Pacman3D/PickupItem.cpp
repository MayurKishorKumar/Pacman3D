#include "PickupItem.h"
#include <Components/CapsuleComponent.h>

APickupItem::APickupItem()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Pickup Capsule"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Static Mesh"));

	RootComponent = CapsuleComp;
	Mesh->SetupAttachment(CapsuleComp);
	fDuration = 0.f;
}

void APickupItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, fPickupRotationSpeed, 0.f));

}

void APickupItem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

