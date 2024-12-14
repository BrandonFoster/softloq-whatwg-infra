/**
 * @file null.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra null primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra null primitive class */
class infra_null: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    /** @brief gets the primitive type of the class. returns infra_primitive_type::infra_null. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief prints the WHATWG infra representation of the null primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//
};
}

#endif