/**
 * @file base.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra data structure base class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/base.hpp"

namespace softloq::whatwg
{
SOFTLOQ_WHATWG_INFRA_API std::ostream& operator<<(std::ostream& out, const infra_structure_base& base) noexcept { base.print(out); return out; }
}