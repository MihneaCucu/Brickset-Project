#ifndef piesa_speciala_h
#define piesa_speciala_h

#include "piesa.h"

class piesa_speciala : public piesa {
private:
    int unghi;

public:
    piesa_speciala(int id, int cod, int unghi);
    void add_conector(conector& conector);
    int get_unghi() const;
    void set_unghi(int unghi);
    ~piesa_speciala() override;
};

#endif
