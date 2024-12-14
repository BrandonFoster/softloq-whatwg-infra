/**
 * @file byte.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{   /** @brief WHATWG infra byte primitive class */
    class infra_byte: public infra_primitive_base
    {
    public:
        // WHATWG primitive base overrides //

        /** @brief gets the primitive type of the class. returns infra_primitive_type::infra_byte. */
        SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
        /**
         * @brief prints the WHATWG infra representation of the byte primitive to the outstream.
         * @param out the outstream that will be used. */
        SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

        //---------------------------------//

        // Constructors //

        /** @brief constructs a WHATWG infra byte primitive with the value 0x00. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte() noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_uint8& value) noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from the copy of another.
         * @param src the infra byte primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_byte& src) noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from the L-value of another.
         * @param src the infra byte primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_byte&& src) noexcept;
        /** @brief applies default destructor. */
        SOFTLOQ_WHATWG_INFRA_API ~infra_byte() noexcept;

        //--------------//

        // Assignments //

        /**
         * @brief assigns a WHATWG infra byte primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_uint8& value) noexcept;
        /**
         * @brief assigns a WHATWG infra bool primitive from the copy of another.
         * @param src the infra byte primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_byte& src) noexcept;
        /**
         * @brief assigns a WHATWG infra byte primitive from the L-value of another.
         * @param src the infra byte primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(infra_byte&& src) noexcept;

        //-------------//

        // Conversions //

        /** @brief gets the C++ 8-bit unsigned integer representation. */
        SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;
        /** @brief gets the WHATWG infra 8-bit unsigned integer representation. */
        SOFTLOQ_WHATWG_INFRA_API operator infra_uint8() const noexcept;

        //-------------//

    private:
        infra_uint8 value;
    };
}

#endif