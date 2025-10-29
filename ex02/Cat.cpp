#include "Cat.hpp"
# include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow! meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}