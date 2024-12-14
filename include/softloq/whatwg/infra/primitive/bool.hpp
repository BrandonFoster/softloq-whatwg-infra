/**
 * @file bool.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg
{   /** @brief WHATWG infra bool primitive class */
    class infra_bool: public infra_primitive_base
    {
    public:
        // WHATWG primitive base overrides //

        /** @brief gets the primitive type of the class. returns infra_primitive_type::infra_bool. */
        SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
        /**
         * @brief prints the WHATWG infra representation of the bool primitive to the outstream.
         * @param out the outstream that will be used. */
        SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

        //---------------------------------//

        // Constructors //

        /** @brief constructs a WHATWG infra bool primitive with the value false. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool() noexcept;
        /**
         * @brief constructs a WHATWG infra bool primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool(const bool value) noexcept;
        /**
         * @brief constructs a WHATWG infra bool primitive from the copy of another.
         * @param src the infra bool primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool(const infra_bool& src) noexcept;
        /**
         * @brief constructs a WHATWG infra bool primitive from the L-value of another.
         * @param src the infra bool primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool(infra_bool&& src) noexcept;
        /** @brief applies default destructor. */
        SOFTLOQ_WHATWG_INFRA_API ~infra_bool() noexcept;

        //--------------//

        // Assignments //

        /**
         * @brief assigns a WHATWG infra bool primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const bool value) noexcept;
        /**
         * @brief assigns a WHATWG infra bool primitive from the copy of another.
         * @param src the infra bool primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const infra_bool& src) noexcept;
        /**
         * @brief assigns a WHATWG infra bool primitive from the L-value of another.
         * @param src the infra bool primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(infra_bool&& src) noexcept;

        //-------------//

        // Conversions //

        /** @brief gets the C++ bool representation. */
        SOFTLOQ_WHATWG_INFRA_API operator bool() const noexcept;

        //-------------//

    private:
        bool value;
    };
}

#endif