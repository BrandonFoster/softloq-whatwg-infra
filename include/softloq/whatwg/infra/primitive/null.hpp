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

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//
};
}

#endif