#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "conector.h"
#include "piesa.h"
#include "catalog.h"
#include "set_lego.h"
#include "piesa_speciala.h"
#include "featured_set_lego.h"
#include "exception_citire_catalog.h"
#include "logger.h"
#include "set_lego_factory.cpp"

INITIALIZE_EASYLOGGINGPP

using namespace std;

// conector, piesa, set_lego, catalog
// 4 clase abstracte: conector_generic, piesa_generic etc
// metode publice doar cu semnatura

int main()
{   
    logger::get_instance()->log_info("Application starting");
    
    catalog<set_lego> catalog_lego(1);
    
    try
    {
        catalog_lego.citire("Data Input");
    }
    
    catch(const exception_citire_catalog& e)
    {
        cout << "exceptie " << e.what() << '\n';
    }
    
        catalog_lego.add_set_lego(set_lego(1, "Set1", 2020, 100.0));
        catalog_lego.add_set_lego(set_lego(2, "Set2", 2021, 150.0));
        catalog_lego.add_set_lego(set_lego(3, "Set3", 2021, 200.0));

       // Filtrăm seturile lansate în 2021
       auto seturi_2021 = catalog_lego.filtreaza_seturi([](const set_lego& set) {
           return set.get_an_lansare() == 2021;
       });

       // Afișăm seturile filtrate
       for (const auto& set : seturi_2021) {
           std::cout << set.get_nume() << " - " << set.get_an_lansare() << " - " << set.get_pret_lansare() << std::endl;
       }
    
    set_lego_generic* seturi[3];
    seturi[0] = new set_lego(2345, "set23", 2020, 24.55); //upcasting
    seturi[1] = new featured_set_lego(2321, "set24", 2020, 30, "Space"); //upcasting
    
    cout << catalog_lego.get_medie_cost() << '\n';
    
    
    //Dynamic dispatch cu virtual
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
    
    
    /*auto legoSet = set_lego_factory::createLegoSet(set_lego_factory::LegoSetType::Normal);
        auto featuredSet = set_lego_factory::createLegoSet(set_lego_factory::LegoSetType::Featured);
        auto limitedSet = set_lego_factory::createLegoSet(set_lego_factory::LegoSetType::Limited);
        auto ucsSet = set_lego_factory::createLegoSet(set_lego_factory::LegoSetType::UCS);*/

    
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

