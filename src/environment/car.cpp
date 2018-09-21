#include "car.h"

Car::Car(Vector2 position, int width, int height, int railIndex, int spacing) {
	polygon.setPosition(position);
	polygon.setSize(width, height);

	polygon.setAngle(180);

	this->spacing = spacing;

	currentRailIndex = railIndex;
}

void Car::setPathing(std::vector<Vector2> railList) {
	float lowestY = railList[currentRailIndex].y;
	int lowestIndex = currentRailIndex;

	if (polygon.getCenter().x >= currentRail.x && currentRailIndex < railList.size() - 1 - spacing) {
		for (int x = currentRailIndex; x < currentRailIndex + spacing; x++) {
			if (lowestY > railList[x].y) {
				lowestY = railList[x].y;
				lowestIndex = x;
			}
		}

		if (lowestIndex == currentRailIndex) {
			currentRailIndex += spacing + 1;
			currentRail = Vector2(railList[currentRailIndex].x, railList[currentRailIndex].y - 100);
		}
		else {
			currentRailIndex = lowestIndex;
			currentRail = Vector2(railList[currentRailIndex].x, lowestY - 100);
		}
	}
}

void Car::update(float elapsedTimeSeconds) {
	directionVector = Vector2((float)cos((-polygon.getAngle() * M_PI) / 180), sin((-polygon.getAngle() * M_PI) / 180));
	directionVector.normalize();
	distanceToNode = (currentRail.x - polygon.getCenter().x) / cos((-polygon.getAngle() * M_PI) / 180);

	projectedPoint = polygon.getCenter() + (directionVector * distanceToNode);

	if (projectedPoint.y <= currentRail.y + 5) {
		polygon.addAngle(-turnSpeed * elapsedTimeSeconds);
	}

	if (projectedPoint.y >= currentRail.y - 5) {
		polygon.addAngle(turnSpeed * elapsedTimeSeconds);
	}

	float difference = abs(currentRail.y - projectedPoint.y);

	if (difference > 15) {
		if (speed > 0) {
			if (speed - ((speedReduction + (difference / differenceMagnitude)) * elapsedTimeSeconds) < speedMin) {
				speed = speedMin;
			}
			else {
				speed -= (speedReduction + (difference / differenceMagnitude)) * elapsedTimeSeconds;
			}
		}
	}
	else {
		if (speed < speedMax) {
			if (speed + ((speedReduction + (difference / differenceMagnitude)) * elapsedTimeSeconds) > speedMax) {
				speed = speedMax;
			}
			else {
				speed += (speedReduction + (difference / differenceMagnitude)) * elapsedTimeSeconds;
			}
		}
	}

	polygon.setPosition(polygon.getPosition() - ((directionVector * elapsedTimeSeconds) * speed));
}

void Car::draw() {
	drawing.drawRect(polygon.getPosition(), polygon.getWidth(), polygon.getHeight(), polygon.getAngle(), color);
	drawing.drawLine(polygon.getCenter(), projectedPoint);
}