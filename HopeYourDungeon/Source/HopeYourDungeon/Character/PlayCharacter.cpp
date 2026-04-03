// CPP FILE

#include "Character/PlayCharacter.h"
#include "AbilitySystemComponent.h"

APlayCharacter::APlayCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    HealthAttributeSet = CreateDefaultSubobject<UPlayHealthAttributeSet>(TEXT("HealthAttributeSet"));
}

void APlayCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (HealthAttributeSet)
    {
        HealthAttributeSet->OnHealthChanged.AddDynamic(this, &APlayCharacter::HandleHealthChanged);
    }
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
        AbilitySystemComponent->SetNumericAttributeBase(UPlayHealthAttributeSet::GetHealthAttribute(), InitialHealth);
    }
}

void APlayCharacter::HandleHealthChanged(float Magnitude, float NewHealth)
{
    if (NewHealth < 0)
    {
        Destroy(); // destroy??? really???
    }
}

UAbilitySystemComponent* APlayCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}
