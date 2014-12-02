#include <stdio.h>
#include <stdlib.h>

#include <TMPL_cLightList.h>

// Constructor
TMPL_cLightList::TMPL_cLightList(void)
{
    this->first = NULL;
    this->last = NULL;
}

TMPL_cLightList::TMPL_cLightList(TMPL_cLightLink* lightLink)
{
    this->first = lightLink;
    this->last = lightLink;
}

// Destructor
TMPL_cLightList::~TMPL_cLightList(void)
{}

// Methods
void TMPL_cLightList::addLight(TMPL_cLight* light)
{
    TMPL_cLightLink* link = (TMPL_cLightLink*) malloc(sizeof(TMPL_cLightLink));
    link->setLight(light);
    link->setPrecedant(this->last);
    link->setSuivant(NULL);

    (this->last)->setSuivant(link);

    this->last = link;
}

void TMPL_cLightList::removeLight(TMPL_cLight* light)
{
    TMPL_cLightLink* link = this->first;
    while(NULL != link)
    {
        if(link->getLight() == light)
        {
            (link->getPrecedant())->setSuivant(link->getSuivant());
            (link->getSuivant())->setPrecedant(link->getPrecedant());

            free(link->getLight());
            free(link);

            return;
        }
        link = link->getSuivant();
    }
}

void TMPL_cLightList::updateSeparateLight(TMPL_cSeparateLight separateLight, TMPL_cLight* unseparateLight)
{
    this->removeLight(unseparateLight);

    TMPL_cLight* light1 = (TMPL_cLight*) malloc(sizeof(TMPL_cLight));
    (*light1) = separateLight.getLight(0);
    this->addLight(light1);

    TMPL_cLight* light2 = (TMPL_cLight*) malloc(sizeof(TMPL_cLight));
    (*light2) = separateLight.getLight(0);
    this->addLight(light2);
}

void TMPL_cLightList::render(sf::RenderWindow& window)
{
	TMPL_cLightLink* aux = this->first;
	while(NULL != aux)
	{
		aux->getLight()->render(window);
		aux = aux->getSuivant();
	}
}
