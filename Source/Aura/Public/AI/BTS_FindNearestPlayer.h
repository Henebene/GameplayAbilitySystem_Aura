// Copyright Henebene

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_FindNearestPlayer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AURA_API UBTS_FindNearestPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FBlackboardKeySelector TargetToFollowSelector;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FBlackboardKeySelector DistanceToTargetSelector;
	
};
