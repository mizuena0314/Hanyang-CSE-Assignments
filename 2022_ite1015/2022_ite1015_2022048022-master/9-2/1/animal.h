#pragma once
#include <string>

class Animal{
    public:
        Animal(std::string _name, int _age);
        virtual ~Animal();

        virtual void printInfo(){};
    protected:
        std::string name;
        int age;
};

class Cat: public Animal{
    public:
        Cat(std::string _name, int _age, std::string _favoriteToy);
        virtual ~Cat();

        virtual void printInfo();
    private:
        std::string favoriteToy;
};

class Zebra: public Animal{
    public:
        Zebra(std::string _name, int _age, int _numStripes);
        virtual ~Zebra();

        virtual void printInfo();
    private:
        int numStripes;
};

