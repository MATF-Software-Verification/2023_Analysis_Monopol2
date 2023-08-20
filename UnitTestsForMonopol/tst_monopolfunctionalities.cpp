#include <QtTest>
#include <vector>
#include <algorithm>
#include "../../RS019-monopol/src/Player.hpp"
#include "../../RS019-monopol/src/Bank.hpp"
#include "../../RS019-monopol/src/Property.hpp"
#include "../../RS019-monopol/src/ActionSpace.hpp"
#include "../../RS019-monopol/src/Board.hpp"
#include "../../RS019-monopol/src/Card.hpp"
#include "../../RS019-monopol/src/Utility.hpp"
#include "../../RS019-monopol/src/Railroad.hpp"
#include "../../RS019-monopol/src/Game.hpp"

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
    void incrementedPlayersBalanceAfterGive();
    void decrementedPlayersBalanceAfterTake();
    void bankNotTakesIsufficientOnAccount();
    void numberOfHousesIsReallySet();
    void numberOfHotelsIsReallySet();
    //void decrementedNumberOfHousesAfterSell();

    void addPlayerToUtility();  // Utility functionalities
    void erasedPlayerFromUtility();

    //void chanceCardIsDrawnFromDesk(); // Board functionalities

    void numberOfPropertiesIncreasedAfterBuy(); // Player functionalities
    void numberOfUtilitiesIncreasedAfterBuy();
    void numberOfRailroadsIncreasedAfterBuy();
    void propertyOwnedByPlayerAfterAddition();

    void throwDiceIsCorrect(); // Game functionalities
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


// *** Testing functionalities of Bank ***

void monopolFunctionalities::playersBalanceAfterBuyCase()
{
    Player* player = new Player(1, "Johnson", 3000, false, 1, 1, false); // Arrange
    Property* property = new Property(200, 20, 21, 25, 30, 35, 45, 10, 100, "Piazza Venezia", "Green");

    Bank* bank = new Bank();

    int before = player->get_wallet();
    int amount = property->getBuyPrice();
    bank->sellSpace(player, property); // Act
    int after = player->get_wallet();

    QCOMPARE(before, after + amount); // Assert
}
/*
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
}*/

// Incremented balance on player's account after bank's giving money
void monopolFunctionalities::incrementedPlayersBalanceAfterGive() {
    Player* player = new Player(1, "Maria", 2000, false, 1, 0, false);
    Bank* bank = new Bank();

    int accountBalanceBefore = player->get_wallet();
    bank->giveMoney(player, 700);
    int accountBalanceAfter = player->get_wallet();

    QCOMPARE(accountBalanceAfter, accountBalanceBefore + 700);
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

// *** Testing functionalities of Utility ***

// Player would be really added from utility
void monopolFunctionalities::addPlayerToUtility() {
    Utility* u = new Utility(20, 40, "Eletric energy");
    Player* p = new Player();

    u->addPlayer(p->getId());
    QVERIFY(std::find(u->player().begin(), u->player().end(), p->getId()) != u->player().end());
}

// Player would be really removed from utility
void monopolFunctionalities::erasedPlayerFromUtility() {
    Utility* u = new Utility(20, 40, "Eletric energy");
    Player* p = new Player();

    u->addPlayer(p->getId());
    u->removePlayer(p->getId());

    QVERIFY(std::find(u->player().begin(), u->player().end(), p->getId()) == u->player().end());
}

/*
// === FUNCTIONS FOR CHECK OF STATEMENT OF CHANCE DECK DIDN'T IMPLEMENTED ===
// Number of cards decreased after draw
void monopolFunctionalities::chanceCardIsDrawnFromDesk() {
    Board* b = new Board();
    int numberOfChanceCardsBefore = 0;
    //numberOfChanceCardsBefore = b->getChanceDeck().size();

    b->drawChanceCard();

    int numberOfChanceCardsAfter = 0;
    //numberOfChanceCardsAfter = b->getChanceDeck().size();
    QCOMPARE(numberOfChanceCardsBefore, numberOfChanceCardsAfter+1);
}*/

// *** Testing functionalities of Player ***

// Number of player's properties increased after buy
void monopolFunctionalities::numberOfPropertiesIncreasedAfterBuy() {
    Player* p = new Player();
    Property* pt = new Property(200, 20, 21, 25, 30, 35, 45, 10, 100, "Piazza Venezia", "Green");
    Bank* b = new Bank();
    int numberOfPropertiesBefore = p->get_properties().size();

    //p->buy(pt); FUNCTION DIDN'T IMPLEMENTED
    b->sellSpace(p, pt);

    int numberOfPropertiesAfter = p->get_properties().size();
    QVERIFY(numberOfPropertiesAfter == numberOfPropertiesBefore + 1);
}

// Number of player's utilities increased after buy
void monopolFunctionalities::numberOfUtilitiesIncreasedAfterBuy() {
    Player* p = new Player();
    Utility* u = new Utility(100, 120, "Electricity");
    Bank* b = new Bank();
    int numberOfUtilitiesBefore = p->get_utilities().size();

    //p->buy(pt); FUNCTION DIDN'T IMPLEMENTED
    b->sellSpace(p, u);

    int numberOfUtilitiesAfter = p->get_utilities().size();
    QVERIFY(numberOfUtilitiesAfter == numberOfUtilitiesBefore + 1);
}

// Number of player's railroads increased after buy
void monopolFunctionalities::numberOfRailroadsIncreasedAfterBuy() {
    Player* p = new Player();
    Railroad* r = new Railroad(400, 50, 450, "Railway South");
    Bank* b = new Bank();
    int numberOfRailroadsBefore = p->get_railroads().size();

    //p->buy(pt); FUNCTION DIDN'T IMPLEMENTED
    b->sellSpace(p, r);

    int numberOfRailroadsAfter = p->get_railroads().size();
    QVERIFY(numberOfRailroadsAfter == numberOfRailroadsBefore + 1);
}


void monopolFunctionalities::propertyOwnedByPlayerAfterAddition() {
    Player* p = new Player();
    Property* pt = new Property(200, 20, 21, 25, 30, 35, 45, 10, 100, "Barcelonetta", "Blue");

    p->add_property(pt);

    auto owned_properties = p->get_properties();
    QVERIFY2(find(owned_properties.begin(), owned_properties.end(), pt) != owned_properties.end(),
             "Is new property really in list of player's properties");

}

// *** Testing functionalities of Game ***

// Values on dice after throw are correct and in interval [1, 6]
void monopolFunctionalities::throwDiceIsCorrect() {
    std::vector<Player*> ps {new Player(), new Player()};
    Board* b = new Board();
    Bank* bk = new Bank();
    Game *g = new Game(ps,  b, bk);

    g->throwDice();

    auto values = g->getDice();
    QVERIFY(values.first <= 6);
    QVERIFY(values.second <= 6);
    QVERIFY(values.first >= 1);
    QVERIFY(values.second >= 1);
}

QTEST_APPLESS_MAIN(monopolFunctionalities)

#include "tst_monopolfunctionalities.moc"
