#pragma once
#include <string>
#include <iostream>

class Equipment {
public:
	bool isUsingAxes;
	bool isUsingSwords;
	bool isUsingBows;
	std::string typeOfArmor;
	std::string typeOfHelmet;
	std::string typeOfBoots;

};

class Warrior {
	public:
		Equipment* equipment;
		virtual std::string fight() = 0;
};

class Murmillo : public Warrior {
	std::string fight();
	~Murmillo();
};


class Thracian : public Warrior {
	std::string fight();
	~Thracian();
};

class Bestiarii : public Warrior {
	std::string fight();
	~Bestiarii();
};


class HeroFactory {
	public:
		static Warrior* createHero(int typeOfHero);
};


class EnemyHero {
	EnemyHero() {};
	EnemyHero(const EnemyHero&) = delete;
	EnemyHero& operator=(const EnemyHero&) = delete;
	EnemyHero& instance();
	std::string fight(Warrior* Warrior);
};

class AbstractBuilder {
	public:
		virtual Equipment* reset() = 0;
		virtual void setUsingAxes(bool value) = 0;
		virtual void setUsingSwords(bool value) = 0;
		virtual void setUsingBows(bool value) = 0;
		virtual void setTypeOfArmor(std::string value) = 0;
		virtual void setTypeOfHelmet(std::string value) = 0;
		virtual void setTypeOfBoots(std::string value) = 0;
};

class EquipmentBuilder : public AbstractBuilder {
	public:
		Equipment* equipment;
		Equipment* reset();
		void setUsingAxes(bool value);
		void setUsingSwords(bool value);
		void setUsingBows(bool value);
		void setTypeOfArmor(std::string value);
		void setTypeOfHelmet(std::string value);
		void setTypeOfBoots(std::string value);
};

class Director{
	private:
		EquipmentBuilder* builder;
	public:
		void setBuilder(EquipmentBuilder* builder);

		void createMurmilloEquipment(Warrior* warrior);
		void showEquipment(Warrior* warrior);
};


