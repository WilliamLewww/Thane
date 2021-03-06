#pragma once
#include <ctime>
#include "core\configuration.h"
#include "core\gui.h"
#include "core\file.h"
#include "core\timer.h"
#include "network\n_joiner.h"
#include "hud\hud.h"
#include "effects\particle_manager.h"
#include "effects\screen_filter.h"
#include "environment\squirrel.h"
#include "board\board.h"
#include "track\track_editor.h"
#include "world.h"
#include "camera.h"

class Joiner {
private:	
	World world;
	Board board;
	HUD hud;

	TrackEditor trackEditor;

	NJoiner nJoiner;
	float netTimer = 0;

	int checkpointCount = 15;
	int tempHUDCheckpoint = 0;

	int speedZone = 0, trackDirection = 0;

	bool initialOpen = true;

	bool isPaused = false;
	bool isCrashed = false;
	bool allowRestartAfterCrash = false;
	bool isKeyStart = false;
	bool allowKeyStart = false;

	bool stillShowBoard = false;
	
	bool showNetworkMenu = false;
	bool canShowMainMenu = false;
	bool showMainMenu = true;
	bool showHUDEdit, showTrackEdit, showBoardEdit;
	bool showSplitsHUD = true, showKeyPressHUD = false, showMinimap = true;

	bool showInventory, showSessionStats = true, showLeaderboards = false, showWheelStats = true;
	bool randomTrackSeed = false;
	bool toggleRain = false;
	bool isRaining = false;

	bool devMode = false;

	int selectedRun = 0, leaderboardSelectedRun = 0;
	int deckID, wheelID;
	int selectedDeck = 0, selectedWheel = 0;
	int trackGenerationStyle;

	int tutorialState = -1;
	int forceEnd = 0;

	void handleConfig();

	void pushConfigurations();
	void pushConfigurationsRain();

	void hideEditWindows();

	void handleDevMode();
	void handleStartInput();

	void handleBoardCollision();

	void handleMainMenu();
	void handleLeaderboards();
	void handleStats();
	void handleHUDEdit();
	void handleTrackEdit();
	void handleBoardEdit();
	void handleInventory();
	void handleNetworkMenu();

	bool canChangeMode = false;
	void changeMode();
	void handleTrackMode();
public:
	int seed, rainSeed;

	void reset(bool isCrash, bool crashedParticles);
	void resetFull();

	void initialize();
	void initializeWorld();
	void draw();
	void update();
};

extern Joiner joiner;