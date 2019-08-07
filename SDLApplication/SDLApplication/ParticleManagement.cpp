#include "pch.h"
#include "ParticleManagement.h"

namespace application
{
ParticleManagement::ParticleManagement(): lastTime(0)
{
	m_pParticles = new Particles[NPARTICLES];
}

ParticleManagement::~ParticleManagement()
{
	delete[] m_pParticles;
}

void ParticleManagement::update(int elapsed)
{
	int interval = elapsed - lastTime;

	for (int i = 0; i < ParticleManagement::NPARTICLES; i++)
	{
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}
}