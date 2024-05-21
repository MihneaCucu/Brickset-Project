#ifndef limited_set_lego_h
#define limited_set_lego_h
#include "set_lego.h"

class limited_set_lego : virtual public set_lego {
private:
    int interval;

public:
    limited_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, int interval);
    int get_interval() const;
    void set_interval(int interval);
    ~limited_set_lego() override;
};

#endif

