#pragma once
#include "deck.h"

class Switchblade : public Deck {
public:
	Switchblade() 
		:Deck("Landyachtz Switchblade", 40, 10) { 

		setColor(103, 156, 192);
		this->price = 225;
	};
};

class RumRunnerCarbon : public Deck {
public:
	RumRunnerCarbon() 
		:Deck("Moonshine Rum Runner Carbon", 36, 9) { 

		setColor(155, 24, 24);
		this->price = 200;
	};
};

class WolfsharkMini : public Deck {
public:
	WolfsharkMini() 
		:Deck("Landyachtz Wolfshark Mini", 32, 10) { 

		setColor(125, 104, 221);
		this->price = 300;
	};
};