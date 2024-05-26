#include "piesa_speciala.h"
#include <iostream>

piesa_speciala::piesa_speciala(int id, int cod, int unghi) : piesa(id, cod), unghi(unghi) {}

void piesa_speciala::add_conector(std::unique_ptr<conector>& conector) {
    try {
        conectori.push_back(std::move(conector));
    } catch(const std::exception& e) {
        std::cerr << "Eroare. Nu s-a putut adauga conector: " << e.what() << '\n';
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

