#ifndef SOFTLOQ_WHATWG_PRIMITIVE_BOOL_HPP
#define SOFTLOQ_WHATWG_PRIMITIVE_BOOL_HPP

#include "Softloq-WHATWG/Primitive/abstract.hpp"

#include <ostream>

namespace Softloq::WHATWG
{
    class Bool : public Primitive
    {
    public:
        SOFTLOQ_WHATWG_INFRA_API Bool();
        SOFTLOQ_WHATWG_INFRA_API Bool(const Bool &boolean);
        SOFTLOQ_WHATWG_INFRA_API Bool(const bool value);
        SOFTLOQ_WHATWG_INFRA_API Bool(Bool &&boolean);
        SOFTLOQ_WHATWG_INFRA_API ~Bool();
        SOFTLOQ_WHATWG_INFRA_API Bool &operator=(const Bool &boolean);
        SOFTLOQ_WHATWG_INFRA_API Bool &operator=(const bool value);
        SOFTLOQ_WHATWG_INFRA_API Bool &operator=(Bool &&boolean);

        SOFTLOQ_WHATWG_INFRA_API inline const Type getType() const override { return Type::Bool; }
        SOFTLOQ_WHATWG_INFRA_API friend std::ostream &operator<<(std::ostream &out, const Bool boolean);

        SOFTLOQ_WHATWG_INFRA_API inline constexpr operator bool() const { return value; }

    private:
        bool value;
    };
}

#endif