/**
 * @file string.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra string primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/string.hpp"

#include <algorithm>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_string::primitive_type() const noexcept { return infra_primitive_type::infra_string; }
SOFTLOQ_WHATWG_INFRA_API std::ostream& operator<<(std::ostream& out, const infra_string& sequence) noexcept { sequence.print(out); return out; }
SOFTLOQ_WHATWG_INFRA_API void infra_string::print(std::ostream& out) const noexcept { code_unit_sequence_type::print(out); }

//---------------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string() noexcept {}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const char c) { return infra_code_unit{c}; });
    for(auto value: values) push_code_point(infra_code_point{value});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::u8string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const std::uint8_t c) { return infra_code_unit{c}; });
    for(auto value: values) push_code_point(infra_code_point{value});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::u16string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const std::uint16_t c) { return infra_code_unit{c}; });
    for(auto value: values) push_code_point(infra_code_point{value});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::u32string& values) noexcept
{
    for(auto value: values)
    {
        push_code_unit(infra_code_point{static_cast<std::int32_t>(value)});
        push_code_point(infra_code_point{static_cast<std::int32_t>(value)});
    }
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const infra_string& src) noexcept
:   code_unit_sequence_type{*static_cast<const code_unit_sequence_type*>(&src)},
    code_point_sequence_type{*static_cast<const code_point_sequence_type*>(&src)} {}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(infra_string&& src) noexcept
:   code_unit_sequence_type{std::move(*static_cast<code_unit_sequence_type*>(&src))},
    code_point_sequence_type{std::move(*static_cast<code_point_sequence_type*>(&src))} {}
SOFTLOQ_WHATWG_INFRA_API infra_string::~infra_string() noexcept {}

//--------------//

// Assignments //

SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const std::string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const char c) { return infra_code_unit{c}; });
    code_point_sequence_type::clear();
    for(auto value: values) push_code_point(infra_code_point{value});
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const std::u8string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const std::uint8_t c) { return infra_code_unit{c}; });
    code_point_sequence_type::clear();
    for(auto value: values) push_code_point(infra_code_point{value});
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const std::u16string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const std::uint16_t c) { return infra_code_unit{c}; });
    code_point_sequence_type::clear();
    for(auto value: values) push_code_point(infra_code_point{value});
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const std::u32string& values) noexcept
{
    for(auto value: values)
    {
        push_code_unit(infra_code_point{static_cast<std::int32_t>(value)});
        push_code_point(infra_code_point{static_cast<std::int32_t>(value)});
    }
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const infra_string& src) noexcept
{
    *static_cast<code_unit_sequence_type*>(this) = *static_cast<const code_unit_sequence_type*>(&src);
    *static_cast<code_point_sequence_type*>(this) = *static_cast<const code_point_sequence_type*>(&src);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(infra_string&& src) noexcept
{
    *static_cast<code_unit_sequence_type*>(this) = std::move(*static_cast<code_unit_sequence_type*>(&src));
    *static_cast<code_point_sequence_type*>(this) = std::move(*static_cast<code_point_sequence_type*>(&src));
    return *this;
}

//-------------//

// Member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_string::code_unit_str() const
{
    return "";
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::code_point_str() const
{
    return "";
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::quoted_str() const
{
    return "";
}

SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::scalar() const
{
    return {};
}

//------------------//

// Private member functions //

SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_unit(const infra_code_unit& unit)
{
    code_unit_sequence_type::push_back(static_cast<std::uint16_t>(unit));
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_unit(const infra_code_point& point)
{
    if (point >= 0x10000)
    {
        code_unit_sequence_type::push_back(0xD800 + ((point - 0x10000) >> 10));
        code_unit_sequence_type::push_back(0xDC00 + ((point - 0x10000) & 0x3FF));
    }
    else code_unit_sequence_type::push_back(static_cast<std::uint16_t>(point));
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_point(const infra_code_unit& unit)
{
    if (unit.is_trailing_surrogate() && code_point_sequence_type::size())
    {
        auto end = --code_point_sequence_type::end();
        if (end->is_leading_surrogate())
        {
            *end = ((static_cast<std::uint32_t>(*end) - 0xD800) << 10) + (unit - 0xDC00) + 0x10000;
            return;
        }
    }
    code_point_sequence_type::push_back(infra_code_point{static_cast<std::uint16_t>(unit)});
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_point(const infra_code_point& point)
{
    if (point.is_trailing_surrogate() && code_point_sequence_type::size())
    {
        auto end = --code_point_sequence_type::end();
        if (end->is_leading_surrogate())
        {
            *end = ((static_cast<std::uint32_t>(*end) - 0xD800) << 10) + (point - 0xDC00) + 0x10000;
            return;
        }
    }
    code_point_sequence_type::push_back(point);
}

//--------------------------//
}