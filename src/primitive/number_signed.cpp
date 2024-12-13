/**
 * @file signed.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra number signed integer primitive classes.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/signed.hpp"

namespace softloq::whatwg::infra
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void signed8::print(std::ostream& out) const noexcept { out << static_cast<int16_t>(value); }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type signed8::number_type() const noexcept { return infra::number_type::int8; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API signed8::signed8() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API signed8::signed8(const std::int8_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API signed8::signed8(const signed8& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API signed8::signed8(signed8&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API signed8::~signed8() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API signed8& signed8::operator=(const std::int8_t value) noexcept { signed8::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed8& signed8::operator=(const signed8& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed8& signed8::operator=(signed8&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API signed8::operator std::int8_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void signed16::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type signed16::number_type() const noexcept { return infra::number_type::int16; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API signed16::signed16() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API signed16::signed16(const std::int16_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API signed16::signed16(const signed16& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API signed16::signed16(signed16&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API signed16::~signed16() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API signed16& signed16::operator=(const std::int16_t value) noexcept { signed16::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed16& signed16::operator=(const signed16& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed16& signed16::operator=(signed16&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API signed16::operator std::int16_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void signed32::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type signed32::number_type() const noexcept { return infra::number_type::int32; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API signed32::signed32() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API signed32::signed32(const std::int32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API signed32::signed32(const signed32& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API signed32::signed32(signed32&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API signed32::~signed32() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API signed32& signed32::operator=(const std::int32_t value) noexcept { signed32::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed32& signed32::operator=(const signed32& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed32& signed32::operator=(signed32&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API signed32::operator std::int32_t() const noexcept { return value; }

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API void signed64::print(std::ostream& out) const noexcept { out << value; }

//---------------------------------//

// WHATWG number base overrides //

SOFTLOQ_WHATWG_INFRA_API const number_type signed64::number_type() const noexcept { return infra::number_type::int64; }

//------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API signed64::signed64() noexcept : value(0) {}
SOFTLOQ_WHATWG_INFRA_API signed64::signed64(const std::int64_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API signed64::signed64(const signed64& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API signed64::signed64(signed64&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API signed64::~signed64() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API signed64& signed64::operator=(const std::int64_t value) noexcept { signed64::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed64& signed64::operator=(const signed64& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API signed64& signed64::operator=(signed64&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API signed64::operator std::int64_t() const noexcept { return value; }

//-------------//
}