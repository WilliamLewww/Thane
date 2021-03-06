#include "track.h"

void Track::initialize() {
	railList.push_back(std::vector<Vector2>());
	railList.push_back(std::vector<Vector2>());
}

void Track::draw(int generationStyle, bool drawDetails = true) {
	road.generate(railList, speedZones, visibleRange.x, visibleRange.y);
	road.draw(visibleRange.x);

	if (drawDetails == true) {
		switch (generationStyle) {
			case 2:
			case 0:
				for (std::vector<Vector2> segment : railList) {
					drawing.drawLineStrip(std::vector<Vector2>(segment.begin() + visibleRange.x, segment.begin() + visibleRange.y), rockyColor);
				}
				break;
			case 1:
				drawing.drawLineStrip(getVisibleRail(0), 10, sideColor, 100);
				drawing.drawLineStrip(getVisibleRail(1), -10, sideColor, 100);

				drawing.drawLineStrip(getVisibleRail(0), getVisibleRail(1), -2, centerColor, 75);
				drawing.drawLineStrip(getVisibleRail(0), getVisibleRail(1), 2, centerColor, 75);
				break;
		}

		// for (Vector2 speedZone : speedZones) {
		// 	if (railList[0][speedZone.x].x < camera.getBoundaryRight() && railList[0][speedZone.x].x > camera.getBoundaryLeft()) {
		// 		drawing.drawLine(Vector2(railList[0][speedZone.x].x, railList[0][speedZone.x].y),
		// 				 Vector2(railList[1][speedZone.x].x, railList[1][speedZone.x].y),
		// 				 speedZoneColor(speedZone.y), 100);
		// 	}
		// }
	}
}

void Track::generateTrackDirection() {
	for (int x = 0; x < railList[0].size() - 1; x += 2) {
		trackDirection.push_back(Vector2(railList[0][x].x, -atan((railList[0][x + 2].y - railList[0][x].y) / (railList[0][x + 2].x - railList[0][x].x)) * (180 / drawing.PI)));
	}
}

int* Track::speedZoneColor(int speed) {
	int* tempColor = (int*)malloc(3 * sizeof(int));
	tempColor[0] = ((double)speed / 50) * 255;
	tempColor[1] = ((50 - (double)speed) / 50) * 255;
	tempColor[2] = 0;

	return tempColor;
}

void Track::resetVisibleRange() { 
	visibleRange = Vector2(0,0); road.clear(); 
}

void Track::updateVisibleRange() {
	for (int x = visibleRange.x; x < railList[0].size(); x++) {
		if (railList[0][x].x < camera.getBoundaryLeft()) { visibleRange.x += 1; }
		if (railList[0][x].x < camera.getBoundaryRight()) { visibleRange.y = x; }
		else { break; }
	}
}

std::vector<Vector2> Track::getVisibleRail(int side) {
	if (visibleRange.x == 0) {
		return std::vector<Vector2>(railList[side].begin() + visibleRange.x + 1, railList[side].begin() + visibleRange.y);
	}
	return std::vector<Vector2>(railList[side].begin() + visibleRange.x, railList[side].begin() + visibleRange.y);
};

void Track::addSpeedZone(int node, int speed) {
	speedZones.push_back(Vector2(node, speed));
}

void Track::addVertex(Vector2 position, int spacing) {
	railList[0].push_back(Vector2(position.x, position.y));
	railList[1].push_back(Vector2(position.x, position.y + spacing));
}

void Track::addVertexSingle(int index, Vector2 position) {
	railList[index].push_back(Vector2(position.x, position.y));
}

void Track::addVertexRelative(int topY, int spacingX, int bottomY) {
	railList[0].push_back(Vector2(railList[0][railList[0].size() - 1].x + spacingX, railList[0][railList[0].size() - 1].y + topY));
	railList[1].push_back(Vector2(railList[1][railList[1].size() - 1].x + spacingX, railList[1][railList[1].size() - 1].y + bottomY));
}

void Track::addVertexRelativeTop(int index, int topY, int spacingX) {
	railList[index].push_back(Vector2(railList[index][railList[index].size() - 1].x + spacingX, railList[index][railList[index].size() - 1].y + topY));
}

void Track::addVertexRelativeBottom(int index, int slope) {
	railList[index].push_back(Vector2(railList[0][railList[index].size() - 1].x, railList[0][railList[index].size() - 1].y));
}

void Track::addVertexComp(int topY, int spacingX) {
	railList[0].push_back(Vector2(railList[0][railList[0].size() - 1].x + spacingX, railList[0][railList[0].size() - 1].y + topY));
	railList[1].push_back(Vector2(railList[1][railList[1].size() - 1].x + spacingX, railList[1][railList[1].size() - 1].y + topY));
}

void Track::addVertexComp(int topY, int spacingX, int offsetY, int limitTop, int limitBottom) {
	railList[0].push_back(Vector2(railList[0][railList[0].size() - 1].x + spacingX, railList[0][railList[0].size() - 1].y + topY));
	railList[1].push_back(Vector2(railList[1][railList[1].size() - 1].x + spacingX, railList[0][railList[0].size() - 1].y + offsetY + (rand() % (limitBottom - limitTop + 1) - limitTop)));
}