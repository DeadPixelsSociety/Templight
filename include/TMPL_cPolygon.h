#ifndef TMPL_C_POLYGON_H
#define TMPL_C_POLYGON_H

#include <TMPL_cPoint.h>

class TMPL_cPolygon
{
public:
    // Constructor
    TMPL_cPolygon(void);
    TMPL_cPolygon(int size);

    // Destructor
    ~TMPL_cPolygon(void);

	// Set
	void setVertex(TMPL_cPoint vertex, int index);
	void setNbVertices(int size);

	// Get
	TMPL_cPoint getVertex(int index);
	int getNbVertices(void);

    // Methods
    TMPL_cPoint computeCenterOfGravity(void);
    int isPointInPolygon(TMPL_cPoint point);

private:
    int nbVertices;
    TMPL_cPoint* verticesTab;

};

#endif
