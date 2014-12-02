#ifndef TMPL_C_LIGHT_H
#define TMPL_C_LIGHT_H

#include <game/Entity.h>
#include <TMPL_cRaySegment.h>
#include <TMPL_cLightSource.h>

class TMPL_cLight : public game::Entity
{
public:
    // Constructor
    TMPL_cLight(void);
    TMPL_cLight(TMPL_cRaySegment raySegmentEx1, TMPL_cRaySegment raySegmentEx2, TMPL_cRaySegment* raySegmentBase);
	TMPL_cLight(TMPL_cLightSource source, float rayon, float xMin, float xMax, float yMin, float yMax);

    // Destructor
    ~TMPL_cLight(void);

    // Get
    TMPL_cRaySegment getRaySegmentEx(int index);
    TMPL_cRaySegment* getRaySegmentBase(void);

	// Method
	void intersectionWithPolygon(TMPL_cPolygon polygon);

	// World
	void render(sf::RenderWindow& window);
	
private:
	TMPL_cRaySegment raySegmentEx[2];	// 2 extrémintés
    TMPL_cRaySegment* raySegmentBase;	// base

};

#endif
