#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

class conector
{
private:
    int id;
    string tip;
    int an_fabricatie;
    
public:
    conector(string tip = "", int an_fabricatie = 0):tip(tip), an_fabricatie(an_fabricatie) {};
//  conector(int an_fabricatie):an_fabricatie(an_fabricatie){};
    
    conector(const conector& other)
    {
        id = other.id;
        tip = other.tip;
        an_fabricatie = other.an_fabricatie;
    }

    conector& operator=(const conector& other)
    {
        if (this != &other)
        {
            id = other.id;
            tip = other.tip;
            an_fabricatie = other.an_fabricatie;
        }
        return *this;
    }
    
    ~conector() = default;
    
    int get_id()
    {
        return id;
    }
    
    int get_an_fabricatie () const
    {
        return an_fabricatie;
    }
    
    string get_tip () const
    {
        return tip;
    }
    
    void set_tip(string tip)
    {
        this->tip=tip;
    }
    
    void set_an_fabricatie(int an_fabricatie )
    {
        this->an_fabricatie=an_fabricatie;
    }
    
    friend ostream& operator<<(ostream& out, const conector& conector);
};

class piesa
{
private:
    int id;
    int cod;
    vector<conector> conectori;
    
public:
    piesa(int cod):cod(cod){};
    
    void add_conector(const conector& connector)
    {
        conectori.push_back(connector);
    }
    
    piesa(const piesa& other)
    {
        id = other.id;
        cod = other.cod;
        conectori = other.conectori;
    }

    piesa& operator=(const piesa& other)
    {
        if (this != &other)
        {
            id = other.id;
            cod = other.cod;
            conectori = other.conectori;
        }
        return *this;
    }
    
    ~piesa() = default;
    
    int get_id()
    {
        return id;
    }
    
    int get_cod() const
    {
        return cod;
    }
    
    void set_cod(int cod)
    {
        this->cod=cod;
    }
    
    const vector<conector>& get_conectori() const
    {
        return conectori;
    }
    
    void set_conectori(vector<conector> conectori)
    {
        this->conectori=conectori;
    }
    
    friend ostream& operator<<(ostream& out, const piesa& piesa);
};

class set_lego
{
private:
    int id;
    double pret_lansare;
    int an_lansare;
    string nume;
    vector<piesa> piese;
    
public:
//    set_lego(string nume):nume(nume){};
    set_lego(string nume = "", int an_lansare = 0, double pret_lansare = 0.0) : nume(nume), an_lansare(an_lansare), pret_lansare(pret_lansare) {};
//    set_lego(int an_lansare):an_lansare(an_lansare){};
//    set_lego(double pret_lansare):pret_lansare(pret_lansare){};
    
    void add_piesa(const piesa& piece)
    {
        piese.push_back(piece);
    }
    
    set_lego(const set_lego& other)
    {
        id = other.id;
        pret_lansare = other.pret_lansare;
        an_lansare = other.an_lansare;
        nume = other.nume;
        piese = other.piese;
    }
    
    set_lego& operator=(const set_lego& other)
    {
        if (this != &other)
        {
            id = other.id;
            pret_lansare = other.pret_lansare;
            an_lansare = other.an_lansare;
            nume = other.nume;
            piese = other.piese;
        }
        return *this;
    }
    
    ~set_lego() = default;
    
    int get_id()
    {
        return id;
    }
    
    string get_nume() const
    {
        return nume;
    }
    
    const vector<piesa>& get_piese() const
    {
        return piese;
    }
    
    int get_an_lansare () const
    {
        return an_lansare;
    }
    
    void set_an_lansare(int an_lansare)
    {
        this->an_lansare=an_lansare;
    }
    
    double get_pret_lansare() const
    {
        return pret_lansare;
    }
    
    void set_pret_lansare(double pret_lansare)
    {
        this->pret_lansare=pret_lansare;
    }
    
    void set_piese(vector<piesa> piese)
    {
        this->piese=piese;
    }
    
    friend ostream& operator<<(ostream& out, const set_lego& set_lego);
};

class catalog
{
private:
    int id;
    vector<set_lego> seturi_lego;
    
public:
    
    catalog(int id) :id(id) {};
    
    void add_set_lego(const set_lego& set)
    {
        seturi_lego.push_back(set);
    }
    
    int get_id()
    {
        return id;
    }
    
    const vector<set_lego>& get_seturi_lego() const
    {
        return seturi_lego;
    }
    
    void set_seturi_lego(vector<set_lego> seturi_lego)
    {
        this->seturi_lego=seturi_lego;
    }
    
    double calculeaza_pret_mediu(int an=0) const
    {
        double sum = 0;
        int count = 0;
        
        for (const auto& set_lego : seturi_lego)
        {
            if (an == 0 || set_lego.get_an_lansare() == an)
            {
                sum += set_lego.get_pret_lansare();
                count++;
            }
        }

        if (count == 0) return 0;
        return sum / count;
    }
    
    void afisare_evolutie_pret_catalog(int begin_year, int end_year)
    {
        for(int i = begin_year; i <= end_year; i++)
        {
            cout << i << ' ' << calculeaza_pret_mediu(i) << '\n';
        }
        
    }
    
    ~catalog() = default;
    
    friend ostream& operator<<(ostream& out, const catalog& catalog_lego);
};

ostream& operator<<(ostream& out, const catalog& catalog_lego)
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

ostream& operator<<(ostream& out, const set_lego& set_lego)
{
    out << "Set LEGO:\n";
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
return out;
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

ostream& operator<<(ostream& out, const conector& conector)
{
    out << "Conector LEGO:\n";
    out << "    - Tip: " << conector.get_tip() << "\n";
    out << "An fabricatie "<< conector.get_an_fabricatie() << "\n";
    out << "\n";
return out;
}

void citire (catalog& catalog_lego, const string& filename)
{
    ifstream file(filename);

    string nume;
    int cod,an_lansare,an_fabricatie;
    double pret_lansare;
    string tip;

    while (file >> nume >> an_lansare >> pret_lansare >> cod >> tip >> an_fabricatie)
    {
        set_lego set_lego(nume, an_lansare, pret_lansare);
        piesa piesa(cod);
        conector conector(tip, an_fabricatie);
        piesa.add_conector(conector);
        set_lego.add_piesa(piesa);
        catalog_lego.add_set_lego(set_lego);
    }

    file.close();
}

int main()
{   catalog catalog_lego(1);
    citire(catalog_lego, "Data Input");
    
    //Exemple de functionalitati
    
    //cout << catalog_lego;
    //catalog_lego.afisare_evolutie_pret_catalog(2008, 2024);
    //cout << catalog_lego.calculeaza_pret_mediu(2012);
    
    /*assert(conector)
    string expected_tip = "tip3";
    conector conector(expected_tip);
    string actual_tip = conector.get_tip();
    assert(actual_tip == expected_tip);
    cout << "Test passed, conector_tip is actual_tip\n";*/
    return 0;
}

