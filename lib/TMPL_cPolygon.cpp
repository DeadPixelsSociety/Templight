#include <stdio.h>
#include <stdlib.h>

#include <TMPL_cPolygon.h>
#include <TMPL_cTriangle.h>

// Constructor
TMPL_cPolygon::TMPL_cPolygon(void)
{
    this->nbVertices = 0;
    this->verticesTab = NULL;
}

TMPL_cPolygon::TMPL_cPolygon(int size)
{
	if(size < 3)
	{
		fprintf(stderr,"A polygon must have more than 2 vertices\n");
		exit(1);
	}

    this->nbVertices = size;
    this->verticesTab = (TMPL_cPoint*) malloc(size * sizeof(TMPL_cPoint));

    int i;
    for(i=0 ; i<size ; i++)
    {
        this->verticesTab[i] = TMPL_cPoint();
    }
}

// Destructor
TMPL_cPolygon::~TMPL_cPolygon(void)
{}

// Set
void TMPL_cPolygon::setVertex(TMPL_cPoint vertex, int index)
{
	this->verticesTab[index] = vertex;
}

void TMPL_cPolygon::setNbVertices(int size)
{
	this->nbVertices = size;
}

// Get
TMPL_cPoint TMPL_cPolygon::getVertex(int index)
{
	return this->verticesTab[index];
}

int TMPL_cPolygon::getNbVertices(void)
{
	return this->nbVertices;
}

// Methods
TMPL_cPoint TMPL_cPolygon::computeCenterOfGravity(void)
{
    int i;
    float AverageX = 0;
    float AverageY = 0;
    for(i=0 ; i<this->nbVertices ; i++)
    {
        AverageX += this->verticesTab[i].getX();
        AverageY += this->verticesTab[i].getY();
    }
    AverageX /= nbVertices;
    AverageY /= nbVertices;

    TMPL_cPoint centerOfGravity = TMPL_cPoint(AverageX, AverageY);
    return centerOfGravity;
}

int TMPL_cPolygon::isPointInPolygon(TMPL_cPoint point)
{
	if(3 > nbVertices)
	{
		return 0;
	}

	// Triangle
	if(3 == nbVertices)
	{
		TMPL_cTriangle t = TMPL_cTriangle(verticesTab[0], verticesTab[1], verticesTab[2]);
		return t.isPointInTriangle(point);
	}

	// Rectangle
	if(4 == nbVertices)
	{
		TMPL_cTriangle t1 = TMPL_cTriangle(verticesTab[0], verticesTab[1], verticesTab[2]);
		TMPL_cTriangle t2 = TMPL_cTriangle(verticesTab[0], verticesTab[2], verticesTab[3]);
		return (t1.isPointInTriangle(point) || t2.isPointInTriangle(point));
	}

	TMPL_cPoint centerOfGravity = computeCenterOfGravity();

	int i;
	int isInTriangle = 0;
	TMPL_cTriangle t;
	for(i=0 ; i<this->nbVertices-1 ; i++)
	{
		t = TMPL_cTriangle(centerOfGravity, verticesTab[i], verticesTab[i+1]);
		isInTriangle = isInTriangle || t.isPointInTriangle(point);
	}

	t = TMPL_cTriangle(centerOfGravity, verticesTab[0], verticesTab[nbVertices-1]);
	isInTriangle = isInTriangle || t.isPointInTriangle(point);

	return isInTriangle;
}
