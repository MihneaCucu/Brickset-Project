#ifndef UCS_set_lego_h
#define UCS_set_lego_h
#include "featured_set_lego.h"
#include "limited_set_lego.h"

class UCS_set_lego : public featured_set_lego, public limited_set_lego {
private:
    int number_made;

public:
    UCS_set_lego(int id, std::string nume, int an_lansare, double pret_lansare, std::string tema, int interval, int number_made);
    int get_number_made() const;
    void set_number_made(int number_made);
    ~UCS_set_lego() override;
    void add_piesa(std::shared_ptr<piesa> piesa);
};

#endif


