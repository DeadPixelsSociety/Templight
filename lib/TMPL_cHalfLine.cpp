#include <math.h>

#include <TMPL_cHalfLine.h>
#include <TMPL_cCartesianEquation.h>

// Constructor
TMPL_cHalfLine::TMPL_cHalfLine(void)
{
	this->vertex = TMPL_cPoint();
	this->angle = 0;
}

TMPL_cHalfLine::TMPL_cHalfLine(TMPL_cPoint vertex, float angle)
{
	this->vertex = vertex;
    this->angle = angle;
}

// Destructor
TMPL_cHalfLine::~TMPL_cHalfLine(void)
{}

// Get
float TMPL_cHalfLine::getAngle(void)
{
	return this->angle;
}

TMPL_cPoint TMPL_cHalfLine::getVertex(void)
{
	return this->vertex;
}

// Methods
TMPL_cPoint TMPL_cHalfLine::intersectionPointWithSegment(TMPL_cSegment segment)
{
    TMPL_cCartesianEquation cartEqua1 = TMPL_cCartesianEquation((*this));
    TMPL_cCartesianEquation cartEqua2 = TMPL_cCartesianEquation(segment);

    TMPL_cPoint intersection = cartEqua1.intersectionPoint(cartEqua2);

    return intersection;
}

int TMPL_cHalfLine::pointAppartient(TMPL_cPoint point)
{
	if(this->angle>=90 && this->angle<=270 && point.getX()>this->vertex.getX())
	{
		return 0;
	}

	if(this->angle>=0 && this->angle<=180 && point.getY()<this->vertex.getY())
	{
		return 0;
	}
	return 1;
}
