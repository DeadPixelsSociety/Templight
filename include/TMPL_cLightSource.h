#ifndef TMPL_C_LIGHT_SOURCE_H
#define TMPL_C_LIGHT_SOURCE_H

#include <TMPL_cHalfLine.h>

class TMPL_cLightSource : public TMPL_cHalfLine
{
public:
	// Constructor
	TMPL_cLightSource(void);
	TMPL_cLightSource(TMPL_cPoint vertex, float angle);

	// Destructor
	~TMPL_cLightSource(void);

	// Methods
	void update(float dt);

};

#endif
