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
    /** @brief gets the data structure type of the class. */
    SOFTLOQ_WHATWG_INFRA_API virtual const infra_structure_type structure_type() const noexcept = 0;
    /** @brief enables the output stream operator << on the data structure class. */
    SOFTLOQ_WHATWG_INFRA_API inline friend std::ostream& operator<<(std::ostream& out, const infra_structure_base& base) noexcept { base.print(out); return out; }
    /**
     * @brief prints the WHATWG infra representation of the data structure type to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API virtual void print(std::ostream& out) const noexcept = 0;
};
}

#endif