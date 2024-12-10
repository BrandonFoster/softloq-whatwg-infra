#include "Softloq-WHATWG/Primitive/bool.hpp"

namespace Softloq::WHATWG
{
    SOFTLOQ_WHATWG_INFRA_API Bool::Bool() : value(false) {}
    SOFTLOQ_WHATWG_INFRA_API Bool::Bool(const Bool &boolean) : value(boolean.value) {}
    SOFTLOQ_WHATWG_INFRA_API Bool::Bool(const bool value) : value(value) {}
    SOFTLOQ_WHATWG_INFRA_API Bool::Bool(Bool &&boolean) : value(std::move(boolean.value)) {}
    SOFTLOQ_WHATWG_INFRA_API Bool::~Bool() {}
    SOFTLOQ_WHATWG_INFRA_API Bool &Bool::operator=(const Bool &boolean)
    {
        Bool::value = boolean.value;
        return *this;
    }
    SOFTLOQ_WHATWG_INFRA_API Bool &Bool::operator=(const bool value)
    {
        Bool::value = value;
        return *this;
    }
    SOFTLOQ_WHATWG_INFRA_API Bool &Bool::operator=(Bool &&boolean)
    {
        Bool::value = std::move(boolean.value);
        return *this;
    }

    SOFTLOQ_WHATWG_INFRA_API std::ostream &operator<<(std::ostream &out, const Bool boolean) { return out << (boolean ? "true" : "false"); }
}