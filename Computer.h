#ifndef COMPUTER_H
#define COMPUTER_H

#include "ComputerPlan.h"
#include "PartAllocator.h"

class Computer : public ComputerPlan
{
public:

    /**
     * @brief Computer default constructor
     */
    Computer()
        : m_requiredParts(new Part*[8]),
          m_numberOfAdditionalParts(0), m_numberOfAssignedAdditionalParts(0)
    {
    }

    /**
     * @brief ~Computer destructor
     */
    virtual ~Computer()
    {
    }

    // Getters

    /**
     * @brief getComputerType retrieves the computer's type
     * @return the computer's type as std::string
     */
    virtual const std::string& getComputerType() const{ return m_computerType;}

    /**
     * @brief getCPU retrieves the computer's cpu information
     * @return the computer's CPU
     */
    virtual const CPU& getCPU() const{ return static_cast<const CPU&>(*m_requiredParts[CPUID]); }

    /**
     * @brief getMotherboard retrieves the computer's motherboard information
     * @return the computer's Motherboard
     */
    virtual const Motherboard& getMotherboard() const{ return static_cast<const Motherboard&>(*m_requiredParts[MotherboardID]);}

    /**
     * @brief getRamSet retrieves the computer's ram set information
     * @return the computer's RamSet
     */
    virtual const RamSet& getRamSet() const{ return static_cast<const RamSet&>(*m_requiredParts[RamSetID]);}

    /**
     * @brief getHardDriveSet retrieves the computer's hard drive set information
     * @return the computer's HardDriveSet
     */
    virtual const HardDriveSet& getHardDriveSet() const{ return static_cast<const HardDriveSet&>(*m_requiredParts[HardDriveSetID]);}

    /**
     * @brief getGraphicsCardSet retrieves the computer's graphics card set information
     * @return the computer's GraphicsCardSet
     */
    virtual const GraphicsCardSet& getGraphicsCardSet() const{ return static_cast<const GraphicsCardSet&>(*m_requiredParts[GraphicsCardSetID]);}

    /**
     * @brief getPowerSupply retrieves the computer's PSU information
     * @return the computer's PowerSupply
     */
    virtual const PowerSupply& getPowerSupply() const{ return static_cast<const PowerSupply&>(*m_requiredParts[PowerSupplyID]);}

    /**
     * @brief getCase retrieves the computer's case information
     * @return the computer's Case
     */
    virtual const Case& getCase() const{ return static_cast<const Case&>(*m_requiredParts[CaseID]);}

    /**
     * @brief getAdditionalPartsList retrieves the computer's optional part information
     * @return the computer's additional part information
     */
    virtual Part** getAdditionalPartsList() const{ return m_additionalParts;}

    /**
     * @brief getNumberOfAdditionalParts retrieves the number of optional parts included in the computer
     * @return the number of additional parts included
     */
    virtual int getNumberOfAdditionalParts() const{ return m_numberOfAdditionalParts;}

    /**
     * @brief getComputerSpecifications retrieves the computers specification
     * @return as a std::string the computers specifications
     */
    virtual std::string getComputerSpecifications() const;

    // Setters

    /**
     * @brief setComputerType setter method for computerType
     * @param computerType computer's type as std::string
     */
    virtual void setComputerType(const std::string &computerType){m_computerType = computerType;}

    /**
     * @brief setCPU setter method for CPU
     * @param cpu computer's CPU
     */
    virtual void setCPU(const CPU &cpu){m_requiredParts[CPUID] = PartAllocator::getPart(cpu);}

    /**
     * @brief setMotherboard setter method for Motherboard
     * @param motherboard computer's Motherboard
     */
    virtual void setMotherboard(const Motherboard &motherboard){m_requiredParts[MotherboardID] = PartAllocator::getPart(motherboard);}

    /**
     * @brief setRAM setter method for RamSet
     * @param ram list of Ram
     * @param numberOfRamSticks number of items in Ram array
     */
    virtual void setRAM(Ram* ram, int numberOfRamSticks){m_requiredParts[RamSetID] = PartAllocator::getRamSet(ram, numberOfRamSticks);}

    /**
     * @brief setHardDrives setter method for HardDriveSet
     * @param hardDrive list of HardDrive pointers
     * @param numberOfHardDrives number of items in HardDrive array
     */
    virtual void setHardDrives(HardDrive** hardDrive, int numberOfHardDrives){m_requiredParts[HardDriveSetID] = PartAllocator::getHardDriveSet(hardDrive, numberOfHardDrives);}

    /**
     * @brief setGraphicsCards setter method for GraphicsCardSet
     * @param graphicsCard list of GraphicsCard
     * @param numberOfGraphicsCard number of items in GraphicsCard array
     */
    virtual void setGraphicsCards(GraphicsCard* graphicsCard, int numberOfGraphicsCard){m_requiredParts[GraphicsCardSetID] = PartAllocator::getGraphicsCardSet(graphicsCard, numberOfGraphicsCard);}

    /**
     * @brief setPowerSupply setter method for PowerSupply
     * @param powerSupply computer's PowerSupply
     */
    virtual void setPowerSupply(const PowerSupply &powerSupply){m_requiredParts[PowerSupplyID] = PartAllocator::getPart(powerSupply);}

    /**
     * @brief setCase setter method for Case
     * @param computerCase computer's Case
     */
    virtual void setCase(const Case &computerCase){m_requiredParts[CaseID] = PartAllocator::getPart(computerCase);}

    /**
     * @brief setNumberOfAdditionalParts sets the number of additional parts permitted for computer
     * @param numberOfAdditionalParts the number of additional parts permitted for computer
     */
    virtual void setNumberOfAdditionalParts(int numberOfAdditionalParts )
    {
        m_numberOfAdditionalParts = numberOfAdditionalParts;
        m_additionalParts = new Part*[m_numberOfAdditionalParts];
    }

    /**
     * @brief addAdditionalPart adds one new additional Part to computer
     * @param part additional Part to add to computer
     */
    virtual void addAdditionalPart(const Part &part)
    {
        m_additionalParts[m_numberOfAssignedAdditionalParts] = PartAllocator::getPart(part);
        m_numberOfAssignedAdditionalParts++;
    }

protected:

    enum ComputerPartID
    {
        CPUID,
        MotherboardID,
        RamSetID,
        HardDriveSetID,
        GraphicsCardSetID,
        CaseID,
        PowerSupplyID
    };

    std::string m_computerType;

    Part** m_requiredParts;
    static int numberOfRequiredParts;

    Part** m_additionalParts;
    int m_numberOfAdditionalParts;
    int m_numberOfAssignedAdditionalParts;
};

#endif // COMPUTER_H
