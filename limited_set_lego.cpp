#include "limited_set_lego.h"
#include <iostream>

limited_set_lego::limited_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, int interval)
    : set_lego(id, nume, an_lansare, pret_lansare), interval(interval) {}

int limited_set_lego::get_interval() const {
    return interval;
}

void limited_set_lego::set_interval(int interval) {
    this->interval = interval;
}

limited_set_lego::~limited_set_lego() {
    /*std::cout << "Destructor called for limited_set_lego with time_limit: " << interval << std::endl;*/
    piese->clear();
}


