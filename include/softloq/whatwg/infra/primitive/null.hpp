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
/** @brief WHATWG infra null primitive class (https://infra.spec.whatwg.org/#nulls). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_null: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_null. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra null primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------// 
};
}

#endif