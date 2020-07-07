
#include "GunProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Char_Game.h"
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
	Bounce = 0;

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
			
			

			if (Cast<AChar_Game>(GetOwner()))
			{
				UGameplayStatics::ApplyDamage(OtherActor, Cast<AChar_Game>(GetOwner())->AttackPoint, GetInstigatorController(), this, UDamageType::StaticClass());
				Cast<AChar_Game>(GetOwner())->AddHPonHit(1);
			}
			else
				UGameplayStatics::ApplyDamage(OtherActor, 20, GetInstigatorController(), this, UDamageType::StaticClass());

			Destroy();
		}
		else if (Cast<AGunProjectile>(OtherActor))
		{
			Destroy();
		}
		else if (Cast<AChar_Game>(OtherActor))
		{
			Cast<AChar_Game>(OtherActor)->TakeDamage(10);
			Destroy();
		}
		else
		{
			Bounce++;
			if (Bounce > 1)
				Destroy();
			
		}
	}
	else if (OtherActor == GetOwner())
	{
		Destroy();
	}
}



