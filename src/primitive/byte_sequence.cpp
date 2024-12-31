/**
 * @file byte_sequence.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra byte sequence primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/byte_sequence.hpp"

#include <iomanip>
#include <sstream>
#include <algorithm>

namespace softloq::whatwg
{
// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_byte_sequence::primitive_type() const noexcept { return infra_primitive_type::infra_byte_sequence; }
SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::print(std::ostream& out) const noexcept { sequence.print(out); }

//---------------------------------//

// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence() noexcept {}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const std::string& values) noexcept { std::transform(values.cbegin(), values.cend(), std::back_inserter(sequence), [](const char c) { return infra_byte{c}; }); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const std::u8string& values) noexcept { std::transform(values.cbegin(), values.cend(), std::back_inserter(sequence), [](const std::uint8_t c) { return infra_byte{c}; }); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const infra_byte_sequence& src) noexcept : sequence(src.sequence) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(infra_byte_sequence&& src) noexcept : sequence(std::move(src.sequence)) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::~infra_byte_sequence() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const std::string& values) noexcept
{
    sequence.clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(sequence), [](const char c) { return infra_byte{c}; });
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const std::u8string& values) noexcept
{
    sequence.clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(sequence), [](const std::uint8_t c) { return infra_byte{c}; });
    return *this;

}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const infra_byte_sequence& src) noexcept { sequence = src.sequence; return *this; }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(infra_byte_sequence&& src) noexcept { sequence = std::move(src.sequence); return *this; }

//-------------//

// iterator member functions //

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::iterator infra_byte_sequence::begin() { return sequence.begin(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_iterator infra_byte_sequence::begin() const { return sequence.begin(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_iterator infra_byte_sequence::cbegin() const noexcept { return sequence.cbegin(); }

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::iterator infra_byte_sequence::end() { return sequence.end(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_iterator infra_byte_sequence::end() const { return sequence.end(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_iterator infra_byte_sequence::cend() const noexcept { return sequence.cend(); }

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::reverse_iterator infra_byte_sequence::rbegin() { return sequence.rbegin(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_reverse_iterator infra_byte_sequence::rbegin() const { return sequence.rbegin(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_reverse_iterator infra_byte_sequence::crbegin() const noexcept { return sequence.crbegin(); }

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::reverse_iterator infra_byte_sequence::rend() { return sequence.rend(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_reverse_iterator infra_byte_sequence::rend() const { return sequence.rend(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::const_reverse_iterator infra_byte_sequence::crend() const noexcept { return sequence.crend(); }

//---------------------------//

// WHATWG sequence member functions //

SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte_sequence::front() noexcept { return sequence.front(); }
SOFTLOQ_WHATWG_INFRA_API const infra_byte& infra_byte_sequence::front() const noexcept { return sequence.front(); }
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte_sequence::back() noexcept { return sequence.back(); }
SOFTLOQ_WHATWG_INFRA_API const infra_byte& infra_byte_sequence::back() const noexcept { return sequence.back(); }

SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::push_back(const infra_byte& item) noexcept { sequence.push_back(item); }
SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::push_back(infra_byte&& item) noexcept { sequence.push_back(std::move(item)); }
SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::pop_back() noexcept { sequence.pop_back(); }

SOFTLOQ_WHATWG_INFRA_API const infra_byte_sequence::size_type infra_byte_sequence::size() const noexcept { return sequence.size(); }
SOFTLOQ_WHATWG_INFRA_API const bool infra_byte_sequence::empty() const noexcept { return sequence.empty(); }
SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::clear() noexcept { return sequence.clear(); }

SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte_sequence::operator[](const size_type index) noexcept { return sequence[index]; }
SOFTLOQ_WHATWG_INFRA_API const infra_byte& infra_byte_sequence::operator[](const size_type index) const noexcept { return sequence[index]; }

//------------------//

// WHATWG byte sequence member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_byte_sequence::byte_string() const noexcept
{
    std::stringstream out;
    auto curr_it = cbegin();
    auto last_it = cend();
    for(const auto& item: sequence)
    {
        out << item;
        if(++curr_it != last_it) out << " ";
    }
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API std::string infra_byte_sequence::quoted_string() const noexcept
{
    std::stringstream out;
    out << "`";
    for(const auto& item: sequence) out << static_cast<char>(static_cast<const std::uint8_t>(item));
    out << "`";
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_byte_sequence::lowercase() const noexcept
{
    infra_byte_sequence sequence;
    std::transform(infra_byte_sequence::sequence.cbegin(), infra_byte_sequence::cend(), std::back_inserter(sequence), [](const auto& byte) { return std::tolower(static_cast<std::uint8_t>(byte)); });
    return sequence;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_byte_sequence::uppercase() const noexcept
{
    infra_byte_sequence sequence;
    std::transform(infra_byte_sequence::cbegin(), infra_byte_sequence::cend(), std::back_inserter(sequence), [](const auto& byte) { return std::toupper(static_cast<std::uint8_t>(byte)); });
    return sequence;
}

//-------------------------//

// WHATWG byte sequence comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept { return a.size() <= b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin()); }
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept
{
    if (is_prefix(b, a)) return false;
    else if (is_prefix(a, b)) return true;
    else return std::equal(a.cbegin(), a.cend(), b.cbegin(), std::less_equal<infra_byte>());
}
SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept { return a.size() == b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin(), [](const auto& byte_a, const auto& byte_b) { return std::tolower(static_cast<std::uint8_t>(byte_a)) == std::tolower(static_cast<std::uint8_t>(byte_b)); }); }

//-------------------------------------------//
}