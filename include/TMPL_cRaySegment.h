#ifndef TMPL_C_RAY_SEGMENT_H
#define TMPL_C_RAY_SEGMENT_H

#include <TMPL_cSegment.h>
#include <TMPL_cHalfLine.h>

class TMPL_cRaySegment : public TMPL_cSegment
{
public:
    // Constructor
    TMPL_cRaySegment(void);
    TMPL_cRaySegment(TMPL_cPoint vertex1, TMPL_cPoint vertex2); // vertex1 sera considéré comme source
	TMPL_cRaySegment(TMPL_cHalfLine halfLine, float xMin, float xMax, float yMin, float yMax);

	// Destructor
    ~TMPL_cRaySegment(void);

	// Set 
	void setNonSourceVertex(TMPL_cPoint vertex);

	// Get
	TMPL_cPoint getSourceVertex(void);
	TMPL_cPoint getNonSourceVertex(void);

	// Methods
	void ordonnerVertex(void);

	float computeAngle();

	TMPL_cPoint intersectionWithPolygon(TMPL_cPolygon polygon);

private:
    int source;

};

#endif
