/**
 * @file unsigned.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra number unsigned integer primitive classes.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/unsigned.hpp"

namespace softloq::whatwg::infra
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void unsigned8::print(std::ostream& out) const noexcept { out << static_cast<uint16_t>(value); }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type unsigned8::number_type() const noexcept { return infra::number_type::uint8; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API unsigned8::unsigned8() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API unsigned8::unsigned8(const std::uint8_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned8::unsigned8(const unsigned8& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned8::unsigned8(unsigned8&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API unsigned8::~unsigned8() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API unsigned8& unsigned8::operator=(const std::uint8_t value) noexcept { unsigned8::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned8& unsigned8::operator=(const unsigned8& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned8& unsigned8::operator=(unsigned8&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API unsigned8::operator std::uint8_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void unsigned16::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type unsigned16::number_type() const noexcept { return infra::number_type::uint16; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API unsigned16::unsigned16() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API unsigned16::unsigned16(const std::uint16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned16::unsigned16(const unsigned16& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned16::unsigned16(unsigned16&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API unsigned16::~unsigned16() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API unsigned16& unsigned16::operator=(const std::uint16_t value) noexcept { unsigned16::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned16& unsigned16::operator=(const unsigned16& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned16& unsigned16::operator=(unsigned16&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API unsigned16::operator std::uint16_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void unsigned32::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type unsigned32::number_type() const noexcept { return infra::number_type::uint32; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API unsigned32::unsigned32() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API unsigned32::unsigned32(const std::uint32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned32::unsigned32(const unsigned32& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned32::unsigned32(unsigned32&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API unsigned32::~unsigned32() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API unsigned32& unsigned32::operator=(const std::uint32_t value) noexcept { unsigned32::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned32& unsigned32::operator=(const unsigned32& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned32& unsigned32::operator=(unsigned32&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API unsigned32::operator std::uint32_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void unsigned64::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type unsigned64::number_type() const noexcept { return infra::number_type::uint64; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API unsigned64::unsigned64() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API unsigned64::unsigned64(const std::uint64_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned64::unsigned64(const unsigned64& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API unsigned64::unsigned64(unsigned64&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API unsigned64::~unsigned64() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API unsigned64& unsigned64::operator=(const std::uint64_t value) noexcept { unsigned64::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned64& unsigned64::operator=(const unsigned64& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API unsigned64& unsigned64::operator=(unsigned64&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API unsigned64::operator std::uint64_t() const noexcept { return value; }

//-------------//
}