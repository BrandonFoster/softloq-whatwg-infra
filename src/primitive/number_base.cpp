/**
 * @file number_base.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra number primitive base class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/number_base.hpp"

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_number_base::primitive_type() const noexcept { return infra_primitive_type::infra_number; }

//---------------------------------//
}