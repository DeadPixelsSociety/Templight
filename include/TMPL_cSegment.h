#ifndef TMPL_C_SEGMENT_H
#define TMPL_C_SEGMENT_H

#include <TMPL_cPoint.h>
#include <TMPL_cPolygon.h>

// VERIFIER ORDRE VERTICES

class TMPL_cSegment
{
public:
    // Constructor
	TMPL_cSegment(void);
   	TMPL_cSegment(TMPL_cPoint vertex1, TMPL_cPoint vertex2);

   	// Destructor
	~TMPL_cSegment(void);

   	// Set
	void setVertex(TMPL_cPoint vertex, int index);

   	// Get
  	TMPL_cPoint getVertex(int index);

   	// Methods
   	float computeLength(void);

    int xAppartientSegment(int x);
    int haveIntersectionWithSegment(TMPL_cSegment segment); // return (1) if point, (2) if segment, (0) if no intersection
    TMPL_cPoint intersectionPointWithSegment(TMPL_cSegment segment);
    //TMPL_cSegment intersectionSegmentWithSegment(TMPL_cSegment segment);

protected:
	TMPL_cPoint vertex[2];

};

#endif
