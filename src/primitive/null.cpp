/**
 * @file null.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra null primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/null.hpp"

namespace softloq::whatwg::infra
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const primitive_type null::primitive_type() const noexcept { return primitive_type::null; }
SOFTLOQ_WHATWG_INFRA_API void null::print(std::ostream& out) const noexcept {}

//---------------------------------//
}