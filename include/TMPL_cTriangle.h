#ifndef TMPL_C_TRIANGLE_H
#define TMPL_C_TRIANGLE_H

#include <TMPL_cPoint.h>

class TMPL_cTriangle
{
public:
    // Constructor
    TMPL_cTriangle(void);
    TMPL_cTriangle(TMPL_cPoint vertex1, TMPL_cPoint vertex2, TMPL_cPoint vertex3);

    // Destructor
    ~TMPL_cTriangle(void);

    // Methods
    float computeArea(void);
    int isPointInTriangle(TMPL_cPoint point);

private:
    TMPL_cPoint vertex[3];

};

#endif
