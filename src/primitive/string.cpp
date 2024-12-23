/**
 * @file string.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra string primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/string.hpp"

#include <sstream>
#include <algorithm>
#include <iostream>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_string::primitive_type() const noexcept { return infra_primitive_type::infra_string; }
SOFTLOQ_WHATWG_INFRA_API std::ostream& operator<<(std::ostream& out, const infra_string& sequence) noexcept { sequence.print(out); return out; }
SOFTLOQ_WHATWG_INFRA_API void infra_string::print(std::ostream& out) const noexcept { code_unit_sequence_type::print(out); }

//---------------------------------//

// Standard iterator functions //

SOFTLOQ_WHATWG_INFRA_API infra_string::iterator infra_string::begin() noexcept { return code_unit_sequence_type::begin(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::begin() const noexcept { return code_unit_sequence_type::begin(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::cbegin() const noexcept { return code_unit_sequence_type::cbegin(); }

SOFTLOQ_WHATWG_INFRA_API infra_string::iterator infra_string::end() noexcept { return code_unit_sequence_type::end(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::end() const noexcept { return code_unit_sequence_type::end(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::cend() const noexcept { return code_unit_sequence_type::cend(); }

SOFTLOQ_WHATWG_INFRA_API infra_string::reverse_iterator infra_string::rbegin() noexcept { return code_unit_sequence_type::rbegin(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::rbegin() const noexcept { return code_unit_sequence_type::rbegin(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::crbegin() const noexcept { return code_unit_sequence_type::crbegin(); }

SOFTLOQ_WHATWG_INFRA_API infra_string::reverse_iterator infra_string::rend() noexcept { return code_unit_sequence_type::rend(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::rend() const noexcept { return code_unit_sequence_type::rend(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::crend() const noexcept { return code_unit_sequence_type::crend(); }

//-----------------------------//

// Constructors //

SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string() noexcept {}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::initializer_list<infra_code_unit>& values) noexcept
:   code_unit_sequence_type{values}
{
    for (auto value: values) push_code_point(infra_code_point{value});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const char c) { return infra_code_unit{static_cast<std::uint8_t>(c)}; });
    for (auto value: values) push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
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
    code_unit_sequence_type::clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*static_cast<code_unit_sequence_type*>(this)), [](const char c) { return infra_code_unit{static_cast<std::uint8_t>(c)}; });
    code_point_sequence_type::clear();
    for (auto value: values) push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
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
    std::stringstream out;
    for (code_unit_sequence_type::size_type i = 0; i < code_unit_sequence_type::size(); ++i)
    {
        out << code_unit_sequence_type::operator[](i);
        if (i != code_unit_sequence_type::size() - 1) out << " ";
    }
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::code_point_str() const
{
    std::stringstream out;
    for (code_point_sequence_type::size_type i = 0; i < code_point_sequence_type::size(); ++i)
    {
        out << code_point_sequence_type::operator[](i);
        if (i != code_point_sequence_type::size() - 1) out << " ";
    }
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::quoted_str() const
{
    std::string quoted = "\"";
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        if (point <= 0x007F)
            quoted += static_cast<char>(point);
        else if (point <= 0x07FF)
        {
            quoted += static_cast<char>(0xC0 + (0x1F & (point >> 6)));
            quoted += static_cast<char>(0x80 + (0x3F & point));
        }
        else if (point <= 0xFFFF)
        {
            quoted += static_cast<char>(0xE0 + (0x0F & (point >> 12)));
            quoted += static_cast<char>(0x80 + (0x3F & (point >> 6)));
            quoted += static_cast<char>(0x80 + (0x3F & point));
        }
        else if (point <= 0x10FFFF)
        {
            quoted += static_cast<char>(0xF0 + (0x07 & (point >> 18)));
            quoted += static_cast<char>(0x80 + (0x3F & (point >> 12)));
            quoted += static_cast<char>(0x80 + (0x3F & (point >> 6)));
            quoted += static_cast<char>(0x80 + (0x3F & point));
        }
    }
    quoted += "\"";
    return quoted;
}

SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::scalar() const
{
    infra_string string;
    code_unit_sequence_type* unit_sequence = static_cast<code_unit_sequence_type*>(&string);
    code_point_sequence_type* point_sequence = static_cast<code_point_sequence_type*>(&string);


    for (const auto& unit: *static_cast<const code_unit_sequence_type*>(this))
    {
        if (unit_sequence->size() && unit.is_surrogate() && point_sequence->back().is_surrogate())
        {
            if (!(point_sequence->back().is_leading_surrogate() && unit.is_trailing_surrogate()))
            {
                unit_sequence->back() = {0xFFFD};
                point_sequence->back() = {0xFFFD};
            }
        }
        string.push_code_unit(unit);
        string.push_code_point(unit);
    }
    if (point_sequence->size() && point_sequence->back().is_surrogate())
    {
        unit_sequence->back() = {0xFFFD};
        point_sequence->back() = {0xFFFD};
    }
    return string;
}

SOFTLOQ_WHATWG_INFRA_API infra_string::size_type infra_string::size() const { return code_unit_sequence_type::size(); }
SOFTLOQ_WHATWG_INFRA_API infra_string::size_type infra_string::code_point_size() const { return code_point_sequence_type::size(); }

SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_ascii() const
{
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        if (!point.is_ascii()) return false;
    }
    return true;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_isomorphic() const
{
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        if (point > 0xFF) return false;
    }
    return true;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_scalar() const
{
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        if (!point.is_scalar()) return false;
    }
    return true;
}

SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_unit_substr(const size_type start, const size_type length) const
{
    infra_string string;
    if (start >= code_unit_sequence_type::size()) return string;
    for (size_type i = start; i - start < length && i < code_unit_sequence_type::size(); ++i)
    {
        string.push_code_unit(code_unit_sequence_type::operator[](i));
        string.push_code_point(code_unit_sequence_type::operator[](i));
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_unit_substr(const size_type start) const
{
    return code_unit_substr(start, code_unit_sequence_type::size());
}

SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_point_substr(const size_type start, const size_type length) const
{
    infra_string string;
    if (start >= code_point_sequence_type::size()) return string;
    for (size_type i = start; i - start < length && i < code_point_sequence_type::size(); ++i)
    {
        string.push_code_unit(code_point_sequence_type::operator[](i));
        string.push_code_point(code_point_sequence_type::operator[](i));
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_point_substr(const size_type start) const
{
    return code_point_substr(start, code_point_sequence_type::size());
}

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_string::byte_encoding() const
{
    return infra_byte_sequence{};
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::ascii_lowercase() const
{
    infra_string string;
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        infra_code_point lowercase{static_cast<std::uint32_t>(std::tolower(static_cast<std::int32_t>(point)))};
        string.push_code_unit(lowercase);
        string.push_code_point(lowercase);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::ascii_uppercase() const
{
    infra_string string;
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        infra_code_point uppercase{static_cast<std::uint32_t>(std::toupper(static_cast<std::int32_t>(point)))};
        string.push_code_unit(uppercase);
        string.push_code_point(uppercase);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::strip_newlines() const
{
    infra_string string;
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
    {
        if (point == 0x000A || point == 0x000D) continue;
        string.push_code_unit(point);
        string.push_code_point(point);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::normalize_newlines() const
{
    infra_string string;
    for (code_point_sequence_type::size_type i = {}; i < code_point_sequence_type::size(); ++i)
    {
        const auto& point = code_point_sequence_type::operator[](i);
        if (string.size() && point == 0x000A)
        {
            auto end = --static_cast<code_point_sequence_type*>(&string)->end();
            if (*end == 0x000D)
            {
                *end = 0x000A;
                *(--static_cast<code_unit_sequence_type*>(&string)->end()) = 0x000A;
                continue;
            }
        }
        string.push_code_unit(point);
        string.push_code_point(point);
    }
    for (auto& unit: *static_cast<code_unit_sequence_type*>(&string))
    {
        if (unit == 0x000D) unit = 0x000A;
    }
    for (auto& point: *static_cast<code_point_sequence_type*>(&string))
    {
        if (point == 0x000D) point = 0x000A;
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::strip_spaces() const
{
    infra_string strip_string;
    code_unit_sequence_type::size_type start_space = {};
    code_unit_sequence_type::size_type end_space = {};
    const code_unit_sequence_type* code_unit_ptr = static_cast<const code_unit_sequence_type*>(this);
    for (auto it = code_unit_ptr->cbegin(); it != code_unit_ptr->cend(); ++it)
    {
        if (*it != 0x20) break;
        start_space++;
    }
    for (auto it = code_unit_ptr->crbegin(); it != code_unit_ptr->crend(); ++it)
    {
        if (*it != 0x20) break;
        end_space++;
    }
    for (code_unit_sequence_type::size_type i = start_space; i < code_unit_ptr->size() - end_space; ++i) strip_string.push_code_unit((*code_unit_ptr)[i]);
    return strip_string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::collapse_spaces() const
{
    infra_string collapse_string;
    code_unit_sequence_type::size_type start_space = {};
    code_unit_sequence_type::size_type end_space = {};
    const code_unit_sequence_type* code_unit_ptr = static_cast<const code_unit_sequence_type*>(this);
    for (auto it = code_unit_ptr->cbegin(); it != code_unit_ptr->cend(); ++it)
    {
        if (*it != 0x20) break;
        start_space++;
    }
    for (auto it = code_unit_ptr->crbegin(); it != code_unit_ptr->crend(); ++it)
    {
        if (*it != 0x20) break;
        end_space++;
    }
    bool found_space = false;
    for (code_unit_sequence_type::size_type i = start_space; i < code_unit_ptr->size() - end_space; ++i)
    {
        const infra_code_unit& unit = (*code_unit_ptr)[i];
        if (found_space)
        {
            if (unit == 0x20) continue;
            found_space = false;
        }
        else if (unit == 0x20) found_space = true;
        collapse_string.push_code_unit((*code_unit_ptr)[i]);
    }
    return collapse_string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::collect(const std::function<const bool (const infra_code_point)>& cond) const
{
    infra_string collect_string;
    for (const auto& point: *static_cast<const code_point_sequence_type*>(this))
        if (cond(point)) collect_string.push_code_point(point);
    return collect_string;
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::skip_spaces(code_point_sequence_type::size_type& point_pos) const
{
    const code_point_sequence_type* code_point_ptr = static_cast<const code_point_sequence_type*>(this);
    for (; point_pos < code_point_ptr->size(); ++point_pos)
    {
        if ((*code_point_ptr)[point_pos] == 0x20) continue;
        break;
    }
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::split(const infra_code_point& delim)
{

}
SOFTLOQ_WHATWG_INFRA_API void infra_string::split_spaces()
{

}
SOFTLOQ_WHATWG_INFRA_API void infra_string::split_commas()
{

}
SOFTLOQ_WHATWG_INFRA_API void infra_string::concatenate()
{

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
    push_code_point(infra_code_point{unit});
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

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_string& a, const infra_string& b)
{
    return a.size() <= b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_suffix(const infra_string& a, const infra_string& b)
{
    return a.size() <= b.size() && std::equal(a.crbegin(), a.crend(), b.crbegin());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_code_unit_less_than(const infra_string& a, const infra_string& b)
{
    if (is_prefix(b, a)) return false;
    else if (is_prefix(a, b)) return true;
    else return std::equal(a.cbegin(), a.cend(), b.cbegin(), std::less_equal<infra_code_unit>());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_iequal(const infra_string& a, const infra_string& b)
{
    return a.size() == b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin(), [](const auto& unit_a, const auto& unit_b) { return std::tolower(static_cast<std::uint16_t>(unit_a)) == std::tolower(static_cast<std::uint16_t>(unit_b)); });
}
}