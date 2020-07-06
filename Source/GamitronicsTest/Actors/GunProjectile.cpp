
#include "GunProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "CharEnemy.h"

AGunProjectile::AGunProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));

	RootComponent = Mesh;
	ProjectileComponent->InitialSpeed = 3000.0f;
	ProjectileComponent->MaxSpeed = 3000.0f;
	ProjectileComponent->bRotationFollowsVelocity = true;
	ProjectileComponent->ProjectileGravityScale = 0.0f;
	ProjectileComponent->bConstrainToPlane = true;
	ProjectileComponent->bShouldBounce = true;
	ProjectileComponent->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));


}

void AGunProjectile::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentHit.AddDynamic(this, &AGunProjectile::OnHit);

}

void AGunProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGunProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL), (OtherActor != GetOwner()))
	{
		if (Cast<ACharEnemy>(OtherActor))
		{
			UGameplayStatics::ApplyDamage(OtherActor, 20,GetInstigatorController(), this, UDamageType::StaticClass());
			Destroy();
		}
		else
		{
			
		}
		//if(Cast<EnemyActor)
	}
	
}

