#pragma once
#include "Drink.h"
class Decorator :
    public Drink
{
    private:
        Drink* base;
    public:
        Decorator(Drink* drink) {
            base = drink;
        }
        void drinking() {
            base->drinking();
        }
};

