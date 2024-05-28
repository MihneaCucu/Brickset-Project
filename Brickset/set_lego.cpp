#include "set_lego.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

int set_lego::contor_seturi_lego = 0;
double set_lego::cost_total = 0;

set_lego::set_lego(int id, std::string nume, int an_lansare, double pret_lansare)
    : id(id), nume(nume), an_lansare(an_lansare), pret_lansare(pret_lansare)
{
    set_lego::increment_set(pret_lansare);
}

set_lego::set_lego(const set_lego& other) {
    id = other.id;
    pret_lansare = other.pret_lansare;
    an_lansare = other.an_lansare;
    nume = other.nume;
    piese =  other.piese;
    nr_piese = map<std::string, int>(other.nr_piese);
}

set_lego& set_lego::operator=(const set_lego& other) {
    if (this != &other) {
        id = other.id;
        pret_lansare = other.pret_lansare;
        an_lansare = other.an_lansare;
        nume = other.nume;
        piese = other.piese;
        nr_piese = std::map<std::string, int>(other.nr_piese);
    }
    return *this;
}

set_lego::~set_lego() {
    piese.clear();
    nr_piese.clear();
}

int set_lego::get_id() const {
    return id;
}

std::string set_lego::get_nume() const {
    return nume;
}

int set_lego::get_an_lansare() const {
    return an_lansare;
}

void set_lego::set_an_lansare(int an_lansare) {
    if (an_lansare < 1990) {
        std::cout << an_lansare << " Eroare. Anul trebuie sa fie mai mare decat 1990.\n";
        return;
    }
    this->an_lansare = an_lansare;
}

double set_lego::get_pret_lansare() const {
    return pret_lansare;
}

void set_lego::set_pret_lansare(double pret_lansare) {
    this->pret_lansare = pret_lansare;
}

const std::vector<piesa>& set_lego::get_piese() const {
    return piese;
}

void set_lego::add_piesa(const piesa& piesa) {
    piese.push_back(piesa);
    nr_piese.emplace(std::to_string(piesa.get_cod()), 1);
}

void set_lego::remove_piesa(int id_piesa) {
    auto it = std::find_if(piese.begin(), piese.end(), [id_piesa](const piesa& p) {
        return p.get_id() == id_piesa;
    });
    if (it != piese.end()) {
        std::string cod_piesa = std::to_string((it)->get_cod());
        if (--(nr_piese)[cod_piesa] == 0) {
            nr_piese.erase(cod_piesa);
        }
        piese.erase(it);
    }
}

const std::map<std::string, int>& set_lego::get_nr_piese() const {
    return nr_piese;
}

const piesa* set_lego::find_piesa(int id_piesa) const {
    auto it = std::find_if(piese.begin(), piese.end(), [id_piesa](const piesa& p) {
        return p.get_id() == id_piesa;
    });
    return nullptr;
}

void set_lego::afiseaza_piese() const {
    std::for_each(piese.begin(), piese.end(), [](const piesa& p) {
        std::cout << "Piesa ID: " << p.get_id() << ", Cod: " << p.get_cod() << std::endl;
    });
}


ostream& operator<<(ostream& out, const set_lego& set_lego) {
    out << "Set LEGO:\n";
    out << "Nume set: " << set_lego.get_nume() << "\n";
    out << "An lansare: " << set_lego.get_an_lansare() << "\n";
    out << "Pret lansare: " << set_lego.get_pret_lansare() << "\n";
    out << "Piese:\n";
    
    for (const auto& piesa : set_lego.get_piese()) {
        out << " Cod Piesa: " << piesa.get_cod() << "\n";
        out << " Conectori:\n";
        
        for (const auto& conector : piesa.get_conectori()) {
            out << "    - Tip: " << conector.get_tip() << "\n";
            out << "An fabricatie " << conector.get_an_fabricatie() << "\n";
        }
    }
    
    out << "\n";
    return out;
}

