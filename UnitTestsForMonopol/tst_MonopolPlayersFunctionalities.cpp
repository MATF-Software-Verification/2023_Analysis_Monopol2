#include <QtTest>
#include "../../RS019-monopol/src/Player.hpp"
#include "../../RS019-monopol/src/Bank.hpp"
#include "../../RS019-monopol/src/Property.hpp"
#include <vector>

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

    void playersBalanceAfterBuyCase();  // Bank functionalities
    void decrementedNumberOfHousesAfterSell();
    void incrementedPlayersBalanceAfterGive();
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

// Testing functionalities of Bank

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

void monopolFunctionalities::incrementedPlayersBalanceAfterGive() {
    Player* player = new Player(1, "Maria", 2000, false, 1, 0, false);
    Bank* bank = new Bank();

    int accountBalanceBefore = player->get_wallet();
    bank->giveMoney(player, 700);
    int accountBalanceAfter = player->get_wallet();

    QCOMPARE(accountBalanceAfter, accountBalanceBefore + 700);
}


QTEST_APPLESS_MAIN(monopolFunctionalities)

#include "tst_monopolfunctionalities.moc"
