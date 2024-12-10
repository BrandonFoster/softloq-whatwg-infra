#ifndef SOFTLOQ_WHATWG_PRIMITIVE_ABSTRACT_HPP
#define SOFTLOQ_WHATWG_PRIMITIVE_ABSTRACT_HPP

#include "Softloq-WHATWG/libmacro.hpp"

namespace Softloq::WHATWG
{
    class Primitive
    {
    public:
        enum class Type
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
        SOFTLOQ_WHATWG_INFRA_API virtual const Type getType() const = 0;
    };
}

#endif