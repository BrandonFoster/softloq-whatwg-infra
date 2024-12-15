/**
 * @file bool.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/bool.hpp"

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_bool::primitive_type() const noexcept { return infra_primitive_type::infra_bool; }
SOFTLOQ_WHATWG_INFRA_API void infra_bool::print(std::ostream& out) const noexcept { out << std::boolalpha << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool() noexcept : value(false) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const bool value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const infra_bool& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(infra_bool&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::~infra_bool() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const bool value) noexcept { infra_bool::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const infra_bool& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(infra_bool&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API infra_bool::operator bool() const noexcept { return value; }

//-------------//
}