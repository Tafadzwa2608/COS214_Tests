#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include <sstream>
#include <iostream>
#include "HighMaintenancePlantFactory.h"
#include "LowMaintenancePlantFactory.h"
#include "CrateFactory.h"
#include "Garden.h"
#include "Staff.h"
#include "Inventory.h"
#include "BulkOrder.h"
#include "OrderSlip.h"
#include "RefundSlip.h"
#include "CashierHandler.h"
#include "ManagerHandler.h"
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "WaterPlantCommand.h"
#include "FertilizeBedCommand.h"
#include "PrepareCommand.h"
#include "PackageOrderCommand.h"
#include "DeliverOrderCommand.h"
#include "Invoker.h"
#include "Nurse.h"
#include "Manager.h"
#include "PlantExpert.h"
#include "RoseCare.h"
#include "AloeCare.h"
#include "BaobabCare.h"
#include "CherryCare.h"
#include "ConcreteState.h"

class PatternTestFixture
{
protected:
    PatternTestFixture()
    {
        inventory = new Inventory();
        lowFactory = new LowMaintenancePlantFactory();
        highFactory = new HighMaintenancePlantFactory();
        crateFactory = new CrateFactory();

        // Create test plants
        rose = highFactory->createFloweringPlant(150.0);
        aloe = lowFactory->createTree(1.2, 100.0);
        baobab = highFactory->createTree(5.0, 300.0);
        cherryBlossom = highFactory->createFloweringPlant(200.0);

        // Create staff
        basicStaff = new Staff(inventory, "Test Staff");
        nurse = new Nurse(inventory, "Test Nurse");
        manager = new Manager(inventory, "Test Manager");
        expert = new PlantExpert(inventory, "Test Expert");
    }

    ~PatternTestFixture()
    {
        delete inventory;
        delete lowFactory;
        delete highFactory;
        delete crateFactory;
        delete basicStaff;
        delete nurse;
        delete manager;
        delete expert;
    }

    Inventory *inventory;
    LowMaintenancePlantFactory *lowFactory;
    HighMaintenancePlantFactory *highFactory;
    CrateFactory *crateFactory;

    NurseryPlant *rose;
    NurseryPlant *aloe;
    NurseryPlant *baobab;
    NurseryPlant *cherryBlossom;

    Staff *basicStaff;
    Nurse *nurse;
    Manager *manager;
    PlantExpert *expert;
};

// Helper function to capture stdout
std::string captureStdout(std::function<void()> func)
{
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

// TEST 1: COMMAND PATTERN

TEST_CASE_METHOD(PatternTestFixture, "CommandPattern_WaterPlantCommandExecutes")
{
    WaterPlantCommand command("Test Plant");

    auto output = captureStdout([&]()
                                { command.execute(); });

    REQUIRE(output.find("Watering") != std::string::npos);
    REQUIRE(output.find("Test Plant") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "CommandPattern_FertilizeBedCommandExecutes")
{
    FertilizeBedCommand command("Test Bed");

    auto output = captureStdout([&]()
                                { command.execute(); });

    REQUIRE(output.find("Fertilizing") != std::string::npos);
    REQUIRE(output.find("Test Bed") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "CommandPattern_InvokerProcessesMultipleCommands")
{
    Invoker invoker;
    Command *waterCmd = new WaterPlantCommand("Plant1");
    Command *fertilizeCmd = new FertilizeBedCommand("Bed1");

    invoker.addCommand(waterCmd);
    invoker.addCommand(fertilizeCmd);

    auto output = captureStdout([&]()
                                { invoker.processCommands(); });

    REQUIRE(output.find("Watering") != std::string::npos);
    REQUIRE(output.find("Fertilizing") != std::string::npos);

    delete waterCmd;
    delete fertilizeCmd;
}

// TEST 2: CHAIN OF RESPONSIBILITY PATTERN

TEST_CASE_METHOD(PatternTestFixture, "CORPattern_CashierHandlerProcessesPayment")
{
    CashierHandler cashierHandler;
    cashierHandler.setPaymentStrategy(new CashPayment(200.0));

    Issue paymentIssue("Payment", "Test payment", rose);

    auto output = captureStdout([&]()
                                { cashierHandler.handle(&paymentIssue); });

    REQUIRE(output.find("CashierHandler processing") != std::string::npos);
    REQUIRE(output.find("Payment") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "CORPattern_ManagerHandlerProcessesStaffIssues")
{
    ManagerHandler managerHandler;

    Issue staffIssue("Staff", "Staff performance issue", nullptr);

    auto output = captureStdout([&]()
                                { managerHandler.handle(&staffIssue); });

    REQUIRE(output.find("ManagerHandler processing") != std::string::npos);
    REQUIRE(output.find("Staff") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "CORPattern_ChainRoutesToCorrectHandler")
{
    CashierHandler cashierHandler;
    ManagerHandler managerHandler;
    cashierHandler.setNext(&managerHandler);

    // Payment should be handled by Cashier
    Issue paymentIssue("Payment", "Test payment", rose);
    auto paymentOutput = captureStdout([&]()
                                       { cashierHandler.handle(&paymentIssue); });
    REQUIRE(paymentOutput.find("CashierHandler") != std::string::npos);

    // Staff issue should be passed to Manager
    Issue staffIssue("Staff", "Staff issue", nullptr);
    auto staffOutput = captureStdout([&]()
                                     { cashierHandler.handle(&staffIssue); });
    REQUIRE(staffOutput.find("ManagerHandler") != std::string::npos);
}

// TEST 3: STRATEGY PATTERN

TEST_CASE_METHOD(PatternTestFixture, "StrategyPattern_RoseCareExecutes")
{
    RoseCare roseCare;

    auto output = captureStdout([&]()
                                { roseCare.performCare(*rose); });

    REQUIRE(output.find("Performing care for Rose") != std::string::npos);
    REQUIRE(output.find("Water: daily") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "StrategyPattern_AloeCareExecutes")
{
    AloeCare aloeCare;

    auto output = captureStdout([&]()
                                { aloeCare.performCare(*aloe); });

    REQUIRE(output.find("Performing care for Aloe") != std::string::npos);
    REQUIRE(output.find("once every 10 days") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "StrategyPattern_StaffUsesCareStrategy")
{
    auto output = captureStdout([&]()
                                { basicStaff->careForPlant(*rose); });

    REQUIRE(output.find("is caring for") != std::string::npos);
}

// TEST 4: OBSERVER PATTERN

TEST_CASE_METHOD(PatternTestFixture, "ObserverPattern_StaffGetsNotifiedOfStateChange")
{
    rose->attach(dynamic_cast<Staff *>(manager));

    auto output = captureStdout([&]()
                                { rose->setState(new MatureState()); });

    REQUIRE(output.find("verifying plant quality") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "ObserverPattern_MultipleObserversGetNotified")
{
    rose->attach(basicStaff);
    rose->attach(nurse);

    auto output = captureStdout([&]()
                                { rose->setState(new MatureState()); });

    REQUIRE(output.find("Staff notified") != std::string::npos);
}

// TEST 5: COMPOSITE PATTERN

TEST_CASE_METHOD(PatternTestFixture, "CompositePattern_BulkOrderCalculatesTotal")
{
    BulkOrder bulkOrder;
    bulkOrder.addOrder(rose);
    bulkOrder.addOrder(aloe);

    double expectedTotal = rose->getTotal() + aloe->getTotal();
    REQUIRE(bulkOrder.getTotal() == expectedTotal);
}

TEST_CASE_METHOD(PatternTestFixture, "CompositePattern_NestedBulkOrder")
{
    BulkOrder individualOrders;
    individualOrders.addOrder(rose);
    individualOrders.addOrder(aloe);

    BulkOrder masterOrder;
    masterOrder.addOrder(&individualOrders);
    masterOrder.addOrder(baobab);

    double expectedTotal = rose->getTotal() + aloe->getTotal() + baobab->getTotal();
    REQUIRE(masterOrder.getTotal() == expectedTotal);
}

// TEST 6: ITERATOR PATTERN

TEST_CASE_METHOD(PatternTestFixture, "IteratorPattern_IteratesThroughOrders")
{
    BulkOrder bulkOrder;
    bulkOrder.addOrder(rose);
    bulkOrder.addOrder(aloe);
    bulkOrder.addOrder(baobab);

    Iterator *iterator = bulkOrder.createIterator();
    int count = 0;

    while (iterator->hasNext())
    {
        Order *order = iterator->next();
        REQUIRE(order != nullptr);
        count++;
    }

    REQUIRE(count == 3);
    delete iterator;
}

// TEST 7: TEMPLATE METHOD PATTERN

TEST_CASE_METHOD(PatternTestFixture, "TemplateMethodPattern_OrderSlipGenerates")
{
    OrderSlip orderSlip(rose);

    auto output = captureStdout([&]()
                                { orderSlip.printSlip(); });

    REQUIRE(output.find("Slip Header") != std::string::npos);
    REQUIRE(output.find("Order ID") != std::string::npos);
    REQUIRE(output.find("End of Slip") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "TemplateMethodPattern_RefundSlipGenerates")
{
    RefundSlip refundSlip(aloe);

    auto output = captureStdout([&]()
                                { refundSlip.printSlip(); });

    REQUIRE(output.find("Refund ID") != std::string::npos);
    REQUIRE(output.find("Refund Amount") != std::string::npos);
}

// TEST 8: PROTOTYPE PATTERN

TEST_CASE_METHOD(PatternTestFixture, "PrototypePattern_PlantCloneCreatesCopy")
{
    Order *clonedRose = rose->clone();

    REQUIRE(rose != clonedRose);
    REQUIRE(rose->getTotal() == clonedRose->getTotal());

    delete clonedRose;
}

TEST_CASE_METHOD(PatternTestFixture, "PrototypePattern_BulkOrderClone")
{
    BulkOrder original;
    original.addOrder(rose);
    original.addOrder(aloe);

    Order *cloned = original.clone();
    REQUIRE(original.getTotal() == cloned->getTotal());

    delete cloned;
}

// TEST 9: FACTORY PATTERN

TEST_CASE_METHOD(PatternTestFixture, "FactoryPattern_CreatesDifferentPlantTypes")
{
    auto newRose = highFactory->createFloweringPlant(100.0);
    auto newAloe = lowFactory->createTree(1.0, 50.0);

    REQUIRE(newRose != nullptr);
    REQUIRE(newAloe != nullptr);
    REQUIRE(dynamic_cast<FloweringPlant *>(newRose) != nullptr);
    REQUIRE(dynamic_cast<Tree *>(newAloe) != nullptr);

    delete newRose;
    delete newAloe;
}

// TEST 10: STAFF SPECIALIZATIONS

TEST_CASE_METHOD(PatternTestFixture, "StaffPattern_NurseSpecializedCare")
{
    auto output = captureStdout([&]()
                                { nurse->tendToPlants(rose); });

    REQUIRE(output.find("tending to plant health") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "StaffPattern_ManagerFunctions")
{
    auto output = captureStdout([&]()
                                { manager->reviewStaffPerformance(); });

    REQUIRE(output.find("conducting staff performance review") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "StaffPattern_PlantExpertDynamicStrategy")
{
    auto output = captureStdout([&]()
                                { expert->careForSpecificPlant(*baobab, new BaobabCare()); });

    REQUIRE(output.find("caring for") != std::string::npos);
}

// TEST 11: ORDER PROCESSING

TEST_CASE_METHOD(PatternTestFixture, "OrderProcessing_OrderLifecycleCommands")
{
    PrepareCommand prepareCmd(rose);
    PackageOrderCommand packageCmd(rose);

    auto output = captureStdout([&]()
                                {
        prepareCmd.execute();
        packageCmd.execute(); });

    REQUIRE(output.find("Preparing order") != std::string::npos);
    REQUIRE(output.find("Packaging order") != std::string::npos);
}

// TEST 12: GARDEN MANAGEMENT

TEST_CASE_METHOD(PatternTestFixture, "GardenManagement_AddRemovePlants")
{
    Garden garden;

    REQUIRE(garden.getPlantCount() == 0);

    garden.addPlant(rose, nullptr);
    REQUIRE(garden.getPlantCount() == 1);

    garden.addPlant(aloe, nullptr);
    REQUIRE(garden.getPlantCount() == 2);

    garden.removePlant(0);
    REQUIRE(garden.getPlantCount() == 1);
}

// TEST 13: PAYMENT STRATEGY

TEST_CASE_METHOD(PatternTestFixture, "PaymentStrategy_CashPaymentProcesses")
{
    CashPayment cashPayment(100.0);

    auto output = captureStdout([&]()
                                {
        bool success = cashPayment.processPayment(50.0);
        REQUIRE(success == true); });

    REQUIRE(output.find("Cash payment processed") != std::string::npos);
}

TEST_CASE_METHOD(PatternTestFixture, "PaymentStrategy_CreditCardPaymentProcesses")
{
    CreditCardPayment creditPayment("1234567812345678", "12/25");

    auto output = captureStdout([&]()
                                {
        bool success = creditPayment.processPayment(100.0);
        REQUIRE(success == true); });

    REQUIRE(output.find("Processing credit card payment") != std::string::npos);
}