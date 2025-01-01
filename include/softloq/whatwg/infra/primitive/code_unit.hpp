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
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const std::uint16_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_uint16& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_uint16&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_code_unit& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_code_unit&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_code_unit() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const std::uint16_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_uint16& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_uint16&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_code_unit& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_code_unit&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::uint16_t() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint16() const noexcept;

    //-------------//

    // Member functions //

    SOFTLOQ_WHATWG_INFRA_API std::string code_unit_str() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API const bool is_leading_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_trailing_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_nonchar() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_tab_or_newline() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_whitespace() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control_or_space() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_control() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_digit() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_alpha() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_alnum() const noexcept;

    //------------------//

private:
    infra_uint16 value;
};
}

#endif