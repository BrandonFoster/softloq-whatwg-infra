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
enum class infra_primitive_type { infra_null, infra_bool, infra_number, infra_byte, infra_byte_sequence, infra_code_unit, infra_code_point, infra_string, infra_time };

/** @brief WHATWG infra primitive base class. Abstract C++ class. */
class infra_primitive_base
{
public:
    SOFTLOQ_WHATWG_INFRA_API virtual const infra_primitive_type primitive_type() const noexcept = 0;
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_primitive_base& base) noexcept;
    SOFTLOQ_WHATWG_INFRA_API virtual void print(std::ostream& out) const noexcept = 0;
};
}

#endif