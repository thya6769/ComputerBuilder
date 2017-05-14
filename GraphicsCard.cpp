#include "GraphicsCard.h"

GraphicsCard::GraphicsCard()
{

}

GraphicsCard::GraphicsCard(const std::string &name, int speed, int size) : Part(name), m_speed(speed), m_size(size)
{

}

GraphicsCard::GraphicsCard(const GraphicsCard &graphicsCard) : Part(graphicsCard.m_name), m_speed(graphicsCard.m_speed), m_size(graphicsCard.m_size)
{

}

GraphicsCard::~GraphicsCard()
{

}

std::string GraphicsCard::getPartInformation() const
{

    std::stringstream ss;
    ss << m_speed <<  " Mhz, Size: " << m_size << " GB";

    std::string partInformation(m_name + ", Frequency: " + ss.str());

    return partInformation;
}
