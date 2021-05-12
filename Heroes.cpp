#include "Heroes.h"

Murmillo::~Murmillo() {
	std::cout << "I was Murmillo!\n";
}

std::string Murmillo::fight() {
	return "Murmillo: ready to fight!\n";
}

Thracian::~Thracian() {
	std::cout << "Thracian: Goodness gracious!\n";
}

std::string Thracian::fight() {
	return "The Thracian has arrived!\n";
}

Bestiarii::~Bestiarii() {
	std::cout << "Bestiarii: I'm so sorry!\n";
}

std::string Bestiarii::fight() {
	return "Bestiarii: Not backing down\n";
}

Warrior* HeroFactory::createHero(int typeOfHero) {
	Warrior* newWarrior;;
	EquipmentBuilder* equip;

	switch (typeOfHero) {
		case 1: {
			newWarrior = new Murmillo();
			break;
		}
		case 2: {
			newWarrior = new Thracian();
			break;
		}

		case 3: {
			newWarrior = new Bestiarii();
			break;
		}
		default: {
			std::cout << "Got invalid input! Try to change something.\n";
			return NULL;
		}
	}

	return newWarrior;
}

EnemyHero& EnemyHero::instance() {
	static EnemyHero enemyHero;
	return enemyHero;
}

std::string EnemyHero::fight(Warrior* Warrior) {
	return "Enemy hero attacks" + Warrior->fight();
}

Equipment* EquipmentBuilder::reset() {
	this->equipment = new Equipment();
	return equipment;
}

void EquipmentBuilder::setUsingAxes(bool value) {
	equipment->isUsingAxes = value;
}

void EquipmentBuilder::setUsingSwords(bool value) {
	equipment->isUsingSwords = value;
}

void EquipmentBuilder::setUsingBows(bool value) {
	equipment->isUsingBows = value;
}

void EquipmentBuilder::setTypeOfArmor(std::string value) {
	equipment->typeOfArmor = value;
}

void EquipmentBuilder::setTypeOfHelmet(std::string value) {
	equipment->typeOfHelmet = value;
}

void EquipmentBuilder::setTypeOfBoots(std::string value) {
	equipment->typeOfBoots = value;
}

void Director::setBuilder(EquipmentBuilder* builder) {
	this->builder = builder;
}

void Director::createMurmilloEquipment(Warrior* warrior) {
	this->builder->reset();
	this->builder->setUsingSwords(true);
	this->builder->setTypeOfArmor("Chainmail Plate\n");
	this->builder->setTypeOfBoots("Ellegant Boots\n");
	this->builder->setTypeOfHelmet("Bone Helmet\n");
	warrior->equipment = this->builder->equipment
}

void Director::showEquipment(Warrior* warrior) {
	if (warrior->equipment->isUsingAxes) {
		std::cout << "Axes +\n";
	}
	else if (warrior->equipment->isUsingSwords) {
		std::cout << "Swords +\n";
	}
	else if (warrior->equipment->isUsingBows) {
		std::cout << "Bows +\n";
	}
	std::cout << warrior->equipment->typeOfArmor;
	std::cout << warrior->equipment->typeOfBoots;
	std::cout << warrior->equipment->typeOfHelmet;
}



void clientCode(Director& director, Warrior* warrior) {
	EquipmentBuilder* firstBuilder = new EquipmentBuilder();
	director.setBuilder(firstBuilder);
	std::cout << "Creating of Murmillo hero...\n";
	director.createMurmilloEquipment(warrior);
	director.showEquipment(warrior);
}

int main() {
	HeroFactory* MainFactory = new HeroFactory();
	Director* MainDirector = new Director();
	clientCode(*MainDirector, MainFactory->createHero(1));
}


