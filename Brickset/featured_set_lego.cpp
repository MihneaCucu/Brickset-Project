#include "featured_set_lego.h"
#include <iostream>

featured_set_lego::featured_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, std::string tema)
    : set_lego(id, nume, an_lansare, pret_lansare), tema(tema) {}

std::string featured_set_lego::get_tema() const 
{
    return tema;
}

void featured_set_lego::set_tema(std::string tema) 
{
    this->tema = tema;
}

featured_set_lego::~featured_set_lego() 
{
    /*std::cout << "Destructor called for featured_set_lego with theme: " << tema << std::endl;*/
    piese->clear();
}

void featured_set_lego::add_piesa(std::shared_ptr<piesa> piesa) 
{
    if (std::dynamic_pointer_cast<piesa_speciala>(piesa))
    {
        set_lego::add_piesa(piesa);
    }
}


//composite pattern
