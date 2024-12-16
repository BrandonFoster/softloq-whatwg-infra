/**
 * @file byte.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/byte.hpp"

#include <iomanip>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_byte::primitive_type() const noexcept { return infra_primitive_type::infra_byte; }
SOFTLOQ_WHATWG_INFRA_API void infra_byte::print(std::ostream& out) const noexcept { out << "0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte() noexcept : value(0x00) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const int value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_uint8& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_uint8&& value) noexcept : value(std::move(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_byte& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_byte&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::~infra_byte() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const int value) noexcept { infra_byte::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_uint8& value) noexcept { infra_byte::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_uint8&& value) noexcept { infra_byte::value = std::move(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_byte& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_byte&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_byte::operator std::uint8_t() const noexcept { return value; }
SOFTLOQ_WHATWG_INFRA_API infra_byte::operator infra_uint8() const noexcept { return value; }

//-------------//
}