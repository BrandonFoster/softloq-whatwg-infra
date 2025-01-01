/**
 * @file code_point.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code point primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra code unit primitive class */
class infra_code_point: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_code_point() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const std::uint32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const infra_uint32& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(infra_uint32&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const infra_code_point& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(infra_code_point&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_code_point() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const std::uint32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const infra_uint32& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(infra_uint32&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const infra_code_point& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(infra_code_point&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::uint32_t() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint32() const noexcept;

    //-------------//

    // Member functions //
    
    SOFTLOQ_WHATWG_INFRA_API std::string code_point_str() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string hex_str() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API const bool is_valid() const noexcept;
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
    infra_uint32 value;
};
}

#endif