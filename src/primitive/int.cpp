/**
 * @file int.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra number signed integer primitive classes.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/int.hpp"

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_int8::print(std::ostream& out) const noexcept { out << static_cast<int16_t>(value); }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_int8::number_type() const noexcept { return infra_number_type::infra_int8; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_int8::infra_int8() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_int8::infra_int8(const int value) noexcept : value(static_cast<std::int8_t>(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int8::infra_int8(const std::int8_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int8::infra_int8(const infra_int8& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int8::infra_int8(infra_int8&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int8::~infra_int8() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_int8& infra_int8::operator=(const int value) noexcept { infra_int8::value = static_cast<std::int8_t>(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int8& infra_int8::operator=(const std::int8_t value) noexcept { infra_int8::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int8& infra_int8::operator=(const infra_int8& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int8& infra_int8::operator=(infra_int8&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_int8::operator std::int8_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_int16::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_int16::number_type() const noexcept { return infra_number_type::infra_int16; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_int16::infra_int16() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_int16::infra_int16(const int value) noexcept : value(static_cast<std::int16_t>(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int16::infra_int16(const std::int16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int16::infra_int16(const infra_int16& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int16::infra_int16(infra_int16&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int16::~infra_int16() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_int16& infra_int16::operator=(const int value) noexcept { infra_int16::value = static_cast<std::int16_t>(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int16& infra_int16::operator=(const std::int16_t value) noexcept { infra_int16::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int16& infra_int16::operator=(const infra_int16& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int16& infra_int16::operator=(infra_int16&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_int16::operator std::int16_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_int32::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_int32::number_type() const noexcept { return infra_number_type::infra_int32; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_int32::infra_int32() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_int32::infra_int32(const std::int32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int32::infra_int32(const infra_int32& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int32::infra_int32(infra_int32&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int32::~infra_int32() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_int32& infra_int32::operator=(const std::int32_t value) noexcept { infra_int32::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int32& infra_int32::operator=(const infra_int32& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int32& infra_int32::operator=(infra_int32&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_int32::operator std::int32_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void infra_int64::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_number_type infra_int64::number_type() const noexcept { return infra_number_type::infra_int64; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_int64::infra_int64() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API infra_int64::infra_int64(const std::int64_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int64::infra_int64(const infra_int64& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_int64::infra_int64(infra_int64&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_int64::~infra_int64() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_int64& infra_int64::operator=(const std::int64_t value) noexcept { infra_int64::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int64& infra_int64::operator=(const infra_int64& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_int64& infra_int64::operator=(infra_int64&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_int64::operator std::int64_t() const noexcept { return value; }

//-------------//
}