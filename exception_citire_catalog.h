#ifndef EXCEPTION_CITIRE_CATALOG_H
#define EXCEPTION_CITIRE_CATALOG_H

#include <exception>
#include <string>

using namespace std;

class exception_citire_catalog: public exception
{
private:
    string msg;
    
public:
    exception_citire_catalog(const string& msg = "Eroare citire catalog"): msg(msg) {}
    virtual const char * what() const noexcept override { return msg.c_str(); }
};

#endif // EXCEPTION_CITIRE_CATALOG_H

