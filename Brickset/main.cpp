#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "conector.h"
#include "piesa.h"
#include "set_lego.h"
#include "catalog.h"
#include "piesa_speciala.h"
#include "featured_set_lego.h"
#include "exception_citire_catalog.cpp"

using namespace std;

// conector, piesa, set_lego, catalog
// 4 clase abstracte: conector_generic, piesa_generic etc
// metode publice doar cu semnatura


int main()
{   
    catalog catalog_lego(1);
    
    try
    {
        catalog_lego.citire("Data Input");
    }
    
    catch(const exception_citire_catalog& e)
    {
        cout << "exceptie " << e.what() << '\n';
    }
    
    set_lego_generic* seturi[3];
    seturi[0] = new set_lego(2345, "set23", 2020, 24.55); //upcasting
    seturi[1] = new featured_set_lego(2321, "set24", 2020, 30, "Space"); //upcasting
    
    //cout << catalog_lego.get_medie_cost() << '\n';
    
    for (int i = 0; i <= 1; i++)
    {
        seturi[i]->set_an_lansare(2024); //dynamic dispatch
    }
    
    piesa_generic* piese[3];
    piese[0] = new piesa(56, 355); //upcasting
    piese[1] = new piesa_speciala(44, 869, 90); //upcasting
    
    
    
    for (int i = 0; i <= 1; i++)
    {
        seturi[i]->set_an_lansare(2024); //dynamic dispatch
    }
    
    // pentru piesa speciala
    
    //Exemple de functionalitati
    
    //cout << catalog_lego <<'\n';
    //catalog_lego.afisare_evolutie_pret_catalog(2008, 2024);
    //cout << catalog_lego.calculeaza_pret_mediu(2012) <<'\n';
    
    double actual_pret_mediu = catalog_lego.calculeaza_pret_mediu(2025);
    assert(actual_pret_mediu == 57.2);
    cout << "Test passed, actual_pret_mediu\n";
    
    string expected_tip = "tip3";
    conector conector(1, expected_tip);
    string actual_tip = conector.get_tip();
    assert(actual_tip == expected_tip);
    cout << "Test passed, conector_tip is actual_tip\n";
    
return 0;
}
