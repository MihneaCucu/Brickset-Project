#include "UCS_set_lego.h"
#include <iostream>

UCS_set_lego::UCS_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, std::string tema, int interval, int number_made)
    : set_lego(id, nume, an_lansare, pret_lansare), featured_set_lego(id, nume, an_lansare, pret_lansare, tema), limited_set_lego(id, nume, an_lansare, pret_lansare, interval), number_made(number_made) {}

int UCS_set_lego::get_number_made() const {
    return number_made;
}

void UCS_set_lego::set_number_made(int number_made) {
    this->number_made = number_made;
}

UCS_set_lego::~UCS_set_lego() {
    /*std::cout << "Destructor called for UCS_set_lego with number_made:  " << number_made << std::endl;*/
    piese.clear();
}



