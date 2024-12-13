/**
 * @file byte.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/byte.hpp"

#include <iomanip>

namespace softloq::whatwg::infra
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const primitive_type byte::primitive_type() const noexcept { return primitive_type::byte; }
SOFTLOQ_WHATWG_INFRA_API void byte::print(std::ostream& out) const noexcept { out << "0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API byte::byte() noexcept : value(0x00) {}
SOFTLOQ_WHATWG_INFRA_API byte::byte(const unsigned8& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API byte::byte(const byte& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API byte::byte(byte&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API byte::~byte() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API byte& byte::operator=(const unsigned8& value) noexcept { byte::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API byte& byte::operator=(const byte& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API byte& byte::operator=(byte&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API byte::operator std::uint8_t() const noexcept { return value; }
SOFTLOQ_WHATWG_INFRA_API byte::operator unsigned8() const noexcept { return value; }

//-------------//
}