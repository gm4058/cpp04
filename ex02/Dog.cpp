#include "Dog.hpp"
# include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark! bark!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}