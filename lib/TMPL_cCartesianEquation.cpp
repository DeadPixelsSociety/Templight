#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <TMPL_cCartesianEquation.h>

// Constructor
TMPL_cCartesianEquation::TMPL_cCartesianEquation(void)
{
    this->a = 1;
    this->b = 1;
    this->c = 0;
}

TMPL_cCartesianEquation::TMPL_cCartesianEquation(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

TMPL_cCartesianEquation::TMPL_cCartesianEquation(TMPL_cSegment segment)
{
    float point1X = segment.getVertex(0).getX();
    float point1Y = segment.getVertex(0).getY();
    float point2X = segment.getVertex(1).getX();
    float point2Y = segment.getVertex(1).getY();

    if(point1X != point2X)
    {
        this->a = (point2Y - point1Y) / (point2X - point1X);
        this->b = -1;
        this->c = point1Y - a * point1X;
    }
    else
    {
        this->a = 1;
        this->b = 0;
        this->c = -point1X;
    }
}

TMPL_cCartesianEquation::TMPL_cCartesianEquation(TMPL_cHalfLine halfLine)
{
    if(fmod(halfLine.getAngle(), 180) == 90)
    {
		this->a = 1;
        this->b = 0;
        this->c = -halfLine.getVertex().getX();
    }
	else{

		if(fmod(halfLine.getAngle(), 180) == 0)
		{
			this->a = 0;
		    this->b = -1;
		    this->c = -halfLine.getVertex().getY();
		}
		else
		{
			this->a = tan(halfLine.getAngle());
			this->b = -1;
			this->c = halfLine.getVertex().getY() - this->a * halfLine.getVertex().getX();
		}
	}
}

// Destructor
TMPL_cCartesianEquation::~TMPL_cCartesianEquation(void)
{}

// Get
float TMPL_cCartesianEquation::getImage(float x)
{
	if(0 == this->b)
	{
		fprintf(stderr,"No unique image for this castersian equation");
		exit(1);
	}
	return -(this->a*x+this->c)/this->b;
}

float TMPL_cCartesianEquation::getAntecedent(float y)
{
	if(0 == this->a)
	{
		fprintf(stderr,"No unique antecedent for this castersian equation");
		exit(1);
	}
	return -(this->b*y+this->c)/this->a;
}

// Methods
int TMPL_cCartesianEquation::haveIntersectionPoint(TMPL_cCartesianEquation cartesianEquation)
{
	if(this->a == cartesianEquation.a && this->b == cartesianEquation.b && this->c == cartesianEquation.c)
	{
		return 2;
	}
	if(this->a == cartesianEquation.a  && this->b == cartesianEquation.b && this->c != cartesianEquation.c)
	{
		return 0;
	}
	return 1;
}

float TMPL_cCartesianEquation::computeDiv(float a, float a2, float b, float b2)
{
	return a*b2 - a2*b;
}

float TMPL_cCartesianEquation::computeXOrY(float a, float a2, float c, float c2, float div)
{
	return (a2*c - c2*a) / div;
}

TMPL_cPoint TMPL_cCartesianEquation::intersectionPoint(TMPL_cCartesianEquation cartesianEquation)
{
	float x=0;
	float y=0;
	float div;
	float a[]={this->a, cartesianEquation.a};
	float b[]={this->b, cartesianEquation.b};
	float c[]={this->c, cartesianEquation.c};

	int i;
	int fait = 0; // 1 pour y, 2 pour x et 0 sinon

	for(i=0 ; i<2 ; i++)
	{
		div = computeDiv(a[i], a[1-i], b[i], b[1-i]);
		if(0!=div && 0==fait)
		{
			y = computeXOrY(a[i], a[1-i], c[i], c[1-i], div);
			fait = 1;
			break;
		}
	}

	for(i=0 ; i<2 ; i++)
	{
		div = computeDiv(b[i], b[1-i], a[i], a[1-i]);
		if(0!=div && 0==fait)
		{
			x = computeXOrY(b[i], b[1-i], c[i], c[1-i], div);
			fait = 2;
			break;
		}
	}

	switch(fait)
	{
		case 1:
			if(0 != this->a)
			{
				x = this->getAntecedent(y);
			} 
			else
			{
				if(0 != cartesianEquation.a)
				{
					x = cartesianEquation.getAntecedent(y);
				}
				else
				{
					fprintf(stderr,"No unique antecedent for this point");
					exit(1);
				}
			}
		break;

		case 2:
			if(0 != this->b)
			{
				y = this->getImage(x);
			} 
			else
			{
				if(0 != cartesianEquation.b)
				{
					y = cartesianEquation.getImage(x);
				}
				else
				{
					fprintf(stderr,"No unique image for this point");
					exit(1);
				}
			}
		break;

		default:
		fprintf(stderr,"Can't find x nor y");
		break;
	}
	
	TMPL_cPoint intersection = TMPL_cPoint(x, y);
	return intersection;
}
