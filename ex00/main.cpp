#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== Constructors ==========" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n========== getType Test ==========" << std::endl;
    std::cout << meta->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;


    std::cout << "\n========== makeSound Test ==========" << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound();

    std::cout << "\n========== Destructors ==========" << std::endl;
    delete meta;
    delete j;
    delete i;

    return 0;
}