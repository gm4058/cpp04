#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
    std::cout << "Brain setIdea called" << std::endl;
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "";
}