#include "profile.h"

Profile profile;

void Profile::addWheel(int wheelID) {
	wheelList.push_back(getWheel(wheelID));
	wheelNameList.push_back("");
	setWheelName(wheelNameList.size() - 1);
}

bool Profile::buyWheel(int wheelID) {
	if (getWheel(wheelID).getPrice() <= score) {
		wheelList.push_back(getWheel(wheelID));
		wheelNameList.push_back("");
		setWheelName(wheelNameList.size() - 1);
		score -= getWheel(wheelID).getPrice();

		return true;
	}

	return false;
}

void Profile::setWheelName(int index) {
	std::string tempString = std::to_string(wheelList[index].getCurrentHeightPercent() * 100.0);
	wheelNameList[index] = wheelList[index].getName() + " - " + tempString.substr(0, tempString.find_first_of('.') + 3) + "%";
}

void Profile::setAllWheelNames() {
	for (int x = 0; x < wheelNameList.size(); x++) {
		setWheelName(x);
	}
}

void Profile::setDeckName(int index) {
	std::string tempString = std::to_string(deckList[index].getCurrentLife()) + "/" + std::to_string(deckList[index].getLife());
	deckNameList[index] = deckList[index].getName() + " - " + tempString;
}

void Profile::setAllDeckNames() {
	for (int x = 0; x < deckNameList.size(); x++) {
		setDeckName(x);
	}
}

void Profile::addDeck(int deckID) {
	deckList.push_back(getDeck(deckID));
	deckNameList.push_back(getDeck(deckID).getName());
	setDeckName(deckNameList.size() - 1);
}

bool Profile::buyDeck(int deckID) {
	if (getDeck(deckID).getPrice() <= score) {
		deckList.push_back(getDeck(deckID));
		deckNameList.push_back(getDeck(deckID).getName());
		setDeckName(deckNameList.size() - 1);
		score -= getDeck(deckID).getPrice();

		return true;
	}

	return false;
}