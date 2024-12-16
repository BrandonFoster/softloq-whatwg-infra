/**
 * @file code_unit.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code unit primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra code unit primitive class */
class infra_code_unit: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_code_unit() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const int value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_uint16& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_uint16&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_code_unit& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_code_unit&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_code_unit() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const int value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_uint16& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_uint16&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_code_unit& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_code_unit&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::uint16_t() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint16() const noexcept;

    //-------------//

private:
    infra_uint16 value;
};
}

#endif