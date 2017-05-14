#include "CPU.h"

CPU::CPU()
    : Part("CPU")
{

}

CPU::CPU(const std::string &name, double clockSpeed, const std::string &socketType)
    : Part(name), m_clockSpeed(clockSpeed), m_socketType(socketType)
{

}

CPU::CPU(const CPU& cpu)
    : CPU(cpu.m_name, cpu.m_clockSpeed, cpu.m_socketType)
{

}

CPU::~CPU(){

}

std::string CPU::getPartInformation() const
{
    std::stringstream ss;
    ss << m_clockSpeed;
    std::string partInformation("CPU: " + m_name + ", Clock Speed: "
                                + ss.str() + " Ghz, Socket: " + m_socketType);
    return partInformation;

}
