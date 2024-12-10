#ifndef SOFTLOQ_WHATWG_PRIMITIVE_ABSTRACT_HPP
#define SOFTLOQ_WHATWG_PRIMITIVE_ABSTRACT_HPP

#include "Softloq-WHATWG/libmacro.hpp"

namespace Softloq::WHATWG
{
    enum class PrimitiveType
    {
        Null,
        Bool,
        Number,
        Byte,
        ByteSequence,
        Codepoint,
        String,
        Time
    };

    class Primitive
    {
    public:
        SOFTLOQ_WHATWG_INFRA_API virtual const PrimitiveType getPrimitiveType() const = 0;
    };
}

#endif