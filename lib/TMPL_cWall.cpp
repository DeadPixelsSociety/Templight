#include "TMPL_cWall.h"

// Constructor
TMPL_cWall::TMPL_cWall(void)
{}

// Destructor
TMPL_cWall::~TMPL_cWall(void)
{}

//World
void TMPL_cWall::render(sf::RenderWindow& window)
{
	sf::ConvexShape wall;
	wall.setPointCount(this->polygon.getNbVertices());
	
	int i;
	int iMax = this->polygon.getNbVertices();
	for(i=0 ; i<iMax ; i++)
	{
		wall.setPoint(i, sf::Vector2f(this->polygon.getVertex(i).getX(), this->polygon.getVertex(i).getY()));
	}

    wall.setFillColor(sf::Color::Red);

    window.draw(wall);
}
