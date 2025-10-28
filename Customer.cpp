#include "Customer.h"

Customer::Customer(std::string n) {
    name = n;
}

std::string Customer::getName() {
    return name;
}