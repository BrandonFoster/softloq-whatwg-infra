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
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string() noexcept {}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::initializer_list<infra_code_unit>& values) noexcept
{
    for (const auto& value: values) push_code_point(infra_code_point{value});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const std::string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(units), [](const char c) { return infra_code_unit{static_cast<std::uint8_t>(c)}; });
    for (const auto& value: values) push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(const infra_string& src) noexcept : units(src.units), points(src.points) {}
SOFTLOQ_WHATWG_INFRA_API infra_string::infra_string(infra_string&& src) noexcept : units(std::move(src.units)), points(std::move(src.points)) {}
SOFTLOQ_WHATWG_INFRA_API infra_string::~infra_string() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const std::string& values) noexcept
{
    units.clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(units), [](const char c) { return infra_code_unit{static_cast<std::uint8_t>(c)}; });
    points.clear();
    for (auto value: values) push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(const infra_string& src) noexcept
{
    units = src.units;
    points = src.points;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator=(infra_string&& src) noexcept
{
    units = std::move(src.units);
    points = std::move(src.points);
    return *this;
}

//-------------//

// iterator member functions //

SOFTLOQ_WHATWG_INFRA_API infra_string::iterator infra_string::begin()
{
    return units.begin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::begin() const
{
    return units.begin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::cbegin() const noexcept
{
    return units.cbegin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::iterator infra_string::end()
{
    return units.end();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::end() const
{
    return units.end();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_iterator infra_string::cend() const noexcept
{ 
    return units.cend();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::reverse_iterator infra_string::rbegin()
{
    return units.rbegin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::rbegin() const
{
    return units.rbegin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::crbegin() const noexcept
{
    return units.crbegin();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::reverse_iterator infra_string::rend()
{
    return units.rend();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::rend() const
{
    return units.rend();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::const_reverse_iterator infra_string::crend() const noexcept
{
    return units.crend();
}

//---------------------------//

// WHATWG string member functions //

SOFTLOQ_WHATWG_INFRA_API const infra_string::code_unit_sequence_type& infra_string::code_units() const noexcept
{
    return units;
}
SOFTLOQ_WHATWG_INFRA_API const infra_string::code_point_sequence_type& infra_string::code_points() const noexcept
{
    return points;
}

SOFTLOQ_WHATWG_INFRA_API std::string infra_string::code_unit_str() const noexcept
{
    std::stringstream out;
    for (code_unit_sequence_type::size_type i = 0; i < units.size(); ++i)
    {
        out << units[i];
        if (i != units.size() - 1) out << " ";
    }
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::code_point_str() const noexcept
{
    std::stringstream out;
    for (code_point_sequence_type::size_type i = 0; i < points.size(); ++i)
    {
        out << points[i];
        if (i != points.size() - 1) out << " ";
    }
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_string::quoted_str() const noexcept
{
    std::string quoted = "\"";
    for (const auto& point: points)
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
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::scalar() const noexcept
{
    infra_string string;
    for (const auto& unit: units)
    {
        if (string.units.size() && unit.is_surrogate() && string.points.back().is_surrogate())
        {
            if (!(string.points.back().is_leading_surrogate() && unit.is_trailing_surrogate()))
            {
                string.units.back() = {0xFFFD};
                string.points.back() = {0xFFFD};
            }
        }
        string.push_code_unit(unit);
        string.push_code_point(unit);
    }
    if (string.points.size() && string.points.back().is_surrogate())
    {
        string.units.back() = {0xFFFD};
        string.points.back() = {0xFFFD};
    }
    return string;
}

SOFTLOQ_WHATWG_INFRA_API infra_string::size_type infra_string::size() const noexcept
{
    return units.size();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::code_unit_sequence_type::size_type infra_string::code_unit_size() const noexcept
{
    return units.size();
}
SOFTLOQ_WHATWG_INFRA_API infra_string::code_point_sequence_type::size_type infra_string::code_point_size() const noexcept
{
    return points.size();
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_ascii() const noexcept
{
    for (const auto& point: points) if (!point.is_ascii()) return false;
    return true;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_isomorphic() const noexcept
{
    for (const auto& point: points) if (point > 0xFF) return false;
    return true;
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::is_scalar() const noexcept
{
    for (const auto& point: points) if (!point.is_scalar()) return false;
    return true;
}

SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_unit_substr(const size_type start, const size_type length) const noexcept
{
    infra_string string;
    if (start >= units.size()) return string;
    for (size_type i = start; i - start < length && i < units.size(); ++i)
    {
        string.push_code_unit(units[i]);
        string.push_code_point(units[i]);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_unit_substr(const size_type start) const noexcept
{
    return code_unit_substr(start, units.size());
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_point_substr(const size_type start, const size_type length) const noexcept
{
    infra_string string;
    if (start >= points.size()) return string;
    for (size_type i = start; i - start < length && i < points.size(); ++i)
    {
        string.push_code_unit(points[i]);
        string.push_code_point(points[i]);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::code_point_substr(const size_type start) const noexcept
{
    return code_point_substr(start, points.size());
}

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_string::byte_encoding() const noexcept
{
    return infra_byte_sequence{};
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::ascii_lowercase() const noexcept
{
    infra_string string;
    for (const auto& point: points)
    {
        infra_code_point lowercase{static_cast<std::uint32_t>(std::tolower(static_cast<std::int32_t>(point)))};
        string.push_code_unit(lowercase);
        string.push_code_point(lowercase);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::ascii_uppercase() const noexcept
{
    infra_string string;
    for (const auto& point: points)
    {
        infra_code_point uppercase{static_cast<std::uint32_t>(std::toupper(static_cast<std::int32_t>(point)))};
        string.push_code_unit(uppercase);
        string.push_code_point(uppercase);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::strip_newlines() const noexcept
{
    infra_string string;
    for (const auto& point: points)
    {
        if (point == 0x000A || point == 0x000D) continue;
        string.push_code_unit(point);
        string.push_code_point(point);
    }
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::normalize_newlines() const noexcept
{
    infra_string string;
    for (code_point_sequence_type::size_type i = {}; i < points.size(); ++i)
    {
        const auto& point = points[i];
        if (string.size() && point == 0x000A)
        {
            auto end = --string.points.end();
            if (*end == 0x000D)
            {
                *end = 0x000A;
                *(--string.units.end()) = 0x000A;
                continue;
            }
        }
        string.push_code_unit(point);
        string.push_code_point(point);
    }
    for (auto& unit: string.units) if (unit == 0x000D) unit = 0x000A;
    for (auto& point: string.points) if (point == 0x000D) point = 0x000A;
    return string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::strip_spaces() const noexcept
{
    infra_string strip_string;
    code_unit_sequence_type::size_type start_space = {};
    code_unit_sequence_type::size_type end_space = {};
    for (auto it = units.cbegin(); it != units.cend(); ++it)
    {
        if (*it != 0x20) break;
        start_space++;
    }
    for (auto it = units.crbegin(); it != units.crend(); ++it)
    {
        if (*it != 0x20) break;
        end_space++;
    }
    for (code_unit_sequence_type::size_type i = start_space; i < units.size() - end_space; ++i) strip_string.push_code_unit(units[i]);
    return strip_string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::collapse_spaces() const noexcept
{
    infra_string collapse_string;
    code_unit_sequence_type::size_type start_space = {};
    code_unit_sequence_type::size_type end_space = {};
    for (auto it = units.cbegin(); it != units.cend(); ++it)
    {
        if (*it != 0x20) break;
        start_space++;
    }
    for (auto it = units.crbegin(); it != units.crend(); ++it)
    {
        if (*it != 0x20) break;
        end_space++;
    }
    bool found_space = false;
    for (code_unit_sequence_type::size_type i = start_space; i < units.size() - end_space; ++i)
    {
        const infra_code_unit& unit = units[i];
        if (found_space)
        {
            if (unit == 0x20) continue;
            found_space = false;
        }
        else if (unit == 0x20) found_space = true;
        collapse_string.push_code_unit(units[i]);
    }
    return collapse_string;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::collect(const std::function<const bool (const infra_code_point)>& cond) const noexcept
{
    infra_string collect_string;
    for (const auto& point: points) if (cond(point)) collect_string.push_code_point(point);
    return collect_string;
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::skip_spaces(code_point_sequence_type::size_type& point_pos) const noexcept
{
    for (; point_pos < points.size(); ++point_pos)
    {
        if (points[point_pos] == 0x20) continue;
        break;
    }
}
SOFTLOQ_WHATWG_INFRA_API infra_string::tokens_type infra_string::split(const infra_code_point& delim) const noexcept
{
    tokens_type tokens;
    infra_string token;
    for (code_point_sequence_type::size_type i = {}; i < points.size(); ++i)
    {
        const auto& code_point = points[i];
        if (code_point == delim)
        {
            tokens.append(token);
            token = {};
        }
        else if (i == points.size() - 1)
        {
            token.push_code_point(code_point);
            tokens.append(token);
        }
        else token.push_code_point(code_point);
    }
    return tokens;
}
SOFTLOQ_WHATWG_INFRA_API infra_string::tokens_type infra_string::split_spaces() const noexcept
{
    tokens_type tokens;
    infra_string token;
    for (code_point_sequence_type::size_type i = {}; i < points.size();)
    {
        const auto& code_point = points[i];
        if (code_point == 0x20)
        {   
            tokens.append(token);
            token = {};
            skip_spaces(++i);
        }
        else if (i == points.size() - 1)
        {
            token.push_code_point(code_point);
            tokens.append(token);
            ++i;
        }
        else
        {
            token.push_code_point(code_point);
            ++i;
        }  
    }
    return tokens;
}
SOFTLOQ_WHATWG_INFRA_API infra_string::tokens_type infra_string::split_commas() const noexcept
{
    tokens_type tokens;
    infra_string token;
    for (code_point_sequence_type::size_type i = {}; i < points.size(); ++i)
    {
        const auto& code_point = points[i];
        if (code_point == 0x2C)
        {
            tokens.append(token.strip_spaces());
            token = {};
        }
        else if (i == points.size() - 1)
        {
            token.push_code_point(code_point);
            tokens.append(token.strip_spaces());
        }
        else token.push_code_point(code_point);
    }
    return tokens;
}
SOFTLOQ_WHATWG_INFRA_API infra_string infra_string::concatenate(const infra_list<infra_string>& list, infra_string separator) noexcept
{
    infra_string concatenate_string;
    for (const auto& string: list)
    {
        if (concatenate_string.size()) for (const auto& unit: separator) concatenate_string.push_code_unit(unit);
        for (const auto& unit: string) concatenate_string.push_code_unit(unit);
    }
    return concatenate_string;
}

//--------------------------------//

// WHATWG sequence member functions //

SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& infra_string::front_code_unit() const noexcept
{
    return units.front();
}
SOFTLOQ_WHATWG_INFRA_API const infra_code_point& infra_string::front_code_point() const noexcept
{
    return points.front();
}
SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& infra_string::back_code_unit() const noexcept
{
    return units.back();
}
SOFTLOQ_WHATWG_INFRA_API const infra_code_point& infra_string::back_code_point() const noexcept
{
    return points.back();
}

SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator+=(const std::string& values) noexcept
{
    for (const auto& value: values)
    {
        push_code_unit(infra_code_unit{static_cast<std::uint8_t>(value)});
        push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
    }
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator+=(const infra_string& values) noexcept
{
    for (const auto& value: values)
    {
        push_code_unit(value);
        push_code_point(value);
    }
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator+=(const infra_code_unit& unit) noexcept
{
    push_code_unit(unit);
    push_code_point(unit);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_string& infra_string::operator+=(const infra_code_point& point) noexcept
{
    push_code_unit(point);
    push_code_point(point);
    return *this;
}

SOFTLOQ_WHATWG_INFRA_API void infra_string::push_back(const std::string& values) noexcept
{
    for (const auto& value: values)
    {
        push_code_unit(infra_code_unit{static_cast<std::uint8_t>(value)});
        push_code_point(infra_code_point{static_cast<std::uint8_t>(value)});
    }
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_back(const infra_string& values) noexcept
{
    for (const auto& value: values)
    {
        push_code_unit(value);
        push_code_point(value);
    }
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_back(const infra_code_unit& unit) noexcept
{
    push_code_unit(unit);
    push_code_point(unit);
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_back(const infra_code_point& point) noexcept
{
    push_code_unit(point);
    push_code_point(point);
}

SOFTLOQ_WHATWG_INFRA_API void infra_string::pop_code_unit() noexcept
{
    if (units.size() >= 2 &&  (++units.rbegin())->is_leading_surrogate() && units.rbegin()->is_trailing_surrogate())
    {
        units.pop_back();
        points.back() = units.back();
    }
    else
    {
        units.pop_back();
        points.pop_back();
    }
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::pop_code_point() noexcept
{
    if (points.back() >= 0x010000)
    {
        units.pop_back();
        units.pop_back();
        points.pop_back();
    }
    else
    {
        units.pop_back();
        points.pop_back();
    }
}

SOFTLOQ_WHATWG_INFRA_API const bool infra_string::empty() const noexcept
{
    return units.size();
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::clear() noexcept
{
    units.clear();
    points.clear();
}

SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& infra_string::operator[](const code_unit_sequence_type::size_type index) const noexcept
{
    return units[index];
}

//----------------------------------//


// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_string::primitive_type() const noexcept
{
    return infra_primitive_type::infra_string;
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::print(std::ostream& out) const noexcept
{
    units.print(out);
}

//---------------------------------//

// auxiliary member functions //

SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_unit(const infra_code_unit& unit) noexcept
{
    units.push_back(static_cast<std::uint16_t>(unit));
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_unit(const infra_code_point& point) noexcept
{
    if (!point.is_valid())
    {
        units.push_back(0xFFFD);
    }
    else if (point >= 0x10000)
    {
        units.push_back(0xD800 + ((point - 0x10000) >> 10));
        units.push_back(0xDC00 + ((point - 0x10000) & 0x3FF));
    }
    else units.push_back(static_cast<std::uint16_t>(point));
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_point(const infra_code_unit& unit) noexcept
{
    push_code_point(infra_code_point{unit});
}
SOFTLOQ_WHATWG_INFRA_API void infra_string::push_code_point(const infra_code_point& point) noexcept
{
    if (point.is_trailing_surrogate() && points.size())
    {
        auto end = --points.end();
        if (end->is_leading_surrogate())
        {
            *end = ((static_cast<std::uint32_t>(*end) - 0xD800) << 10) + (point - 0xDC00) + 0x10000;
            return;
        }
    }
    points.push_back(point);
}

//--------------------------//

// WHATWG string comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool infra_string::operator<(const infra_string& b) const noexcept
{
    return is_code_unit_less_than(*this, b);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::operator>(const infra_string& b) const noexcept
{
    return is_code_unit_less_than(b, *this);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_string::operator==(const infra_string& b) const noexcept
{
    return units == b.units;
}

//------------------------------------//

// auxiliary functions //

SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const std::string& b) noexcept
{
    infra_string combine{a};
    return combine += b;
}
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_string& b) noexcept
{
    infra_string combine{a};
    return combine += b;
}
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_code_unit& b) noexcept
{
    infra_string combine{a};
    return combine += b;
}
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_code_point& b) noexcept
{
    infra_string combine{a};
    return combine += b;
}

//---------------------//

// WHATWG string comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_string& a, const infra_string& b) noexcept
{
    return a.size() <= b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_suffix(const infra_string& a, const infra_string& b) noexcept
{
    return a.size() <= b.size() && std::equal(a.crbegin(), a.crend(), b.crbegin());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_code_unit_less_than(const infra_string& a, const infra_string& b) noexcept
{
    if (is_prefix(b, a)) return false;
    else if (is_prefix(a, b)) return true;
    else return std::equal(a.cbegin(), a.cend(), b.cbegin(), std::less_equal<infra_code_unit>());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_iequal(const infra_string& a, const infra_string& b) noexcept
{
    return a.size() == b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin(), [](const auto& unit_a, const auto& unit_b) { return std::tolower(static_cast<std::uint16_t>(unit_a)) == std::tolower(static_cast<std::uint16_t>(unit_b)); });
}

//------------------------------------//
}