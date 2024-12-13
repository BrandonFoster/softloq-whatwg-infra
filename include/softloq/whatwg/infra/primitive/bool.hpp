/**
 * @file bool.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Contains the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg::infra
{   /** @brief WHATWG infra bool primitive class */
    class boolean: public primitive_base
    {
    public:
        // WHATWG primitive base overrides //

        /** @brief gets the primitive type of the class. returns infra::primitive_type::boolean. */
        SOFTLOQ_WHATWG_INFRA_API const infra::primitive_type primitive_type() const noexcept override;
        /**
         * @brief prints the WHATWG infra representation of the bool primitive to the outstream.
         * @param out the outstream that will be used. */
        SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

        //---------------------------------//

        // Constructors //

        /** @brief constructs a WHATWG infra bool primitive with the value false. */
        SOFTLOQ_WHATWG_INFRA_API boolean();
        /**
         * @brief constructs a WHATWG infra bool primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API boolean(const bool value);
        /**
         * @brief constructs a WHATWG infra bool primitive from the copy of another.
         * @param src the infra bool primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API boolean(const boolean& src);
        /**
         * @brief constructs a WHATWG infra bool primitive from the L-value of another.
         * @param src the infra bool primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API boolean(boolean&& src);
        /** @brief applies default destructor. */
        SOFTLOQ_WHATWG_INFRA_API ~boolean();

        //--------------//

        // Assignments //

        /**
         * @brief assigns a WHATWG infra bool primitive from a value.
         * @param value the value that will be used. */
        SOFTLOQ_WHATWG_INFRA_API boolean& operator=(const bool value);
        /**
         * @brief assigns a WHATWG infra bool primitive from the copy of another.
         * @param src the infra bool primitive that will be copied. */
        SOFTLOQ_WHATWG_INFRA_API boolean& operator=(const boolean& src);
        /**
         * @brief assigns a WHATWG infra bool primitive from the L-value of another.
         * @param src the infra bool primitive that will be moved. */
        SOFTLOQ_WHATWG_INFRA_API boolean& operator=(boolean&& src);

        //-------------//

        // Conversions //

        /** @brief gets the C++ bool representation. */
        SOFTLOQ_WHATWG_INFRA_API operator bool() const;

        //-------------//

    private:
        bool value;
    };
}

#endif