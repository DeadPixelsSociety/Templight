#include <stdio.h>
#include <stdlib.h>

#include <TMPL_cPolygonList.h>

// Constructor
TMPL_cPolygonList::TMPL_cPolygonList(void)
{
    this->polygon = NULL;
    this->precedant = NULL;
    this->suivant = NULL;
}

TMPL_cPolygonList::TMPL_cPolygonList(TMPL_cPolygon* polygon)
{
    this->polygon = polygon;
    this->precedant = NULL;
    this->suivant = NULL;
}

// Destructor
TMPL_cPolygonList::~TMPL_cPolygonList(void)
{}

// Methods
void TMPL_cPolygonList::addPolygonAfter(TMPL_cPolygon* polygon)
{
    TMPL_cPolygonList* pPolygonList = (TMPL_cPolygonList*) malloc(sizeof(TMPL_cPolygonList));

    (this->suivant)->precedant = pPolygonList;

    pPolygonList->polygon = polygon;
    pPolygonList->precedant = this;
    pPolygonList->suivant = this->suivant;

    this->suivant = pPolygonList;
}
