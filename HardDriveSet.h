#ifndef HARDDRIVESET_H
#define HARDDRIVESET_H

#include "HardDrive.h"
#include "SolidStateDrive.h"
#include "HardDiscDrive.h"

class HardDriveSet : public Part
{
public:

    /**
     * @brief HardDriveSet default constructor
     */
    HardDriveSet()
        : m_hardDrives(0), m_numberOfHardDrives(-1)
    {}

    /**
     * @brief HardDriveSet constructor
     * @param hardDrives array of HardDrive pointers
     * @param numberOfHardDrives number of elements in array of HardDrive pointers
     */
    HardDriveSet(HardDrive** hardDrives, int numberOfHardDrives)
        : Part("Hard Drive Set"), m_hardDrives(new HardDrive*[numberOfHardDrives]), m_numberOfHardDrives(numberOfHardDrives)
    {
        for(unsigned i = 0; i < m_numberOfHardDrives; i++){
            if (SolidStateDrive* ssDrive = dynamic_cast<SolidStateDrive*>(hardDrives[i]))
            {
                m_hardDrives[i] = new SolidStateDrive(*ssDrive);

            }else if (HardDiscDrive* hhDrive = dynamic_cast<HardDiscDrive*>(hardDrives[i]))
            {
                m_hardDrives[i] = new HardDiscDrive(*hhDrive);

            } else {
                m_hardDrives[i] = new HardDrive(*hardDrives[i]);
            }
        }
    }

    /**
     * @brief HardDriveSet copy constructor
     * @param hardDriveSet instance of the HardDriveSet to perform a deep copy on
     */
    HardDriveSet(const HardDriveSet& hardDriveSet)
        : Part("Hard Drive Set"), m_hardDrives(new HardDrive*[hardDriveSet.m_numberOfHardDrives]),
          m_numberOfHardDrives(hardDriveSet.m_numberOfHardDrives)
    {
        for(unsigned i = 0; i < hardDriveSet.m_numberOfHardDrives; i++){

            if (SolidStateDrive* ssDrive = dynamic_cast<SolidStateDrive*>(hardDriveSet.m_hardDrives[i]))
            {
                m_hardDrives[i] = new SolidStateDrive(*ssDrive);

            }else if (HardDiscDrive* hhDrive = dynamic_cast<HardDiscDrive*>(hardDriveSet.m_hardDrives[i]))
            {
                m_hardDrives[i] = new HardDiscDrive(*hhDrive);

            } else {
                m_hardDrives[i] = new HardDrive(*hardDriveSet.m_hardDrives[i]);
            }
        }
    }

    /**
     * @brief ~HardDriveSet destructor
     */
    virtual ~HardDriveSet()
    {
        for(unsigned i = 0; i < m_numberOfHardDrives; i++){
            delete m_hardDrives[i];
        }
        delete[] m_hardDrives;
    }

    /**
     * @brief getPartInformation constructs the part information for the HardDriveSet class
     * @return returns the part information for the HardDriveSet class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getHardDrives retrieves an array of HardDrive pointers
     * @return an array of HardDrive pointers
     */
    HardDrive** getHardDrives() const{return m_hardDrives;}

    /**
     * @brief getNumberOfHardDrives retrieves number of elements in array of HardDrive pointers
     * @return the number of elements in the HardDrive pointer array
     */
    int getNumberOfHardDrives() const{return m_numberOfHardDrives;}

private:
    HardDrive** m_hardDrives;
    int m_numberOfHardDrives;
};

#endif // HARDDRIVESET_H
