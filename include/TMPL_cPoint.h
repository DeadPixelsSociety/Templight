#ifndef TMPL_C_POINT_H
#define TMPL_C_POINT_H

class TMPL_cPoint
{
public:
	// Constructor
	TMPL_cPoint(void);
	TMPL_cPoint(float x, float y);

	// Destructor
	~TMPL_cPoint(void);

	// Set
	void setX(float x);
	void setY(float y);

	// Get
	float getX();
	float getY();

private:
	float x, y;
};

#endif
