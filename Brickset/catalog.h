#ifndef catalog_h
#define catalog_h
#include <vector>
#include "set_lego.h"

class catalog_generic {
public:
    virtual int get_id() const = 0;
    virtual void add_set_lego(const set_lego& set) = 0;
    virtual const std::vector<set_lego>& get_seturi_lego() const = 0;
    virtual void remove_set_lego(int id_set_lego) = 0;
    virtual void remove_set_lego(const set_lego& set_lego) = 0;
    virtual double calculeaza_pret_mediu(int an = 0) const = 0;
    virtual void afisare_evolutie_pret_catalog(int begin_year, int end_year) = 0;
    virtual ~catalog_generic() {}
};

class catalog : public catalog_generic {
private:
    int id;
    std::vector<set_lego> seturi_lego;

public:
    catalog(int id);
    void add_set_lego(const set_lego& set) override;
    int get_id() const override;
    const std::vector<set_lego>& get_seturi_lego() const override;
    void remove_set_lego(int id_set_lego) override;
    void remove_set_lego(const set_lego& set_lego) override;
    double calculeaza_pret_mediu(int an = 0) const override;
    void afisare_evolutie_pret_catalog(int begin_year, int end_year) override;
    void citire (const string& filename);
};

#endif
