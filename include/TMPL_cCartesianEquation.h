#ifndef TMPL_C_CARTESIAN_EQUATION_H
#define TMPL_C_CARTESIAN_EQUATION_H

#include <TMPL_cSegment.h>
#include <TMPL_cHalfLine.h>

class TMPL_cCartesianEquation
{
public:
	// Constructor
	TMPL_cCartesianEquation(void);
	TMPL_cCartesianEquation(float a, float b, float c);
    TMPL_cCartesianEquation(TMPL_cSegment segment);
    TMPL_cCartesianEquation(TMPL_cHalfLine halfLine);

	// Destructor
	~TMPL_cCartesianEquation(void);

	// Get
	float getImage(float x);
	float getAntecedent(float y);

    // Methods
    int haveIntersectionPoint(TMPL_cCartesianEquation cartesianEquation); // return (1) if yes, (2) if same linear function, (0) if no

	float computeDiv(float a, float a2, float b, float b2);
	float computeXOrY(float a, float a2, float c, float c2, float div);

    TMPL_cPoint intersectionPoint(TMPL_cCartesianEquation cartesianEquation);

private:
	float a, b, c; // ax+by+c=0

};

#endif
