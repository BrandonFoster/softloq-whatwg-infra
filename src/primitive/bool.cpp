/**
 * @file bool.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/bool.hpp"

namespace softloq::whatwg::infra
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const primitive_type boolean::primitive_type() const noexcept { return primitive_type::boolean; }
SOFTLOQ_WHATWG_INFRA_API void boolean::print(std::ostream& out) const noexcept { out << std::boolalpha << value; }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API boolean::boolean() noexcept : value(false) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(const bool value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(const boolean& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(boolean&& src) noexcept : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API boolean::~boolean() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(const bool value) noexcept { boolean::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(const boolean& src) noexcept { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(boolean&& src) noexcept { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API boolean::operator bool() const noexcept { return value; }

//-------------//
}