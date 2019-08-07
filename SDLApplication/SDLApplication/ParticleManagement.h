#include "Particles.h"

#pragma once
namespace application 
{
class ParticleManagement
{
public:
	const static int NPARTICLES = 5000;

private:
	Particles * m_pParticles;
	int lastTime;

public:
	ParticleManagement();
	~ParticleManagement();

	void update(int elapsed);

	const Particles *const getparticles() { return m_pParticles; };

};
}


