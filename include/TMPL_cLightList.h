#ifndef TMPL_C_LIGHT_LIST_H
#define TMPL_C_LIGHT_LIST_H

#include <game/Entity.h>
#include <TMPL_cLightLink.h>
#include <TMPL_cSeparateLight.h>

class TMPL_cLightList : public game::Entity
{
public:
    // Constructor
    TMPL_cLightList(void);
    TMPL_cLightList(TMPL_cLightLink* lightLink);

    // Destructor
    ~TMPL_cLightList(void);

    // Methods
    void addLight(TMPL_cLight* light);
    void removeLight(TMPL_cLight* light);

    void updateSeparateLight(TMPL_cSeparateLight separateLight, TMPL_cLight* unseparateLight);

	// World
	void render(sf::RenderWindow& window);

private:
    TMPL_cLightLink* first;
    TMPL_cLightLink* last;

};

#endif
