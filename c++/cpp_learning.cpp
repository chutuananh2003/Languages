
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    virtual void makeSound() const {
        std::cout << "The animal makes a sound.\n";
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    void makeSound() const override {
        std::cout << "The dog barks.\n";
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}

    void makeSound() const override {
        std::cout << "The cat meows.\n";
    }
};

int main() {
    Animal* animal1 = new Animal("Generic Animal");
    Animal* animal2 = new Dog("Fido");
    Animal* animal3 = new Cat("Whiskers");

    animal1->makeSound();
    animal2->makeSound();
    animal3->makeSound();

    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}
