

#include "Inventory.h"
#include <iostream>


void Inventory::addPlant(const std::string& itemName, NurseryPlant* plant) {
    if (itemStock.find(itemName) == itemStock.end()) {
        itemStock[itemName] = std::vector<NurseryPlant*>();
    }
    itemStock[itemName].push_back(plant);
}

void Inventory::removePlant(const std::string& itemName) {
    auto it = itemStock.find(itemName);
    if (it != itemStock.end() && !it->second.empty()) {
        it->second.pop_back();
        if (it->second.empty()) {
            itemStock.erase(it);
        }
    } else {
        std::cout << "No plants of this type in inventory to remove.\n";
    }
}


void Inventory::displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& pair : itemStock) {
        std::cout << "Item: " << pair.first << ", Stock: " << pair.second.size() << "\n";
    }
}
