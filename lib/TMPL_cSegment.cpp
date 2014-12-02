#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <TMPL_cSegment.h>
#include <TMPL_cCartesianEquation.h>

// Constructor
TMPL_cSegment::TMPL_cSegment(void)
{
	this->vertex[0] = TMPL_cPoint();
	this->vertex[1] = TMPL_cPoint();
}

TMPL_cSegment::TMPL_cSegment(TMPL_cPoint vertex1, TMPL_cPoint vertex2)
{
	if(vertex1.getX()<vertex2.getX())
	{
		this->vertex[0] = vertex1;
		this->vertex[1] = vertex2;
	}
	else
	{
		this->vertex[0] = vertex2;
		this->vertex[1] = vertex1;
	}
}

// Destructor
TMPL_cSegment::~TMPL_cSegment(void)
{}

// Set
void TMPL_cSegment::setVertex(TMPL_cPoint vertex, int index)
{
    if(0!=index && 1!=index)
    {
        fprintf(stderr,"%d is not a valid index for a segment vertex\n", index);
   	 	exit(1);
    }
	this->vertex[index] = vertex;
}

// Get
TMPL_cPoint TMPL_cSegment::getVertex(int index)
{
    if(0!=index && 1!=index)
    {
        fprintf(stderr,"%d is not a valid index for a segment vertex\n", index);
   	 	exit(1);
    }
    return this->vertex[index];
}

// Methods
float TMPL_cSegment::computeLength(void)
{
    return sqrt
            (
                pow(this->vertex[1].getX() - this->vertex[0].getX(), 2)
                +
                pow(this->vertex[1].getY() - this->vertex[0].getY(), 2)
            );
}

int TMPL_cSegment::xAppartientSegment(int x)
{
    return (x >= this->vertex[0].getX() && x <= this->vertex[1].getX());
}

int TMPL_cSegment::haveIntersectionWithSegment(TMPL_cSegment segment)
{
    TMPL_cCartesianEquation cartEqua1 = TMPL_cCartesianEquation(*this);
    TMPL_cCartesianEquation cartEqua2 = TMPL_cCartesianEquation(segment);

    int haveFunctionIntersection = cartEqua1.haveIntersectionPoint(cartEqua2);

    if(1 == haveFunctionIntersection)
    {
        TMPL_cPoint intersection = cartEqua1.intersectionPoint(cartEqua2);
        if(this->xAppartientSegment(intersection.getX() && segment.xAppartientSegment(intersection.getX())))
        {
            return 1;
        }
        return 0;
    }

    if(2 == haveFunctionIntersection)
    {
        if(this->xAppartientSegment(segment.vertex[0].getX()) || this->xAppartientSegment(segment.vertex[1].getX()) || segment.xAppartientSegment(this->vertex[0].getX()) || segment.xAppartientSegment(this->vertex[1].getX()))
        {
            return 2;
        }
    }

    return 0;
}

TMPL_cPoint TMPL_cSegment::intersectionPointWithSegment(TMPL_cSegment segment)
{
    TMPL_cCartesianEquation cartEqua1 = TMPL_cCartesianEquation(*this);
    TMPL_cCartesianEquation cartEqua2 = TMPL_cCartesianEquation(segment);

    TMPL_cPoint intersection = cartEqua1.intersectionPoint(cartEqua2);

    return intersection;
}

/*
TMPL_cSegment TMPL_cSegment::intersectionSegmentWithSegment(TMPL_cSegment segment)
{
    TMPL_cSegment intersection;
    if(this->xAppartientSegment(segment.vertex[0].getX()) && segment.xAppartientSegment(this->vertex[1].getX()))
    {
        intersection = TMPL_cSegment(segment.vertex[0], this->vertex[1]);
    }

    if(this->xAppartientSegment(segment.vertex[1].getX()) && segment.xAppartientSegment(this->vertex[0].getX()))
    {
        intersection = TMPL_cSegment(this->vertex[1], segment.vertex[1]);
    }

    if(this->xAppartientSegment(segment.vertex[0].getX()) && this->xAppartientSegment(segment.vertex[1].getX()))
    {
        intersection = TMPL_cSegment(segment.vertex[0], segment.vertex[1]);
    }

    if(segment.xAppartientSegment(this->vertex[0].getX()) && segment.xAppartientSegment(this->vertex[1].getX()))
    {
        intersection = TMPL_cSegment(this->vertex[0], this->vertex[1]);
    }

    return intersection;
}
*/
