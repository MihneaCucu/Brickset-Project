#ifndef piesa_h
#define piesa_h

#include <vector>
#include <memory>
#include "conector.h"

class piesa_generic {
public:
    virtual int get_id() const = 0;
    virtual int get_cod() const = 0;
    virtual void set_cod(int cod) = 0;
    virtual void add_conector(std::unique_ptr<conector> conector) = 0;
    virtual const std::vector<std::unique_ptr<conector>>& get_conectori() const = 0;
    virtual void remove_conector(int id_conector) = 0;
    virtual ~piesa_generic() {}
};

class piesa : public piesa_generic {
private:
    int id;
    int cod;
    
protected:
    std::vector<std::unique_ptr<conector>> conectori;

public:
    piesa(int id, int cod);
    piesa(const piesa& other) = delete;
    piesa& operator=(const piesa& other) = delete;
    ~piesa();

    int get_id() const override;
    int get_cod() const override;
    void set_cod(int cod) override;
    void add_conector(std::unique_ptr<conector> conector) override;
    const std::vector<std::unique_ptr<conector>>& get_conectori() const override;
    void remove_conector(int id_conector) override;
};

#endif

