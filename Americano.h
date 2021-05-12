#pragma once
#include "Decorator.h"
class Americano :
    public Decorator
{
    public:
        Americano(Drink* base) : Decorator(base) { ; }
        void drinking() {
            Decorator::drinking();
            std::cout << " Americano";
        }
};

