#include <QtTest>
#include <vector>
#include <algorithm>
#include "../../RS019-monopol/src/Player.hpp"
#include "../../RS019-monopol/src/Bank.hpp"
#include "../../RS019-monopol/src/Property.hpp"
#include "../../RS019-monopol/src/ActionSpace.hpp"
#include "../../RS019-monopol/src/Board.hpp"
#include "utilityFunctionsForTesting.h"

// add necessary includes here

class monopolFunctionalities : public QObject
{
    Q_OBJECT

public:
    monopolFunctionalities();
    ~monopolFunctionalities();

private slots:
    void initTestCase();
    void cleanupTestCase();

    //void actionSpacehasValidAction(); // Action space

    void playersBalanceAfterBuyCase();  // Bank functionalities
    void decrementedNumberOfHousesAfterSell();
    void incrementedPlayersBalanceAfterGive();
    void thrownExceptionForIncorrectArgumentGive();
    void decrementedPlayersBalanceAfterTake();
    void bankNotTakesIsufficientOnAccount();
    void thrownExceptionForIncorrectArgumentTake();
    void numberOfHousesIsReallySet();
    void numberOfHotelsIsReallySet();
    void negativeNumberOfHousesIsntAllowed();
    void negativeNumberOfHotelsIsntAllowed();


};


monopolFunctionalities::monopolFunctionalities()
{

}

monopolFunctionalities::~monopolFunctionalities()
{

}

void monopolFunctionalities::initTestCase()
{

}

void monopolFunctionalities::cleanupTestCase()
{

}

// TODO:
// *** Testing functionalities of Board ***


// *** Testing functionalities of Bank ***

// Changed player's account balance after buy space (for instance he bought property)
void monopolFunctionalities::playersBalanceAfterBuyCase()
{
    Player* player = new Player(1, "Johnson", 3000, false, 1, 1, false); // Arrange
    Property* property = new Property(200, 20, 21, 25, 30, 35, 45, 10, 100, "Oiaza", "Green");

    Bank* bank = new Bank();

    int before = player->get_wallet();
    int amount = property->getBuyPrice();
    bank->sellSpace(player, property); // Act
    int after = player->get_wallet();

    QCOMPARE(before, after + amount); // Assert
}

// === FUNCTION DIDN'T IMPLEMENTED ===
// Changed count of avaiable houses in bank after sell of house
void monopolFunctionalities::decrementedNumberOfHousesAfterSell()
{
    Player* player = new Player();
    Bank* bank = new Bank();

    int numberOfHousesBefore = bank->getHouses();
    //bank->sellHouse(player);
    int numberOfHousesAfter = bank->getHouses();

    QVERIFY(numberOfHousesBefore == numberOfHousesAfter + 1);
}

// Incremented balance on player's account after bank's giving money
void monopolFunctionalities::incrementedPlayersBalanceAfterGive() {
    Player* player = new Player(1, "Maria", 2000, false, 1, 0, false);
    Bank* bank = new Bank();

    int accountBalanceBefore = player->get_wallet();
    bank->giveMoney(player, 700);
    int accountBalanceAfter = player->get_wallet();

    QCOMPARE(accountBalanceAfter, accountBalanceBefore + 700);
}

// Thrown exception for incorrect argument for giving money (negative value)
void monopolFunctionalities::thrownExceptionForIncorrectArgumentGive() {
    Player* player = new Player();
    Bank* bank = new Bank();

    QVERIFY_EXCEPTION_THROWN(bank->giveMoney(player, -20), std::invalid_argument);
}

// Decremented balance on player's account after taking money
void monopolFunctionalities::decrementedPlayersBalanceAfterTake() {
    Player* player = new Player(1, "Georgina", 1000, false, 1, 0, true);
    Bank* bank = new Bank();

    int accountBalanceBefore = player->get_wallet();
    bank->takeMoney(player, 50);
    int accountBalanceAfter = player->get_wallet();

    QCOMPARE(accountBalanceBefore, accountBalanceAfter + 50);
}

// Bank doesn't take the amount of player if player doesn't have enough (and player won't take a minus on account)
void monopolFunctionalities::bankNotTakesIsufficientOnAccount() {
    Player* player = new Player(1, "Joe", 100, false, 1, 0, false);
    Bank* bank = new Bank();

    bank->takeMoney(player, 120);
    QVERIFY(player->get_wallet() >= 0);
}

// Thrown exception for incorrect argument for taking money (negative value)
void monopolFunctionalities::thrownExceptionForIncorrectArgumentTake() {
    Player* player = new Player();
    Bank* bank = new Bank();

    QVERIFY_EXCEPTION_THROWN(bank->takeMoney(player, -33), std::exception);
}

// Number of avaiable houses is really set on desired positive value
void monopolFunctionalities::numberOfHousesIsReallySet() {
    Bank* b = new Bank();
    b->setHouses(70);

    QCOMPARE(b->getHouses(), 70);
}

// Number of avaiable hotels is really set on desired positive value
void monopolFunctionalities::numberOfHotelsIsReallySet() {
    Bank* b = new Bank();
    b->setHotels(70);

    QCOMPARE(b->getHotels(), 70);
}

// Set of negative values to number of houses won't be allowed
void monopolFunctionalities::negativeNumberOfHousesIsntAllowed() {
    Bank* b = new Bank();

    b->setHouses(-1);
    QVERIFY(b->getHouses() >= 0);
}

// Set of negative values to number of hotels won't be allowed
void monopolFunctionalities::negativeNumberOfHotelsIsntAllowed() {
    Bank* b = new Bank();

    b->setHouses(-1);
    QVERIFY(b->getHotels() >= 0);
}


QTEST_APPLESS_MAIN(monopolFunctionalities)

#include "tst_monopolfunctionalities.moc"
