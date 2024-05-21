#ifndef featured_set_lego_h
#define featured_set_lego_h
#include "set_lego.h"
#include "piesa_speciala.h"

class featured_set_lego : virtual public set_lego {
private:
    std::string tema;

public:
    featured_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, std::string tema);
    std::string get_tema() const;
    void set_tema(std::string tema);
    ~featured_set_lego() override;
    void add_piesa(const piesa& piesa) override;
};

#endif
