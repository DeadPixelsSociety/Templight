#include <game/World.h>

#include "config.h"

#include <TMPL_cLight.h>
#include <TMPL_cWall.h>

int main()
{
	// initialize
	game::World world;
	sf::RenderWindow window(sf::VideoMode(640, 480), "Templight (version " GAME_VERSION ")");
	window.setKeyRepeatEnabled(false);

	//TMPL_cPoint vertex1 = TMPL_cPoint(100.,200.);
	
	//TMPL_cLightSource lSource1 = TMPL_cLightSource(vertex1, 90);

	

	// load resources

	// add entities

	//world.addEntity(&light, game::Memory::FROM_STACK);

	// main loop
	sf::Clock clock;
	while(window.isOpen())
	{
		// input
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
		  	}
			else 
			{
				if(event.type == sf::Event::KeyPressed)
				{
		    		switch (event.key.code)
					{
		     			case sf::Keyboard::Escape:
		       				window.close();
		       			break;

		      			default:
		        		break;
		    		}
		  		}
			}
		}

		// update
		sf::Time elapsed = clock.restart();
		world.update(elapsed.asSeconds());

		// render
		window.clear(sf::Color::White);
		world.render(window);
		window.display();
  }

  return 0;
}
