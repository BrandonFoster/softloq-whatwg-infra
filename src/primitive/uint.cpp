/**
 * @file uint.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra number unsigned integer primitive classes.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_uint8::print(std::ostream& out) const noexcept { out << static_cast<uint16_t>(value); }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_uint8::number_type() const noexcept { return infra_number_type::infra_uint8; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_uint8::infra_uint8() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint8::infra_uint8(const std::int32_t value) noexcept : value(static_cast<std::uint8_t>(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint8::infra_uint8(const std::uint8_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint8::infra_uint8(const infra_uint8& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint8::infra_uint8(infra_uint8&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint8::~infra_uint8() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_uint8& infra_uint8::operator=(const std::int32_t value) noexcept { infra_uint8::value = static_cast<std::uint8_t>(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint8& infra_uint8::operator=(const std::uint8_t value) noexcept { infra_uint8::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint8& infra_uint8::operator=(const infra_uint8& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint8& infra_uint8::operator=(infra_uint8&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_uint8::operator std::uint8_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_uint16::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_uint16::number_type() const noexcept { return infra_number_type::infra_uint16; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_uint16::infra_uint16() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint16::infra_uint16(const std::int32_t value) noexcept : value(static_cast<std::uint16_t>(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint16::infra_uint16(const std::uint16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint16::infra_uint16(const infra_uint16& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint16::infra_uint16(infra_uint16&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint16::~infra_uint16() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_uint16& infra_uint16::operator=(const std::int32_t value) noexcept { infra_uint16::value = static_cast<std::uint16_t>(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint16& infra_uint16::operator=(const std::uint16_t value) noexcept { infra_uint16::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint16& infra_uint16::operator=(const infra_uint16& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint16& infra_uint16::operator=(infra_uint16&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_uint16::operator std::uint16_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_uint32::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_uint32::number_type() const noexcept { return infra_number_type::infra_uint32; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_uint32::infra_uint32() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint32::infra_uint32(const std::uint32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint32::infra_uint32(const infra_uint32& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint32::infra_uint32(infra_uint32&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint32::~infra_uint32() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_uint32& infra_uint32::operator=(const std::uint32_t value) noexcept { infra_uint32::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint32& infra_uint32::operator=(const infra_uint32& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint32& infra_uint32::operator=(infra_uint32&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_uint32::operator std::uint32_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_uint64::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_uint64::number_type() const noexcept { return infra_number_type::infra_uint64; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_uint64::infra_uint64() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint64::infra_uint64(const std::uint64_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint64::infra_uint64(const infra_uint64& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint64::infra_uint64(infra_uint64&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_uint64::~infra_uint64() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_uint64& infra_uint64::operator=(const std::uint64_t value) noexcept { infra_uint64::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint64& infra_uint64::operator=(const infra_uint64& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_uint64& infra_uint64::operator=(infra_uint64&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_uint64::operator std::uint64_t() const noexcept { return value; }

//-------------//
}