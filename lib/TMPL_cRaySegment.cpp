#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <TMPL_cRaySegment.h>
#include <TMPL_cCartesianEquation.h>

// Constructor
TMPL_cRaySegment::TMPL_cRaySegment(void)
: TMPL_cSegment()
{
	this->source = 0;
}

TMPL_cRaySegment::TMPL_cRaySegment(TMPL_cPoint vertex1, TMPL_cPoint vertex2)
: TMPL_cSegment(vertex1, vertex2)
{
	this->source = 0;
	this->ordonnerVertex();
}

TMPL_cRaySegment::TMPL_cRaySegment(TMPL_cHalfLine halfLine, float xMin, float xMax, float yMin, float yMax)
{
	this->vertex[0] = halfLine.getVertex();

	TMPL_cCartesianEquation eq = TMPL_cCartesianEquation(halfLine);
	TMPL_cPoint p[4];
	p[0] = TMPL_cPoint(xMin, eq.getImage(xMin));
	p[1] = TMPL_cPoint(xMax, eq.getImage(xMax));
	p[2] = TMPL_cPoint(eq.getAntecedent(yMin), yMin);
	p[3] = TMPL_cPoint(eq.getAntecedent(yMax), yMax);

	int i;
	for(i=0 ; i<4 ; i++)
	{
		if(halfLine.pointAppartient(p[i]))
		{
			this->vertex[1] = p[i];
			break;
		}
	}

	this->ordonnerVertex();
}

// Destructor
TMPL_cRaySegment::~TMPL_cRaySegment(void)
{}

// Set 
void TMPL_cRaySegment::setNonSourceVertex(TMPL_cPoint vertex)
{
	setVertex(vertex, 1-this->source);
}

// Get
TMPL_cPoint TMPL_cRaySegment::getSourceVertex(void)
{
	return this->getVertex(this->source);
}

TMPL_cPoint TMPL_cRaySegment::getNonSourceVertex(void)
{
	return this->getVertex(1 - this->source);
}

// Methods
void TMPL_cRaySegment::ordonnerVertex(void)
{
	if(this->vertex[0].getX()>this->vertex[1].getX())
	{
		this->source = 1;
		TMPL_cPoint pAux = TMPL_cPoint(this->vertex[0].getX(), this->vertex[0].getY());
		this->vertex[0] = TMPL_cPoint(this->vertex[1].getX(), this->vertex[1].getY());
		this->vertex[1] = pAux;
	}
}

float TMPL_cRaySegment::computeAngle()
{
	if(this->vertex[1].getX() == this->vertex[0].getX())
	{
		if(this->vertex[this->source].getY() < this->vertex[1-this->source].getY())
		{
			return 90.;
		}
		return 270.;	
	}

	float rapport = atan( (this->vertex[1].getY() - this->vertex[0].getY()) / (this->vertex[1].getX() - this->vertex[0].getX()) );

	if(this->source)
	{
		rapport += 180.;
	}
	return rapport;
}

TMPL_cPoint TMPL_cRaySegment::intersectionWithPolygon(TMPL_cPolygon polygon)
{
	int i;
	TMPL_cPoint pointArrive = this->vertex[1-this->source];
	TMPL_cPoint pointIntersection;
	TMPL_cSegment segmentPolygon, segmentRayon, segmentArrive;

	int nbVertices = polygon.getNbVertices();
	for(i=0 ; i<nbVertices ; i++)
	{
		segmentPolygon = TMPL_cSegment(polygon.getVertex(i), polygon.getVertex((i+1)%nbVertices));
		if(this->haveIntersectionWithSegment(segmentPolygon))
		{
			pointIntersection = this->intersectionPointWithSegment(segmentPolygon);
			segmentRayon = TMPL_cSegment(this->getVertex(this->source), pointIntersection);
			
			segmentArrive = TMPL_cSegment(this->getVertex(this->source), pointArrive);
			if(segmentRayon.computeLength() < segmentArrive.computeLength())
			{
				pointArrive = pointIntersection;
			}
		}
	}
	return pointArrive;
}

