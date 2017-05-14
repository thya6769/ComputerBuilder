#include "GraphicsCardSet.h"

GraphicsCardSet::GraphicsCardSet()
    : m_graphicsCards(0), m_numberOfGraphicsCards(-1)
{

}

GraphicsCardSet::GraphicsCardSet(GraphicsCard* graphicsCards, int numberOfGraphicsCards)
    : Part("Graphics Card Set"),  m_graphicsCards(new GraphicsCard[numberOfGraphicsCards])
    , m_numberOfGraphicsCards(numberOfGraphicsCards)
{
    for (int i = 0; i < m_numberOfGraphicsCards; ++i)
    {
        m_graphicsCards[i] = GraphicsCard(graphicsCards[i]);
    }
}

GraphicsCardSet::GraphicsCardSet(const GraphicsCardSet &graphicsCardSet)
    : Part("Graphics Card Set"),  m_graphicsCards(new GraphicsCard[graphicsCardSet.m_numberOfGraphicsCards])
    , m_numberOfGraphicsCards(graphicsCardSet.m_numberOfGraphicsCards)
{
    for (int i = 0; i < m_numberOfGraphicsCards; ++i)
    {
        m_graphicsCards[i] = GraphicsCard(graphicsCardSet.m_graphicsCards[i]);
    }
}

GraphicsCardSet::~GraphicsCardSet()
{
    if (0 != m_graphicsCards && -1 != m_numberOfGraphicsCards)
    {
        delete[] m_graphicsCards;
    }
    m_graphicsCards = 0;
    m_numberOfGraphicsCards = -1;
}

std::string GraphicsCardSet::getPartInformation() const
{
    std::string partInformation("Graphics Cards: Number Of Cards: ");

    std::stringstream ss;
    ss << m_numberOfGraphicsCards;

    partInformation += ss.str();

    for (int i = 0; i < m_numberOfGraphicsCards; ++i)
    {

        ss.str("");
        ss.clear();
        ss << i+1;

        partInformation += "\nSlot " + ss.str() + ": " + m_graphicsCards[i].getPartInformation();
    }

    return partInformation;
}

GraphicsCard* GraphicsCardSet::getGraphicsCards() const
{
    return m_graphicsCards;
}

int GraphicsCardSet::getNumberOfGraphicsCards() const
{
    return m_numberOfGraphicsCards;
}
