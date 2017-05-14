#include "HardDriveSet.h"
#include <iostream>

std::string HardDriveSet::getPartInformation() const
{
    std::string partInformation("Hard Drives: Number Of Drives: ");
    std::stringstream ss;
    ss << m_numberOfHardDrives;
    partInformation += ss.str();

    for(unsigned i = 0; i < m_numberOfHardDrives; i++)
    {
        ss.str("");
        ss.clear();
        ss << i+1;

        if (SolidStateDrive* ssDrive = dynamic_cast<SolidStateDrive*>(m_hardDrives[i]))
        {
            partInformation += "\nDrive " + ss.str() + ": " + ssDrive->getPartInformation();
        }
        else if (HardDiscDrive* hhDrive = dynamic_cast<HardDiscDrive*>(m_hardDrives[i]))
        {
            partInformation += "\nDrive " + ss.str() + ": " + hhDrive->getPartInformation();
        } else {
            partInformation += "\nDrive " + ss.str() + ": " + m_hardDrives[i]->getPartInformation();
        }
    }
    return partInformation;
}
