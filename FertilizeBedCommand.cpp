#include "FertilizeBedCommand.h"

FertilizeBedCommand::FertilizeBedCommand(std::string b) {
    bedName = b;
}

void FertilizeBedCommand::execute() {
        std::cout << "Fertilizing bed: " << bedName << "\n";
    }

