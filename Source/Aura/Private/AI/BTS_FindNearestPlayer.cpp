// Copyright Henebene


#include "AI/BTS_FindNearestPlayer.h"
#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void UBTS_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    AAIController* Controller = OwnerComp.GetAIOwner();
    const APawn* OwningPawn = Controller->GetPawn();

    const FName TargetTag = OwningPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");

    /** Same Stephen's code look for players */
    TArray<AActor*> ActorsWithTargetTag;
    UGameplayStatics::GetAllActorsWithTag(OwningPawn, TargetTag, ActorsWithTargetTag);

    float ClosestDistance = TNumericLimits<float>::Max();
    AActor* ClosestActor = nullptr;

    for (AActor* NewActor : ActorsWithTargetTag)
    {
        const float NewDistance = OwningPawn->GetDistanceTo(NewActor);
        if (IsValid(NewActor) && IsValid(OwningPawn))
        {
            if (NewDistance < ClosestDistance)
            {
                ClosestDistance = NewDistance;
                ClosestActor = NewActor;
            }
        }
    }
    /** End of same code */

    Controller->GetBlackboardComponent()->SetValueAsObject(TargetToFollowSelector.SelectedKeyName, ClosestActor);
    Controller->GetBlackboardComponent()->SetValueAsFloat(DistanceToTargetSelector.SelectedKeyName, ClosestDistance);
}