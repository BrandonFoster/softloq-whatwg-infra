/**
 * @file base.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra data structure base class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_BASE_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_BASE_HPP

#include "softloq/whatwg/infra/lib_macro.hpp"

#include <ostream>

namespace softloq::whatwg
{
/** @brief WHATWG infra data structure types */
enum class infra_structure_type { infra_sequence, infra_list, infra_map, infra_struct };

/** @brief WHATWG infra data structure base class. Abstract C++ class. */
class infra_structure_base
{
public:
    SOFTLOQ_WHATWG_INFRA_API virtual const infra_structure_type structure_type() const noexcept = 0;
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_structure_base& base) noexcept;
    SOFTLOQ_WHATWG_INFRA_API virtual void print(std::ostream& out) const noexcept = 0;
};
}

#endif