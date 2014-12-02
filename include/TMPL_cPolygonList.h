#ifndef TMPL_C_POLYGON_LIST_H
#define TMPL_C_POLYGON_LIST_H

#include <TMPL_cPolygon.h>

class TMPL_cPolygonList
{
public:
    // Constructor
    TMPL_cPolygonList(void);
    TMPL_cPolygonList(TMPL_cPolygon* polygon);

    // Destructor
    ~TMPL_cPolygonList(void);

    // Methods
    void addPolygonAfter(TMPL_cPolygon* polygon);

private:
    TMPL_cPolygon* polygon;
    TMPL_cPolygonList* precedant;
    TMPL_cPolygonList* suivant;

};

#endif
