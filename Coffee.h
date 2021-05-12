#pragma once
#include "Drink.h"
class Coffee :
    public Drink
{
    public:
        void drinking() {
            std::cout << "drinking";
        }
};

