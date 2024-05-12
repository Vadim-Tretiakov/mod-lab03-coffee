#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, ConstructorInitializesStateAndCash) {
    Automata automata;
    EXPECT_EQ(automata.getState(), STATES::OFF);
    EXPECT_EQ(automata.cash, 0);
}

TEST(AutomataTest, OnTurnsOnTheMachine) {
    Automata automata;
    automata.on();
    EXPECT_EQ(automata.getState(), STATES::ON);
}

TEST(AutomataTest, OffTurnsOffTheMachine) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), STATES::OFF);
}

TEST(AutomataTest, CoinIncreasesCash) {
    Automata automata;
    automata.coin(10);
    EXPECT_EQ(automata.cash, 10);
}

TEST(AutomataTest, CancelChangesStateToCancel) {
    Automata automata;
    automata.cancel();
    EXPECT_EQ(automata.getState(), STATES::CANCEL);
}

TEST(AutomataTest, CookChangesStateToCook) {
    Automata automata;
    automata.cook();
    EXPECT_EQ(automata.getState(), STATES::COOK);
}

TEST(AutomataTest, FinishChangesStateToFinish) {
    Automata automata;
    automata.finish();
    EXPECT_EQ(automata.getState(), STATES::OFF);
}
