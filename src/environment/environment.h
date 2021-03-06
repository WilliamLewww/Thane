#pragma once
#include <vector>
#include <stdlib.h>
#include "..\effects\screen_filter.h"
#include "..\core\timer.h"
#include "..\camera.h"
#include "tree.h"
#include "squirrel.h"
#include "gravel.h"
#include "guard_rail.h"
#include "car.h"
#include "bike.h"
#include "pinecone.h"
#include "rain.h"
#include "boulder.h"
#include "ocean.h"

class Environment {
private:
	Ocean ocean;

	std::vector<GuardRail> guardRailList;
	std::vector<std::vector<Tree>> treeList;
	std::vector<Boulder> boulderList;
	
	Vector2 visibleGuardRailRange;
	Vector2 visibleTreeRange;
	Vector2 visibleSquirrelRange;
	Vector2 visiblePineconeRange;
	Vector2 visibleBoulderRange;

	float elapsedTimeSeconds;
public:
	Rain rain;
	Gravel gravel;
	std::vector<Car> carList;
	std::vector<Bike> bikeList;
	std::vector<Squirrel> squirrelList;
	std::vector<Pinecone> pineconeList;
	
	void resetVisibleRange();

	void generateWaves();
	void generateRain(std::vector<Vector2> rail, int concentration);
	void generateCars(std::vector<Vector2> rail, int count);
	void generateBikes(std::vector<Vector2> rail, int count, bool isLeft);
	void generateGuardRails(std::vector<Vector2> rail, int spacing, int chainMin, int chainMax, int concentration);
	void generateGravel(std::vector<std::vector<Vector2>> rail, int concentration);
	void generatePinecones(std::vector<Vector2> rail, int concentration, int scaleMin, int scaleMax);
	void generateTrees(std::vector<Vector2> rail, int concentration, int offsetY, int scaleMin, int scaleMax);
	void generateSquirrels(std::vector<std::vector<Vector2>> rail, int concentration, int scaleMin, int scaleMax);
	void generateBoulders(std::vector<Vector2> rail, int concentration);

	void update(std::vector<std::vector<Vector2>> rail);
	void draw();
	void drawUnderMountain();
	void drawStatic();
	void drawStaticBackground();
};