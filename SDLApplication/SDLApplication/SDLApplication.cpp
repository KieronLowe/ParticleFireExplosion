#include "pch.h"
#include <SDL.h>
#include "Screen.h"
#include "ParticleManagement.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace application;

#undef main

int main()
{
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false)
	{
		std::cout << "Error initialising SDL." << std::endl;
	}

	ParticleManagement particlemanagement;

	bool quit = false;

	while (true)
	{
		int elapsed = SDL_GetTicks();
		
		particlemanagement.update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particles * const pParticles = particlemanagement.getparticles();
		for (int i = 0; i < ParticleManagement::NPARTICLES; i++)
		{
			Particles particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		screen.update();

		if (screen.processEvent() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}


