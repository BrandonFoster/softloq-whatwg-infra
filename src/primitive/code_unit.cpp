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
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit() noexcept : value(0x0000) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const std::uint16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_uint16& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_uint16&& value) noexcept : value(std::move(value)) {}
#ifdef SOFTLOQ_MULTITHREADING
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_code_unit& src) noexcept : infra_code_unit(src, std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_code_unit&& src) noexcept : infra_code_unit(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_code_unit& src, const std::lock_guard<std::mutex>&) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_code_unit&& src, const std::lock_guard<std::mutex>&) noexcept : value(std::move(src.value)) {}
#else
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_code_unit& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_code_unit&& src) noexcept : value(std::move(src.value)) {}
#endif
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::~infra_code_unit() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const std::uint16_t value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_unit::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_uint16& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_unit::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_uint16&& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_code_unit::value = std::move(value);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_code_unit& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = src.value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_code_unit&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = std::move(src.value);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator std::uint16_t() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator infra_uint16() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}

//-------------//

// WHATWG code unit member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_code_unit::code_unit_str() const noexcept
{
    std::stringstream out;
    out << *this;
    return out.str();
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_leading_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0xD800 <= value && value <= 0xD8FF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_trailing_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0xDC00 <= value && value <= 0xDFFF;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_surrogate() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0xD800 <= value && value <= 0xD8FF) || (0xDC00 <= value && value <= 0xDFFF);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_scalar() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return !((0xD800 <= value && value <= 0xD8FF) || (0xDC00 <= value && value <= 0xDFFF));
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_nonchar() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    switch (value)
    {
    case 0xFFFE:
    case 0xFFFF: return true;
    default: return 0xFDD0 <= value && value <= 0xFDEF;
    }
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_ascii() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x7F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_ascii_tab_or_newline() const noexcept
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
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_whitespace() const noexcept
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
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_C0_control() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_C0_control_or_space() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value == 0x20 || value <= 0x1F;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_control() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value <= 0x1F || (0x7F <= value && value <= 0x9F);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_digit() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x30 <= value && value <= 0x39;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_upper_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x46);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_lower_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x61 <= value && value <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_hex() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x46) || (0x61 <= value && value <= 0x66);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_upper() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x41 <= value && value <= 0x5A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_lower() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return 0x61 <= value && value <= 0x7A;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_alpha() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x41 <= value && value <= 0x5A) || (0x61 <= value && value <= 0x7A);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_code_unit::is_alnum() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return (0x30 <= value && value <= 0x39) || (0x41 <= value && value <= 0x5A) || (0x61 <= value && value <= 0x7A);
}

//-----------------------------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_unit::primitive_type() const noexcept { return infra_primitive_type::infra_code_unit; }
SOFTLOQ_WHATWG_INFRA_API void infra_code_unit::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    out << "0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value;
}

//---------------------------------//
}