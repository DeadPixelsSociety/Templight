#include <TMPL_cPoint.h>

// Constructor
TMPL_cPoint::TMPL_cPoint(void)
{
	this->x = 0;
	this->y = 0;
}

TMPL_cPoint::TMPL_cPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}

// Destructor
TMPL_cPoint::~TMPL_cPoint(void)
{}

// Set
void TMPL_cPoint::setX(float x)
{
	this->x = x;
}

void TMPL_cPoint::setY(float y)
{
	this->y = y;
}

// Get
float TMPL_cPoint::getX(void)
{
	return this->x;
}

float TMPL_cPoint::getY(void)
{
	return this->y;
}

