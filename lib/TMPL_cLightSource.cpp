#include <TMPL_cLightSource.h>

// Constructor
TMPL_cLightSource::TMPL_cLightSource(void)
: TMPL_cHalfLine()
{}

TMPL_cLightSource::TMPL_cLightSource(TMPL_cPoint vertex, float angle)
: TMPL_cHalfLine(vertex, angle)
{}

// Destructor
TMPL_cLightSource::~TMPL_cLightSource(void)
{}
