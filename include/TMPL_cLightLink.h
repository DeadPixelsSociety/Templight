#ifndef TMPL_C_LIGHT_LINK_H
#define TMPL_C_LIGHT_LINK_H

#include <TMPL_cLight.h>

class TMPL_cLightLink
{
public:
    // Constructor
    TMPL_cLightLink(void);
    TMPL_cLightLink(TMPL_cLight* light);

    // Destructor
    ~TMPL_cLightLink(void);

    // Set
    void setLight(TMPL_cLight* light);
    void setPrecedant(TMPL_cLightLink* precedant);
    void setSuivant(TMPL_cLightLink* suivant);

    // Get
    TMPL_cLight* getLight(void);
    TMPL_cLightLink* getPrecedant(void);
    TMPL_cLightLink* getSuivant(void);

private:
    TMPL_cLight* light;
    TMPL_cLightLink* precedant;
    TMPL_cLightLink* suivant;

};

#endif
