#ifndef SOFTLOQ_WHATWG_PRIMITIVE_NUMBER_HPP
#define SOFTLOQ_WHATWG_PRIMITIVE_NUMBER_HPP

#include "Softloq-WHATWG/Primitive/abstract.hpp"

#include <ostream>

namespace Softloq::WHATWG
{
    class Number : public Primitive
    {
    public:
        SOFTLOQ_WHATWG_INFRA_API virtual ~Number() = 0;

        SOFTLOQ_WHATWG_INFRA_API inline const Type getType() const override { return Type::Number; }
    };
}

#endif