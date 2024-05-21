#include "set_lego.h"
#include "featured_set_lego.h"
#include "limited_set_lego.h"
#include "UCS_set_lego.h"
class set_lego_factory {
public:
    enum class LegoSetType {
        Normal,
        Featured,
        Limited,
        UCS
    };

    static std::unique_ptr<set_lego> createLegoSet(LegoSetType type, int id, std::string nume, int an_lansare, double pret_lansare, std::string tema = NULL, int interval = 0, int number_made = 0) {
        switch (type) {
            case LegoSetType::Normal:
                return std::make_unique<set_lego>(id, nume, an_lansare, pret_lansare);
            case LegoSetType::Featured:
                return std::make_unique<featured_set_lego>(id, nume, an_lansare, pret_lansare, tema);
            case LegoSetType::Limited:
                return std::make_unique<limited_set_lego>(id, nume, an_lansare, pret_lansare, interval);
            case LegoSetType::UCS:
                return std::make_unique<UCS_set_lego>(id, nume, an_lansare, pret_lansare, tema, interval, number_made);
            default:
                return nullptr;
        }
    }
};
