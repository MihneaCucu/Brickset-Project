#include "piesa_speciala.h"
#include <iostream>

piesa_speciala::piesa_speciala(int id, int cod, int unghi) : piesa(id, cod), unghi(unghi) {}

void piesa_speciala::add_conector(const conector& conector) {
    if (conector.get_tip() == "tip1000") {
        conectori.push_back(conector);
    } else {
        std::cout << "Nu poti instantia piese speciale cu alt tip de conector." << std::endl;
    }
}

int piesa_speciala::get_unghi() const {
    return unghi;
}

void piesa_speciala::set_unghi(int unghi) {
    this->unghi = unghi;
}

piesa_speciala::~piesa_speciala() {
    /*std::cout << "Destructor called for piesa speciala with angle: " << unghi << std::endl;*/
    conectori.clear();
}

