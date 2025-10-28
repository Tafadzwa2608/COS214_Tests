#include "Crate.h"
#include <iostream>

Crate::Crate(const std::string& material)
    : material(material)
{
    std::cout << "Crate created with material: " << material << std::endl;
}

void Crate::display() const {
    std::cout << "Container type: Crate, Material: " << material << std::endl;
}

std::string Crate::getType() const {
    return "Crate";
}
