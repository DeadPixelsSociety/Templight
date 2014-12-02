#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <TMPL_cLight.h>

// Constructor
TMPL_cLight::TMPL_cLight(void)
{
	this->raySegmentEx[0] = TMPL_cRaySegment();
	this->raySegmentEx[1] = TMPL_cRaySegment();
	this->raySegmentBase = NULL;
}

TMPL_cLight::TMPL_cLight(TMPL_cRaySegment raySegmentEx1, TMPL_cRaySegment raySegmentEx2, TMPL_cRaySegment* raySegmentBase)
{
	this->raySegmentEx[0] = raySegmentEx1;
	this->raySegmentEx[1] = raySegmentEx2;
	this->raySegmentBase = raySegmentBase;
}

TMPL_cLight::TMPL_cLight(TMPL_cLightSource source, float rayon, float xMin, float xMax, float yMin, float yMax)
{
	this->raySegmentBase = new TMPL_cRaySegment(source, xMin, xMax, yMin, yMax);

	TMPL_cPoint pEx0 = TMPL_cPoint(source.getVertex().getX() + rayon*cos(source.getAngle()+90), source.getVertex().getY() + rayon*sin(source.getAngle()+90));
	TMPL_cPoint pEx1 = TMPL_cPoint(source.getVertex().getX() + rayon*cos(source.getAngle()-90), source.getVertex().getY() + rayon*sin(source.getAngle()-90));

	this->raySegmentEx[0] = TMPL_cRaySegment(TMPL_cHalfLine(pEx0, source.getAngle()), xMin, xMax, yMin, yMax);
	this->raySegmentEx[1] = TMPL_cRaySegment(TMPL_cHalfLine(pEx1, source.getAngle()), xMin, xMax, yMin, yMax);
}

// Destructor
TMPL_cLight::~TMPL_cLight(void)
{}

// Get
TMPL_cRaySegment TMPL_cLight::getRaySegmentEx(int index)
{
    if(0!=index && 1!=index)
    {
        fprintf(stderr,"%d is not a valid index for a ray segment\n", index);
   	 	exit(1);
    }
	return this->raySegmentEx[index];
}

TMPL_cRaySegment* TMPL_cLight::getRaySegmentBase(void)
{
    return this->raySegmentBase;
}

// Method
void TMPL_cLight::intersectionWithPolygon(TMPL_cPolygon polygon)
{
	int i;
	for(i=0 ; i<2 ; i++)
	{
		this->raySegmentEx[i].setNonSourceVertex(this->raySegmentEx[i].intersectionWithPolygon(polygon));
	}
}

// World
void TMPL_cLight::render(sf::RenderWindow& window)
{
	sf::ConvexShape light;
	light.setPointCount(4);
	
	light.setPoint(0, sf::Vector2f(this->raySegmentEx[0].getSourceVertex().getX(), this->raySegmentEx[0].getSourceVertex().getY()));
	light.setPoint(1, sf::Vector2f(this->raySegmentEx[1].getSourceVertex().getX(), this->raySegmentEx[1].getSourceVertex().getY()));
	light.setPoint(2, sf::Vector2f(this->raySegmentEx[1].getNonSourceVertex().getX(), this->raySegmentEx[1].getNonSourceVertex().getY()));
	light.setPoint(3, sf::Vector2f(this->raySegmentEx[0].getNonSourceVertex().getX(), this->raySegmentEx[0].getNonSourceVertex().getY()));

    light.setFillColor(sf::Color::Yellow);

    window.draw(light);
}

