/*#include "catalog.h"
#include "exception_citire_catalog.cpp"
#include <iostream>
#include <fstream>


using namespace std;
template<typename T>
catalog<T>::catalog(int id) : id(id) {}

template<typename T>
void catalog<T>::add_set_lego(const T& set) {
    seturi_lego.push_back(set);
}

template<typename T>
int catalog<T>::get_id() const {
    return id;
}

template<typename T>
const std::vector<T>& catalog<T>::get_seturi_lego() const {
    return seturi_lego;
}
template<typename T>
void catalog<T>::remove_set_lego(int id_set_lego) {
    for (auto it = seturi_lego.begin(); it != seturi_lego.end(); ++it) {
        if (it->get_id() == id_set_lego) {
            seturi_lego.erase(it);
            break;
        }
    }
}

template<typename T>
void catalog<T>::remove_set_lego(const T& set_lego) {
    remove_set_lego(set_lego.get_id());
}

template<typename T>
double catalog<T>::calculeaza_pret_mediu(int an) const {
    double sum = 0;
    int count = 0;

    for (const auto& set_lego : seturi_lego) {
        if (an == 0 || set_lego.get_an_lansare() == an) {
            sum += set_lego.get_pret_lansare();
            count++;
        }
    }

    if (count == 0) return 0;
    return sum / count;
}

template<typename T>
void catalog<T>::afisare_evolutie_pret_catalog(int begin_year, int end_year) {
    for (int i = begin_year; i <= end_year; i++) {
        std::cout << i << ' ' << calculeaza_pret_mediu(i) << '\n';
    }
}

template<typename T>
int catalog<T>::get_contor_seturi()
{
    return seturi_lego[0].contor_seturi_lego;
}

template<typename T>
double catalog<T>::get_medie_cost()
{
    return seturi_lego[0].calculeaza_medie_cost();
}

template<typename T>
ostream& operator<<(ostream& out, const catalog<T>& catalog_lego)
{
    out << "Catalog LEGO:\n";
        
    for (const auto& set_lego : catalog_lego.get_seturi_lego())
    {
        out << "Nume set: " << set_lego.get_nume() << "\n";
        out << "An lansare: " << set_lego.get_an_lansare() << "\n";
        out << "Pret lansare: " << set_lego.get_pret_lansare() << "\n";
        out << "Piese:\n";
            
        for (const auto& piesa : set_lego.get_piese())
        {
            out << " Cod Piesa: " << piesa.get_cod() << "\n";
            out << " Conectori:\n";
                
            for (const auto& conector : piesa.get_conectori())
            {
                out << "    - Tip: " << conector.get_tip() << "\n";
                out << "An fabricatie "<< conector.get_an_fabricatie() << "\n";
            }
        }
        out << "\n";
    }
    return out;
}

template<typename T>
void catalog<T>::citire (const string& filename)
{   try
    {
        ifstream file(filename);
        
        string nume;
        int id_set,id_piesa,id_conector,cod,an_lansare,an_fabricatie;
        double pret_lansare;
        string tip;
        
        while (file >> id_set >> nume >> an_lansare >> pret_lansare >> id_piesa >>cod >> id_conector >> tip >> an_fabricatie)
        {
            T set_lego(id_set, nume, an_lansare, pret_lansare);
            piesa piesa(id_piesa, cod);
            conector conector(id_conector, tip, an_fabricatie);
            piesa.add_conector(conector);
            set_lego.add_piesa(piesa);
            this->add_set_lego(set_lego);
        }
        
        file.close();
    }
    catch(const exception& e)
    {
        throw exception_citire_catalog();
    }
}
*/
