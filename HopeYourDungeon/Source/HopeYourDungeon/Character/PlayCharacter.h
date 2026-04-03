// HEADER FILE

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "PlayCharacter.generated.h"

class UAbilitySystemComponent;
class UPlayHealthAttributeSet;

UCLASS()
class PLAYGROUNDGAS_API APlayCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY()
    TObjectPtr<UPlayHealthAttributeSet> HealthAttributeSet;

    UPROPERTY(EditAnywhere)
    float InitialHealth = 100.0f; // todo future - set in BP instead of here

    UFUNCTION()
    void HandleHealthChanged(float Magnitude, float NewHealth);
};