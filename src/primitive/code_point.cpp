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

SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point() noexcept : value(0x0000) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const std::uint32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_uint32& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_uint32&& value) noexcept : value(std::move(value)) {}
#ifdef SOFTLOQ_MULTITHREADING
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_code_point& src) noexcept : infra_code_point(src, std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_code_point&& src) noexcept : infra_code_point(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_code_point& src, const std::lock_guard<std::mutex>&) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_code_point&& src, const std::lock_guard<std::mutex>&) noexcept : value(std::move(src.value)) {}
#else
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_code_point& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_code_point&& src) noexcept : value(std::move(src.value)) {}
#endif
SOFTLOQ_WHATWG_INFRA_API infra_code_point::~infra_code_point() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const std::uint32_t value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_point::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_uint32& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_point::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_uint32&& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_point::value = std::move(value);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_code_point& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = src.value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_code_point&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = std::move(src.value);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator std::uint32_t() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator infra_uint32() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
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
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    std::stringstream out;
    out << "0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value;
    return out.str();
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_valid() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x10FFFF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_leading_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0xD800 <= value && value <= 0xD8FF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_trailing_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0xDC00 <= value && value <= 0xDFFF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0xD800 <= value && value <= 0xD8FF) || (0xDC00 <= value && value <= 0xDFFF);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_scalar() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return !((0xD800 <= value && value <= 0xD8FF) || (0xDC00 <= value && value <= 0xDFFF));
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_nonchar() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    switch (value)
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
    default: return 0xFDD0 <= value && value <= 0xFDEF;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_ascii() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x7F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_ascii_tab_or_newline() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    switch (value)
    {
    case 0x9:
    case 0xA:
    case 0xD: return true;
    default: return false;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_whitespace() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
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
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_C0_control() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_C0_control_or_space() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value == 0x20 || value <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_control() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x1F || (0x7F <= value && value <= 0x9F);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_digit() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x30 <= value && value <= 0x39;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_upper_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x46);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_lower_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x61 <= value && value <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x46) || (0x61 <= value && value <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_upper() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x41 <= value && value <= 0x5A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_lower() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x61 <= value && value <= 0x7A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_alpha() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x41 <= value && value <= 0x5A) || (0x61 <= value && value <= 0x7A);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_point::is_alnum() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x5A) || (0x61 <= value && value <= 0x7A);
}

//------------------------------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_point::primitive_type() const noexcept { return infra_primitive_type::infra_code_point; }
SOFTLOQ_WHATWG_INFRA_API void infra_code_point::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    if (value <= 0x10FFFF) out << "U+" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value;
    else out << "U+<Invalid:" << std::hex << std::uppercase << value << ">";
}

//---------------------------------//
}