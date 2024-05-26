#ifndef catalog_h
#define catalog_h
#include <vector>
#include <iostream>
#include <fstream>
#include "set_lego.h"
#include "exception_citire_catalog.h"

//template

class set_lego;


template<typename T>
class catalog_generic {
public:
    virtual int get_id() const = 0;
    virtual void add_set_lego(const set_lego& set) = 0;
    virtual const std::vector<set_lego>& get_seturi_lego() const = 0;
    virtual void remove_set_lego(int id_set_lego) = 0;
    virtual void remove_set_lego(const T& set_lego) = 0;
    virtual double calculeaza_pret_mediu(int an = 0) const = 0;
    virtual void afisare_evolutie_pret_catalog(int begin_year, int end_year) = 0;
    virtual ~catalog_generic() {}
    virtual int get_contor_seturi() = 0;
    virtual double get_medie_cost() = 0;
};
template<typename T>
class catalog : public catalog_generic<T>{
private:
    int id;
    std::vector<set_lego> seturi_lego;

public:
    catalog(int id){};
    
    void add_set_lego(const set_lego& set) override
    {
        seturi_lego.push_back(set);
    }


    
    int get_id() const override{return id;};
    
    const std::vector<set_lego>& get_seturi_lego() const override {
        return seturi_lego;
    }

    void remove_set_lego(int id_set_lego) override{for (auto it = seturi_lego.begin(); it != seturi_lego.end(); ++it) {
        if (it->get_id() == id_set_lego) {
            seturi_lego.erase(it);
            break;
        }
    }};
    void remove_set_lego(const T& set_lego) override{remove_set_lego(set_lego.get_id());};
    double calculeaza_pret_mediu(int an = 0) const override{double sum = 0;
        int count = 0;

        for (const auto& set_lego : seturi_lego) {
            if (an == 0 || set_lego.get_an_lansare() == an) {
                sum += set_lego.get_pret_lansare();
                count++;
            }
        }

        if (count == 0) return 0;
        return sum / count;};

    void afisare_evolutie_pret_catalog(int begin_year, int end_year) override{for (int i = begin_year; i <= end_year; i++) {
        cout << i << ' ' << calculeaza_pret_mediu(i) << '\n';
    }};
    
    void citire (const string& filename){ try
        {
            ifstream file(filename);
            
            string nume;
            int id_set,id_piesa,id_conector,cod,an_lansare,an_fabricatie;
            double pret_lansare;
            string tip;
            
            while (file >> id_set >> nume >> an_lansare >> pret_lansare >> id_piesa >>cod >> id_conector >> tip >> an_fabricatie)
            {
                T set_lego(id_set, nume, an_lansare, pret_lansare);
                std::shared_ptr<piesa> ptr_piesa = std::make_shared<piesa>(id_piesa, cod);
                
                conector conector(id_conector, tip, an_fabricatie);
                
                ptr_piesa->add_conector(conector);

                set_lego.add_piesa(ptr_piesa);
                
                this->add_set_lego(set_lego);
            }
            
            file.close();
        }
        catch(const exception& e)
        {
            throw exception_citire_catalog();
        }};
    
    /*template<typename T>
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
    }*/

    
    int get_contor_seturi() override{return seturi_lego[0].contor_seturi_lego;};
    
    double get_medie_cost() override{return seturi_lego[0].calculeaza_medie_cost();};
    
    template<typename Predicate>
        std::vector<T> filtreaza_seturi(Predicate pred) const
        {
            std::vector<T> rezultat;
            for (const auto& set : seturi_lego) {
                if (pred(set)) {
                    rezultat.push_back(set);
                }
            }
            return rezultat;
        }
    
    
    
};




#endif
