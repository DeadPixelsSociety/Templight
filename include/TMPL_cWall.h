#ifndef TMPL_C_WALL_H
#define TMPL_C_WALL_H

#include "TMPL_cObstacle.h"
#include "TMPL_cPolygon.h"

class TMPL_cWall : public TMPL_cObstacle
{
public:
	// Constructor
	TMPL_cWall(void);

    // Destructor
	~TMPL_cWall(void);

	// World
	void render(sf::RenderWindow& window);

private:
	TMPL_cPolygon polygon;
};

#endif
