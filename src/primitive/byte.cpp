/**
 * @file byte.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/byte.hpp"

#include <iomanip>

namespace softloq::whatwg
{
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte() noexcept
: data(0x00)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const std::int32_t value) noexcept
: data(value)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_uint8& value) noexcept
: data(value)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_uint8&& value) noexcept
: data(std::move(value))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_byte& src) noexcept
: data(src.data)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_byte&& src) noexcept
: data(std::move(src.data))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::~infra_byte() noexcept
{
}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const std::int32_t value) noexcept
{
    infra_byte::data = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_uint8& value) noexcept
{
    infra_byte::data = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_uint8&& value) noexcept
{
    infra_byte::data = std::move(value);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_byte& src) noexcept
{
    data = src.data;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_byte&& src) noexcept
{
    data = std::move(src.data);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_byte::operator std::uint8_t() const noexcept
{
    return data;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::operator infra_uint8() const noexcept
{
    return data;
}

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_byte::primitive_type() const noexcept
{
    return infra_primitive_type::infra_byte;
}
SOFTLOQ_WHATWG_INFRA_API void infra_byte::print(std::ostream& out) const noexcept
{
    out << "0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << data;
}

//---------------------------------//
}