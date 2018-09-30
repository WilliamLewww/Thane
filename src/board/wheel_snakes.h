#pragma once
#include "wheel.h"

class Snakes : public Wheel {
public:
	Snakes(float currentHeightPercent)
		:Wheel(48, 66, 75, LIP_ROUND, false) {

		this->currentHeightPercent = currentHeightPercent;
		setColor(255, 107, 95);
	};

	inline float getTraction() {
		float traction;
		return traction;
	};
};