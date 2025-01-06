/**
 * @file code_point.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra code point primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/code_point.hpp"

#include <iomanip>
#include <sstream>

namespace softloq::whatwg
{
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point() noexcept
: data(0x0000)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const std::uint32_t value) noexcept
: data(value)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_uint32& value) noexcept
: data(value)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_uint32&& value) noexcept
: data(std::move(value))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_code_point& src) noexcept
: data(src.data)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_code_point&& src) noexcept
: data(std::move(src.data))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::~infra_code_point() noexcept
{
}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const std::uint32_t value) noexcept
{
    infra_code_point::data = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_uint32& value) noexcept
{
    infra_code_point::data = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_uint32&& value) noexcept
{
    infra_code_point::data = std::move(value);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_code_point& src) noexcept
{
    data = src.data;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_code_point&& src) noexcept
{
    data = std::move(src.data);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator std::uint32_t() const noexcept
{
    return data;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator infra_uint32() const noexcept
{
    return data;
}

//-------------//

// WHATWG code point member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_code_point::code_point_str() const noexcept
{
    std::stringstream out;
    out << *this;
    return out.str();
}

SOFTLOQ_WHATWG_INFRA_API std::string infra_code_point::hex_str() const noexcept
{
    std::stringstream out;
    out << "0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << data;
    return out.str();
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_valid() const noexcept
{
    return data <= 0x10FFFF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_leading_surrogate() const noexcept
{
    return 0xD800 <= data && data <= 0xD8FF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_trailing_surrogate() const noexcept
{
    return 0xDC00 <= data && data <= 0xDFFF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_surrogate() const noexcept
{
    return (0xD800 <= data && data <= 0xD8FF) || (0xDC00 <= data && data <= 0xDFFF);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_scalar() const noexcept
{
    return !((0xD800 <= data && data <= 0xD8FF) || (0xDC00 <= data && data <= 0xDFFF));
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_nonchar() const noexcept
{
    switch (data)
    {
    case 0xFFFE:
    case 0xFFFF:
    case 0x1FFFE:
    case 0x1FFFF:
    case 0x2FFFE:
    case 0x2FFFF:
    case 0x3FFFE:
    case 0x3FFFF:
    case 0x4FFFE:
    case 0x4FFFF:
    case 0x5FFFE:
    case 0x5FFFF:
    case 0x6FFFE:
    case 0x6FFFF:
    case 0x7FFFE:
    case 0x7FFFF:
    case 0x8FFFE:
    case 0x8FFFF:
    case 0x9FFFE:
    case 0x9FFFF:
    case 0xAFFFE:
    case 0xAFFFF:
    case 0xBFFFE:
    case 0xBFFFF:
    case 0xCFFFE:
    case 0xCFFFF:
    case 0xDFFFE:
    case 0xDFFFF:
    case 0xEFFFE:
    case 0xEFFFF:
    case 0xFFFFE:
    case 0xFFFFF:
    case 0x10FFFE:
    case 0x10FFFF: return true;
    default: return 0xFDD0 <= data && data <= 0xFDEF;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_ascii() const noexcept
{
    return data <= 0x7F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_ascii_tab_or_newline() const noexcept
{
    switch (data)
    {
    case 0x9:
    case 0xA:
    case 0xD: return true;
    default: return false;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_whitespace() const noexcept
{
    switch (data)
    {
    case 0x9:
    case 0xA:
    case 0xC:
    case 0xD:
    case 0x20: return true;
    default: return false;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_C0_control() const noexcept
{
    return data <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_C0_control_or_space() const noexcept
{
    return data == 0x20 || data <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_control() const noexcept
{
    return data <= 0x1F || (0x7F <= data && data <= 0x9F);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_digit() const noexcept
{
    return 0x30 <= data && data <= 0x39;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_upper_hex() const noexcept
{
    return (0x30 <= data && data <= 0x39) || (0x41 <= data && data <= 0x46);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_lower_hex() const noexcept
{
    return (0x30 <= data && data <= 0x39) || (0x61 <= data && data <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_hex() const noexcept
{
    return (0x30 <= data && data <= 0x39) || (0x41 <= data && data <= 0x46) || (0x61 <= data && data <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_upper() const noexcept
{
    return 0x41 <= data && data <= 0x5A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_lower() const noexcept
{
    return 0x61 <= data && data <= 0x7A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_alpha() const noexcept
{
    return (0x41 <= data && data <= 0x5A) || (0x61 <= data && data <= 0x7A);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_alnum() const noexcept
{
    return (0x30 <= data && data <= 0x39) || (0x41 <= data && data <= 0x5A) || (0x61 <= data && data <= 0x7A);
}

//------------------------------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_point::primitive_type() const noexcept
{
    return infra_primitive_type::infra_code_point;
}
SOFTLOQ_WHATWG_INFRA_API void infra_code_point::print(std::ostream& out) const noexcept
{
    if (data <= 0x10FFFF) out << "U+" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << data;
    else out << "U+<Invalid:" << std::hex << std::uppercase << data << ">";
}

//---------------------------------//
}