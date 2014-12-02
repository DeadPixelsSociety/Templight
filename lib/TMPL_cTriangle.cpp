#include <math.h>

#include <TMPL_cTriangle.h>
#include <TMPL_cSegment.h>

#include <TMPL_Constants.h>

// Constructor
TMPL_cTriangle::TMPL_cTriangle()
{
    this->vertex[0] = TMPL_cPoint();
    this->vertex[1] = TMPL_cPoint();
    this->vertex[2] = TMPL_cPoint();
}

TMPL_cTriangle::TMPL_cTriangle(TMPL_cPoint vertex1, TMPL_cPoint vertex2, TMPL_cPoint vertex3)
{
    this->vertex[0] = vertex1;
    this->vertex[1] = vertex2;
    this->vertex[2] = vertex3;
}

// Destructor
TMPL_cTriangle::~TMPL_cTriangle(void)
{}

// Methods
float TMPL_cTriangle::computeArea()
{
    TMPL_cSegment segment12 = TMPL_cSegment(this->vertex[0], this->vertex[1]);
    TMPL_cSegment segment13 = TMPL_cSegment(this->vertex[0], this->vertex[2]);
    TMPL_cSegment segment23 = TMPL_cSegment(this->vertex[1], this->vertex[3]);

    float length12 = segment12.computeLength();
    float length13 = segment13.computeLength();
    float length23 = segment23.computeLength();

	float area = sqrt((length12 + length13 + length23) * (length12 + length13 - length23) * (length12 + length23 - length13) * (length13 + length23 - length12)) / 4;

    return area;
}

int TMPL_cTriangle::isPointInTriangle(TMPL_cPoint point)
{
    float area = this->computeArea();

    TMPL_cTriangle triangleP12 = TMPL_cTriangle(point, this->vertex[0], this->vertex[1]);
    float areaP12 = triangleP12.computeArea();

    TMPL_cTriangle triangleP13 = TMPL_cTriangle(point, this->vertex[0], this->vertex[2]);
    float areaP13 = triangleP13.computeArea();

    TMPL_cTriangle triangleP23 = TMPL_cTriangle(point, this->vertex[1], this->vertex[2]);
    float areaP23 = triangleP23.computeArea();

    float areaSum = areaP12 + areaP13 + areaP23;

    if(areaSum+AREA_IMPRECISION > area && areaSum-AREA_IMPRECISION < area)
    {
        return 1;
    }
    return 0;
}
