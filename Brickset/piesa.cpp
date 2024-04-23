#include "piesa.h"
#include <iostream>
#include <fstream>

using namespace std;

piesa::piesa(int id, int cod) : id(id), cod(cod) {}

piesa::piesa(const piesa& other) {
    id = other.id;
    cod = other.cod;
    conectori = other.conectori;
}

piesa& piesa::operator=(const piesa& other) {
    if (this != &other) {
        id = other.id;
        cod = other.cod;
        conectori = other.conectori;
    }
    return *this;
}

piesa::~piesa() {
    /*std::cout << "Destructor called for piesa with ID: " << id << std::endl;*/
    conectori.clear();
}

int piesa::get_id() const {
    return id;
}

int piesa::get_cod() const {
    return cod;
}

void piesa::set_cod(int cod) {
    this->cod = cod;
}

void piesa::add_conector(const conector& conector) {
    try
    {
        conectori.push_back(conector);
    }
    catch(exception)
    {
        cerr << "Eroare. Nu s-a putut adauga conector." << '\n';
    }
}

const std::vector<conector>& piesa::get_conectori() const {
    return conectori;
}

void piesa::remove_conector(int id_conector) {
    for (auto it = conectori.begin(); it != conectori.end(); ++it) {
        if (it->get_id() == id_conector) {
            conectori.erase(it);
            break;
        }
    }
}

ostream& operator<<(ostream& out, const piesa& piesa)
{
    out << "Piesa LEGO:\n";
    out << " Cod Piesa: " << piesa.get_cod() << "\n";
    out << " Conectori:\n";
            
    for (const auto& conector : piesa.get_conectori())
        {
            out << "    - Tip: " << conector.get_tip() << "\n";
            out << "An fabricatie "<< conector.get_an_fabricatie() << "\n";
        }
    
    out << "\n";
return out;
}
