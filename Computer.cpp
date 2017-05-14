#include "Computer.h"

// TODO
std::string Computer::getComputerSpecifications() const
{
    std::string computerSpecification(getComputerType());
    for(unsigned ID = CPUID; ; ID++){
        Part* part = m_requiredParts[ID];
        if(part){
            computerSpecification += "\n" +part->getPartInformation();
        }
        if(ID == PowerSupplyID){
            break;
        }
    }
    computerSpecification += "\nAdditional Parts";

    for(unsigned i = 0; i < m_numberOfAssignedAdditionalParts; i++){
        computerSpecification += "\n" + m_additionalParts[i]->getPartInformation();
    }

    return computerSpecification;
}
