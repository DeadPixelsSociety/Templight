#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <TMPL_cSeparateLight.h>
#include <TMPL_cHalfLine.h>

// Constructor
TMPL_cSeparateLight::TMPL_cSeparateLight(void)
{
    this->lights[0] = TMPL_cLight();
    this->lights[1] = TMPL_cLight();
}

TMPL_cSeparateLight::TMPL_cSeparateLight(TMPL_cLight light1, TMPL_cLight light2)
{
    this->lights[0] = light1;
    this->lights[1] = light2;
}

TMPL_cSeparateLight::TMPL_cSeparateLight(TMPL_cPoint point, TMPL_cLight light)
{
    float angle[2];
	angle[0] = light.getRaySegmentEx(0).computeAngle();
	angle[1] = light.getRaySegmentEx(1).computeAngle();

	float angleMoy = angle[0];
	if(angle[0] != angle[1])
	{
	 	angleMoy = (angle[0] + angle[1])/2 + 180*fabs((int)(angle[0] - angle[1])/180);
	}

	TMPL_cHalfLine halfLineToFindSource = TMPL_cHalfLine(point, fmod(angleMoy + 180, 360));
	TMPL_cSegment sourcesSegment = TMPL_cSegment(light.getRaySegmentEx(0).getSourceVertex(), light.getRaySegmentEx(1).getSourceVertex());

	TMPL_cPoint newSourcePoint = halfLineToFindSource.intersectionPointWithSegment(sourcesSegment);
	TMPL_cRaySegment middleRaySegment = TMPL_cRaySegment(newSourcePoint, point);

	TMPL_cLight newLight0 = TMPL_cLight(light.getRaySegmentEx(0), middleRaySegment, light.getRaySegmentBase());
	TMPL_cLight newLight1 = TMPL_cLight(middleRaySegment, light.getRaySegmentEx(1), light.getRaySegmentBase());

    this->lights[0] = newLight0;
    this->lights[1] = newLight1;
}

// Destructor
TMPL_cSeparateLight::~TMPL_cSeparateLight(void)
{}

// Get
TMPL_cLight TMPL_cSeparateLight::getLight(int index)
{
    if(0!=index && 1!=index)
    {
        fprintf(stderr,"%d is not a valid index for a separate lights light\n", index);
   	 	exit(1);
    }
    return this->lights[index];
}
