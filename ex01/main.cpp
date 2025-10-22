#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Basic Leak Test ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // Dog와 Brain의 소멸자가 호출되어야 합니다.
    delete i; // Cat과 Brain의 소멸자가 호출되어야 합니다.
    std::cout << std::endl;


    std::cout << "--- Animal Array Test ---" << std::endl;
    const Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << std::endl;

    animals[0]->makeSound();
    animals[1]->makeSound();

    std::cout << std::endl;

    animals[2]->makeSound();
    animals[3]->makeSound();

    std::cout << std::endl;


    std::cout << "--- Deep Copy Test (Dog) ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I am the original dog!");

    std::cout << "* Creating a copy of the dog..." << std::endl;
    Dog copyDog = originalDog; // 복사 생성자 호출

    std::cout << "* Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "* Copied dog's idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "* Changing original dog's idea..." << std::endl;
    originalDog.getBrain()->setIdea(0, "My idea has changed!");

    std::cout << "* Original dog's new idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "* Copied dog's idea (should be unchanged): " << copyDog.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Assignment Operator Test (Cat) ---" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "I am cat1");
    Cat cat2;
    cat2.getBrain()->setIdea(0, "I am cat2");

    std::cout << "* Before assignment, cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    cat2 = cat1; // 할당 연산자 호출
    std::cout << "* After assignment, cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    std::cout << "* Changing cat1's idea..." << std::endl;
    cat1.getBrain()->setIdea(0, "cat1's idea changed");

    std::cout << "* cat1's new idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "* cat2's idea (should be unchanged): " << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "--- Destructors for local objects ---" << std::endl;
    return 0;
}