#include <stdio.h>
#include <stdlib.h>

#include <TMPL_cLightLink.h>

// Constructor
TMPL_cLightLink::TMPL_cLightLink(void)
{
    this->light = NULL;
    this->precedant = NULL;
    this->suivant = NULL;
}

TMPL_cLightLink::TMPL_cLightLink(TMPL_cLight* light)
{
    this->light = light;
    this->precedant = NULL;
    this->suivant = NULL;
}

// Destructor
TMPL_cLightLink::~TMPL_cLightLink(void)
{}

// Set
void TMPL_cLightLink::setLight(TMPL_cLight* light)
{
    this->light = light;
}

void TMPL_cLightLink::setPrecedant(TMPL_cLightLink* precedant)
{
    this->precedant = precedant;
}


void TMPL_cLightLink::setSuivant(TMPL_cLightLink* suivant)
{
    this->suivant = suivant;
}

// Get
TMPL_cLight* TMPL_cLightLink::getLight(void)
{
    return this->light;
}

TMPL_cLightLink* TMPL_cLightLink::getPrecedant(void)
{
    return this->precedant;
}

TMPL_cLightLink* TMPL_cLightLink::getSuivant(void)
{
    return this->suivant;
}

