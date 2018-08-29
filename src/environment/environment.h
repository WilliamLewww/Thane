#pragma once
#include <vector>
#include <stdlib.h>
#include "tree.h"
#include "..\camera.h"

class Environment {
private:
	Vector2 visibleTreeRange;
	std::vector<std::vector<Tree>> treeList;
public:
	void resetVisibleRange();
	void generateTrees(std::vector<Vector2> rail, int concentration, int offsetY, int scaleMin, int scaleMax);
	void draw();
};