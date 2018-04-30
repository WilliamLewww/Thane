#pragma once
#include "core\configuration.h"
#include "core\gui.h"
#include "hud\hud.h"
#include "world.h"
#include "board.h"
#include "camera.h"

class Joiner {
private:
	World world;
	Board board;
	HUD hud;

	int speedZone = 0;
public:
	void initialize();
	void draw();
	void update(int elapsedTime);
};

extern Joiner joiner;