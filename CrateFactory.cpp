#include "CrateFactory.h"
#include "Crate.h"
#include <iostream>

Container* CrateFactory::createContainer(std::string material){
    
   
    return new Crate(material);
}