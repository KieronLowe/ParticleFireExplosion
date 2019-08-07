#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#pragma once
namespace application
{
struct Particles
{
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particles();
	~Particles();
	void update(int interval);
};
}

