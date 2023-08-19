#include "utilityFunctionsForTesting.h"

std::set<int> functionsForActionSpace::initValidActions() {
    std::set<int> validActions;
    validActions.insert( static_cast<int>(ActionSpace::EnumActionSpace::CHANCE));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::COMMUNITY_CHEST));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::GOTO_JAIL));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::INCOME_TAX));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::FREE_PARKING));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::GO));
    validActions.insert(static_cast<int>(ActionSpace::EnumActionSpace::JAIL));
}
