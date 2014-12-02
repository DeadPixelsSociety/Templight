#ifndef TMPL_C_SEPARATE_LIGHT_H
#define TMPL_C_SEPARATE_LIGHT_H

#include <TMPL_cLight.h>

class TMPL_cSeparateLight
{
public:
    // Constructor
    TMPL_cSeparateLight(void);
    TMPL_cSeparateLight(TMPL_cLight light1, TMPL_cLight light2);
    TMPL_cSeparateLight(TMPL_cPoint point, TMPL_cLight light); // separe light par point

    // Destructor
    ~TMPL_cSeparateLight(void);

    // Get
    TMPL_cLight getLight(int index);

private:
	TMPL_cLight lights[2];
};

#endif

