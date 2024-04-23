#include "conector.h"
#include <iostream>
#include <fstream>

using namespace std;

conector::conector(int id, std::string tip, int an_fabricatie) : id(id), tip(tip), an_fabricatie(an_fabricatie) {}

conector::conector(const conector& other) {
    id = other.id;
    tip = other.tip;
    an_fabricatie = other.an_fabricatie;
}

conector& conector::operator=(const conector& other) {
    if (this != &other) {
        id = other.id;
        tip = other.tip;
        an_fabricatie = other.an_fabricatie;
    }
    return *this;
}

conector::~conector() {
    //std::cout << "Destructor called for conector with ID: " << id << std::endl;
}

int conector::get_id() const {
    return id;
}

int conector::get_an_fabricatie() const {
    return an_fabricatie;
}

std::string conector::get_tip() const {
    return tip;
}

void conector::set_tip(std::string tip) {
    this->tip = tip;
}

void conector::set_an_fabricatie(int an_fabricatie) {
    if (an_fabricatie < 1990) {
        std::cout << an_fabricatie << " Eroare. Anul trebuie sa fie mai mare decat 1990.\n";
        return;
    }
    this->an_fabricatie = an_fabricatie;
}

ostream& operator<<(ostream& out, const conector& conector)
{
    out << "Conector LEGO:\n";
    out << "    - Tip: " << conector.get_tip() << "\n";
    out << "An fabricatie "<< conector.get_an_fabricatie() << "\n";
    out << "\n";
return out;
}
