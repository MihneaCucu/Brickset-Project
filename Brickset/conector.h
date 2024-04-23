#ifndef conector_h
#define conector_h
#include <string>

using namespace std;

class conector_generic {
public:
    virtual int get_id() const = 0;
    virtual int get_an_fabricatie() const = 0;
    virtual std::string get_tip() const = 0;
    virtual void set_tip(std::string tip) = 0;
    virtual void set_an_fabricatie(int an_fabricatie) = 0;
    virtual ~conector_generic() {}
};

class conector : public conector_generic {
private:
    int id;
    int an_fabricatie;
    std::string tip;

public:
    conector(int id = 0, std::string tip = "", int an_fabricatie = 0);
    conector(const conector& other);
    conector& operator=(const conector& other);
    ~conector();

    int get_id() const override;
    int get_an_fabricatie() const override;
    std::string get_tip() const override;
    void set_tip(std::string tip) override;
    void set_an_fabricatie(int an_fabricatie) override;
};


#endif
