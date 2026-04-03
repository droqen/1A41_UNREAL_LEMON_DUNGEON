#include "AbilitySystem/Attributes/PlayHealthAttributeSet.h"
#include "GameplayEffectExtension.h"

void UPlayHealthAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        OnHealthChanged.Broadcast(Data.EvaluatedData.Magnitude, GetHealth());
    }
}