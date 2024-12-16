/**
 * @file code_unit.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra code unit primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/code_unit.hpp"

#include <iomanip>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_code_unit::primitive_type() const noexcept { return infra_primitive_type::infra_code_unit; }
SOFTLOQ_WHATWG_INFRA_API void infra_code_unit::print(std::ostream& out) const noexcept { out << "0x" << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit() noexcept : value(0x0000) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const int value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_uint16& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_uint16&& value) noexcept : value(std::move(value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(const infra_code_unit& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::infra_code_unit(infra_code_unit&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::~infra_code_unit() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const int value) noexcept { infra_code_unit::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_uint16& value) noexcept { infra_code_unit::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_uint16&& value) noexcept { infra_code_unit::value = std::move(value); return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(const infra_code_unit& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit& infra_code_unit::operator=(infra_code_unit&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator std::uint16_t() const noexcept { return value; }
SOFTLOQ_WHATWG_INFRA_API infra_code_unit::operator infra_uint16() const noexcept { return value; }

//-------------//
}