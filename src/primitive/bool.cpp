/**
 * @file bool.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/bool.hpp"

namespace softloq::whatwg
{
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool() noexcept
: data(false)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const bool value) noexcept
: data(value)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const infra_bool& src) noexcept
: data(src.data)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(infra_bool&& src) noexcept
: data(std::move(src.data))
{
} 
SOFTLOQ_WHATWG_INFRA_API infra_bool::~infra_bool() noexcept
{
}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const bool value) noexcept
{
    infra_bool::data = data;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const infra_bool& src) noexcept
{
    data = src.data;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(infra_bool&& src) noexcept
{
    data = std::move(src.data);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_bool::operator const bool() const noexcept
{
    return data;
}

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_bool::primitive_type() const noexcept
{
    return infra_primitive_type::infra_bool;
}
SOFTLOQ_WHATWG_INFRA_API void infra_bool::print(std::ostream& out) const noexcept
{
    out << std::boolalpha << data;
}

//---------------------------------//
}