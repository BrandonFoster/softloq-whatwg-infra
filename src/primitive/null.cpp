/**
 * @file null.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra null primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/null.hpp"

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_null::primitive_type() const noexcept
{
    return infra_primitive_type::infra_null;
}
SOFTLOQ_WHATWG_INFRA_API void infra_null::print(std::ostream& out) const noexcept
{
}

//---------------------------------//
}