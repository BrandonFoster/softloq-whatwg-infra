/**
 * @file code_unit.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra code unit primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/code_unit.hpp"

#include <iomanip>
#include <sstream>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_unit::primitive_type() const noexcept { return infra_primitive_type::infra_code_unit; }
SOFTLOQ_WHATWG_INFRA_API void infra_code_unit::print(std::ostream& out) const noexcept { out << "0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit() noexcept : value(0x0000) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const std::uint16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_uint16& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_uint16&& value) noexcept : value(std::move(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_code_unit& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_code_unit&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::~infra_code_unit() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const std::uint16_t value) noexcept { infra_code_unit::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_uint16& value) noexcept { infra_code_unit::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_uint16&& value) noexcept { infra_code_unit::value = std::move(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_code_unit& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_code_unit&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator std::uint16_t() const noexcept { return value; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator infra_uint16() const noexcept { return value; }

//-------------//

// Member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_code_unit::code_unit_str() const
{
    std::stringstream out;
    out << *this;
    return out.str();
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_leading_surrogate() const { return 0xD800 <= value && value <= 0xD8FF; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_trailing_surrogate() const { return 0xDC00 <= value && value <= 0xDFFF; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_surrogate() const { return is_leading_surrogate() || is_trailing_surrogate(); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_scalar() const { return !is_surrogate(); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_nonchar() const
{
    switch (value)
    {
    case 0xFFFE:
    case 0xFFFF: return true;
    default: return 0xFDD0 <= value && value <= 0xFDEF;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_ascii() const { return value <= 0x7F; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_ascii_tab_or_newline() const
{
    switch (value)
    {
    case 0x9:
    case 0xA:
    case 0xD: return true;
    default: return false;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_whitespace() const
{
    switch (value)
    {
    case 0x9:
    case 0xA:
    case 0xC:
    case 0xD:
    case 0x20: return true;
    default: return false;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_C0_control() const { return value <= 0x1F; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_C0_control_or_space() const { return value == 0x20 || is_C0_control(); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_control() const { return is_C0_control() || (0x7F <= value && value <= 0x9F); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_digit() const { return 0x30 <= value && value <= 0x39; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_upper_hex() const { return is_digit() || (0x41 <= value && value <= 0x46); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_lower_hex() const { return is_digit() || (0x61 <= value && value <= 0x66); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_hex() const { return is_digit() || (0x41 <= value && value <= 0x46) || (0x61 <= value && value <= 0x66); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_upper() const { return 0x41 <= value && value <= 0x5A; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_lower() const { return 0x61 <= value && value <= 0x7A; }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_alpha() const { return is_lower() || is_upper(); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_alnum() const { return is_digit() || is_alpha(); }

//------------------//
}