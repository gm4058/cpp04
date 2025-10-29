#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>


int main()
{
    {
        std::cout << "------------- Basic Leak Test -------------" << std::endl;

        std::cout << "** Constructor call **" << std::endl;
        
        std::cout << "[j]" << std::endl;
        const Animal* j = new Dog();
        std::cout << std::endl;

        std::cout << "[i]" << std::endl;
        const Animal* i = new Cat();
        std::cout << std::endl;



        std::cout <<"\n** Destructor call **" << std::endl;
        std::cout << "[j]" << std::endl;
        delete j;
        std::cout << std::endl;

        std::cout << "[i]" << std::endl;
        delete i;
        std::cout << std::endl;
    }

    {
        std::cout << "\n\n------------- Animal Array Test -------------" << std::endl;

        std::cout << "** Constructor call **" << std::endl;
        const Animal* animals[4];

        std::cout << "[animals[0]]" << std::endl;
        animals[0] = new Dog();
        std::cout << std::endl;

        std::cout << "[animals[1]]" << std::endl;
        animals[1] = new Dog();
        std::cout << std::endl;

        std::cout << "[animals[2]]" << std::endl;
        animals[2] = new Cat();
        std::cout << std::endl;

        std::cout << "[animals[3]]" << std::endl;
        animals[3] = new Cat();
        std::cout << std::endl;



        std::cout << "\n** virtual method(makeSound) call from Dog obj **" << std::endl;

        animals[0]->makeSound();
        animals[1]->makeSound();

        std::cout << "\n **virtual method(makeSound) call from Cat obj **" << std::endl;

        animals[2]->makeSound();
        animals[3]->makeSound();




        std::cout <<"\n\n**Destructor call**" << std::endl;

        for (int i = 0; i < 4; i++)
        {
            std::cout << "[animals[" << i << "]]" << std::endl;
            delete animals[i];
            std::cout << std::endl;
        }
    }


    {
        std::cout << "\n\n------------- Deep Copy Test (Dog) -------------" << std::endl;

        std::cout << "** originalDog Constructor call **" << std::endl;

        std::cout << "[originalDog]" << std::endl;
        Dog originalDog;

        std::cout << "\n** originalDog setIdea **" << std::endl;
        originalDog.getBrain()->setIdea(0, "I am the original dog!");



        std::cout << "\n** Creating copyDog **" << std::endl;
        Dog copyDog = originalDog;
        std::cout << std::endl;



        std::cout << "# Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "# Copied dog's idea: " << copyDog.getBrain()->getIdea(0) << std::endl << std::endl;

        std::cout << "# Changing original dog's idea..." << std::endl;
        originalDog.getBrain()->setIdea(0, "My idea has changed!");
        std::cout << std::endl;

        std::cout << "# Original dog's new idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "# Copied dog's idea (should be unchanged): " << copyDog.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;


        std::cout <<"\n** Destructor call **" << std::endl;
    }


    {
        std::cout << "\n\n------------- Assignment Operator Test (Cat) -------------" << std::endl;

        std::cout << "** Constructor call **" << std::endl;

        std::cout << "[cat1]" << std::endl;
        Cat cat1;
        std::cout << std::endl;

        std::cout << "[cat2]" << std::endl;
        Cat cat2;
        std::cout << std::endl;



        std::cout << "\n** cat objs setIdea **" << std::endl;

        std::cout << "# cat1 setIdea" << std::endl;
        cat1.getBrain()->setIdea(0, "I am cat1");
        std::cout << std::endl;

        std::cout << "# cat2 setIdea" << std::endl;
        cat2.getBrain()->setIdea(0, "I am cat2");
        std::cout << std::endl << std::endl;



        std::cout << "# Before assignment, cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;

        std::cout << "\n** Copying **" << std::endl;
        cat2 = cat1;
        std::cout << std::endl;

        std::cout << "# After assignment, cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl << std::endl;



        std::cout << "# Changing cat1's idea..." << std::endl;
        cat1.getBrain()->setIdea(0, "cat1's idea changed");
        std::cout << std::endl;



        std::cout << "# cat1's new idea: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "# cat2's idea (should be unchanged): " << cat2.getBrain()->getIdea(0) << std::endl;
        std::cout << std::endl;



        std::cout <<"\n** Destructor call **" << std::endl;
    }

    return 0;
}