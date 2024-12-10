#ifndef SOFTLOQ_WHATWG_PRIMITIVE_NULL_HPP
#define SOFTLOQ_WHATWG_PRIMITIVE_NULL_HPP

#include "Softloq-WHATWG/Primitive/abstract.hpp"

#include <ostream>

namespace Softloq::WHATWG
{
    class Null : public Primitive
    {
    public:
        SOFTLOQ_WHATWG_INFRA_API inline const PrimitiveType getPrimitiveType() const override { return PrimitiveType::Null; }
        SOFTLOQ_WHATWG_INFRA_API friend std::ostream &operator<<(std::ostream &out, const Null null);
    };
}

#endif