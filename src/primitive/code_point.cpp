/**
 * @file code_point.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra code point primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/code_point.hpp"

#include <iomanip>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_point::primitive_type() const noexcept { return infra_primitive_type::infra_code_point; }
SOFTLOQ_WHATWG_INFRA_API void infra_code_point::print(std::ostream& out) const noexcept
{
    if (value <= 0x10FFFF) out << "U+" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value;
    else out << "U+<Invalid:" << std::hex << std::uppercase << value << ">";
}

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point() noexcept : value(0x0000) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_uint32& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_uint32&& value) noexcept : value(std::move(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(const infra_code_point& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::infra_code_point(infra_code_point&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_point::~infra_code_point() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_uint32& value) noexcept { infra_code_point::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_uint32&& value) noexcept { infra_code_point::value = std::move(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(const infra_code_point& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_point& infra_code_point::operator=(infra_code_point&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator std::uint32_t() const noexcept { return value; }
SOFTLOQ_WHATWG_INFRA_API infra_code_point::operator infra_uint32() const noexcept { return value; }

//-------------//
}