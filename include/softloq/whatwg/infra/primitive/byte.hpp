/**
 * @file byte.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include "softloq/whatwg/infra/primitive/unsigned.hpp"

namespace softloq::whatwg::infra
{   /** @brief WHATWG infra byte primitive class */
    class byte: public primitive_base
    {
    public:
        // WHATWG primitive base overrides //

        /** @brief gets the primitive type of the class. returns infra::primitive_type::byte. */
        SOFTLOQ_WHATWG_INFRA_API const infra::primitive_type primitive_type() const noexcept override;
        /**
         * @brief prints the WHATWG infra representation of the byte primitive to the outstream.
         * @param out the outstream that will be used. */
        SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

        //---------------------------------//

        // Constructors //

        /** @brief constructs a WHATWG infra byte primitive with the value 0x00. */
        SOFTLOQ_WHATWG_INFRA_API byte() noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API byte(const unsigned8& value) noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from the copy of another.
         * @param src the infra byte primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API byte(const byte& src) noexcept;
        /**
         * @brief constructs a WHATWG infra byte primitive from the L-value of another.
         * @param src the infra byte primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API byte(byte&& src) noexcept;
        /** @brief applies default destructor. */
        SOFTLOQ_WHATWG_INFRA_API ~byte() noexcept;

        //--------------//

        // Assignments //

        /**
         * @brief assigns a WHATWG infra byte primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API byte& operator=(const unsigned8& value) noexcept;
        /**
         * @brief assigns a WHATWG infra bool primitive from the copy of another.
         * @param src the infra byte primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API byte& operator=(const byte& src) noexcept;
        /**
         * @brief assigns a WHATWG infra byte primitive from the L-value of another.
         * @param src the infra byte primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API byte& operator=(byte&& src) noexcept;

        //-------------//

        // Conversions //

        /** @brief gets the C++ 8-bit unsigned integer representation. */
        SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;
        /** @brief gets the WHATWG infra 8-bit unsigned integer representation. */
        SOFTLOQ_WHATWG_INFRA_API operator unsigned8() const noexcept;

        //-------------//

    private:
        unsigned8 value;
    };
}

#endif