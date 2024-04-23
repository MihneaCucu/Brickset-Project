#ifndef set_lego_h
#define set_lego_h
#include <vector>
#include "piesa.h"

class set_lego_generic {
public:
    virtual int get_id() const = 0;
    virtual std::string get_nume() const = 0;
    virtual int get_an_lansare() const = 0;
    virtual void set_an_lansare(int an_lansare) = 0;
    virtual double get_pret_lansare() const = 0;
    virtual void set_pret_lansare(double pret_lansare) = 0;
    virtual const std::vector<piesa>& get_piese() const = 0;
    virtual void add_piesa(const piesa& piesa) = 0;
    virtual void remove_piesa(int id_piesa) = 0;
    virtual ~set_lego_generic() {}
    
};

class set_lego : public set_lego_generic {
private:
    int id;
    double pret_lansare;
    std::string nume;
    int an_lansare;
    
protected:
    std::vector<piesa> piese;

public:
    
    static void increment_set(double pret_lansare)
    {
        contor_seturi_lego++;
        cost_total += pret_lansare;
    };

    static double calculeaza_medie_cost()
    {
        return  cost_total / contor_seturi_lego;
    };
    
    static int contor_seturi_lego;
    static double cost_total;
    
    set_lego(int id, std::string nume = "", int an_lansare = 0, double pret_lansare = 0.0);
    set_lego(const set_lego& other);
    set_lego& operator=(const set_lego& other);
    ~set_lego();

    int get_id() const override;
    std::string get_nume() const override;
    int get_an_lansare() const override;
    void set_an_lansare(int an_lansare) override;
    double get_pret_lansare() const override;
    void set_pret_lansare(double pret_lansare) override;
    const std::vector<piesa>& get_piese() const override;
    void add_piesa(const piesa& piesa) override;
    void remove_piesa(int id_piesa) override;
};


#endif
