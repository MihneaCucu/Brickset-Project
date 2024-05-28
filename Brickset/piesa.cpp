#include "piesa.h"
#include <iostream>
#include <fstream>

using namespace std;

piesa::piesa(int id, int cod) : id(id), cod(cod) {}

piesa::~piesa() {}

int piesa::get_id() const {
    return id;
}

int piesa::get_cod() const {
    return cod;
}

void piesa::set_cod(int cod) {
    this->cod = cod;
}

void piesa::add_conector(conector conector) {
    conectori.push_back(std::move(conector));
}

const std::vector<conector>& piesa::get_conectori() const {
    return conectori;
}

void piesa::remove_conector(int id_conector) {
    conectori.erase(
        std::remove_if(conectori.begin(), conectori.end(),
            [id_conector](conector& ptr) {
                return ptr.get_id() == id_conector;
            }),
        conectori.end()
    );
}

