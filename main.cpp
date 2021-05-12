#include "Drink.h"
#include "Coffee.h"
#include "Decorator.h"
#include "Americano.h"


int main() {
	Drink *coffee = new Americano(new Coffee);
	coffee->drinking();
	return 0;
}