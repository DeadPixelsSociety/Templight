#ifndef TMPL_C_HALF_LINE_H
#define TMPL_C_HALF_LINE_H

#include <TMPL_cPoint.h>
#include <TMPL_cSegment.h>

class TMPL_cHalfLine
{
public:
	// Constructor
	TMPL_cHalfLine(void);
	TMPL_cHalfLine(TMPL_cPoint vertex, float angle);

	// Destructor
	~TMPL_cHalfLine(void);

	// Get
	float getAngle(void);
	TMPL_cPoint getVertex(void);

    // Methods
    TMPL_cPoint intersectionPointWithSegment(TMPL_cSegment segment);
	int pointAppartient(TMPL_cPoint point);

protected:
	TMPL_cPoint vertex;
	float angle;

};

#endif
