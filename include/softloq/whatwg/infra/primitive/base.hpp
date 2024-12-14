/**
 * @file base.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra primitive base class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BASE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BASE_HPP

#include "softloq/whatwg/infra/lib_macro.hpp"
#include <ostream>

namespace softloq::whatwg
{
/** @brief WHATWG infra primitive types */
enum class infra_primitive_type { infra_null, infra_bool, infra_number, infra_byte, infra_byte_sequence, infra_code_point, infra_string, infra_time };
/** @brief WHATWG infra primitive base class. Abstract C++ class. */
class infra_primitive_base
{
public:
    /** @brief gets the primitive type of the class. */
    SOFTLOQ_WHATWG_INFRA_API virtual const infra_primitive_type primitive_type() const noexcept = 0;
    /** @brief enables the output stream operator << on the primitive class. */
    SOFTLOQ_WHATWG_INFRA_API inline friend std::ostream& operator<<(std::ostream& out, const infra_primitive_base& base) noexcept { base.print(out); return out; }
    /**
     * @brief prints the WHATWG infra representation of the primitive type to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API virtual void print(std::ostream& out) const noexcept = 0;
};
}

#endif