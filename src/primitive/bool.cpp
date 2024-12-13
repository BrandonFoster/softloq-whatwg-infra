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

SOFTLOQ_WHATWG_INFRA_API boolean::boolean() : value(false) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(const bool value) : value(value) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(const boolean& src) : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API boolean::boolean(boolean&& src) : value(std::move(src.value)) {}
SOFTLOQ_WHATWG_INFRA_API boolean::~boolean() {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(const bool value) { boolean::value = value; return *this; }
SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(const boolean& src) { value = src.value; return *this; }
SOFTLOQ_WHATWG_INFRA_API boolean& boolean::operator=(boolean&& src) { value = std::move(src.value); return *this; }

//-------------//

// Conversions //

SOFTLOQ_WHATWG_INFRA_API boolean::operator bool() const { return value; }

//-------------//
}