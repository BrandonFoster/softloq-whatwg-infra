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
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence() noexcept
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const std::initializer_list<infra_byte>& values) noexcept
: infra_sequence<infra_byte>(values)
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const std::string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*this), [](const char c) { return infra_byte{c}; });
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const std::u8string& values) noexcept
{
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*this), [](const std::uint8_t c) { return infra_byte{c}; });
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(const infra_byte_sequence& src) noexcept
: infra_sequence<infra_byte>(*static_cast<const sequence_type*>(this))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::infra_byte_sequence(infra_byte_sequence&& src) noexcept
: infra_sequence<infra_byte>(std::move(*static_cast<sequence_type*>(this)))
{
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence::~infra_byte_sequence() noexcept
{
}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const std::string& values) noexcept
{
    this->clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*this), [](const char c) { return infra_byte{c}; });
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const std::u8string& values) noexcept
{
    this->clear();
    std::transform(values.cbegin(), values.cend(), std::back_inserter(*this), [](const std::uint8_t c) { return infra_byte{c}; });
    return *this;

}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(const infra_byte_sequence& src) noexcept
{
    *static_cast<sequence_type*>(this) = *static_cast<const sequence_type*>(&src);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& infra_byte_sequence::operator=(infra_byte_sequence&& src) noexcept
{
    *static_cast<sequence_type*>(this) = std::move(*static_cast<const sequence_type*>(&src));
    return *this;
}

//-------------//

// WHATWG byte sequence member functions //

SOFTLOQ_WHATWG_INFRA_API std::string infra_byte_sequence::byte_string() const noexcept
{
    std::stringstream out;
    auto curr_it = cbegin();
    auto last_it = cend();
    for(const auto& item: *this)
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
    for(const auto& item: *this) out << static_cast<char>(static_cast<const std::uint8_t>(item));
    out << "`";
    return out.str();
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_byte_sequence::lowercase() const noexcept
{
    infra_byte_sequence sequence;
    std::transform(cbegin(), cend(), std::back_inserter(sequence), [](const auto& byte) { return std::tolower(static_cast<std::uint8_t>(byte)); });
    return sequence;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence infra_byte_sequence::uppercase() const noexcept
{
    infra_byte_sequence sequence;
    std::transform(cbegin(), cend(), std::back_inserter(sequence), [](const auto& byte) { return std::toupper(static_cast<std::uint8_t>(byte)); });
    return sequence;
}

//-------------------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_byte_sequence::primitive_type() const noexcept
{
    return infra_primitive_type::infra_byte_sequence;
}
SOFTLOQ_WHATWG_INFRA_API void infra_byte_sequence::print(std::ostream& out) const noexcept
{
    infra_sequence<infra_byte>::print(out);
}

//---------------------------------//

// WHATWG byte sequence comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool infra_byte_sequence::operator<(const infra_byte_sequence& b) const noexcept
{
    return is_byte_less(*this, b);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_byte_sequence::operator>(const infra_byte_sequence& b) const noexcept
{
    return is_byte_less(b, *this);
}
SOFTLOQ_WHATWG_INFRA_API const bool infra_byte_sequence::operator==(const infra_byte_sequence& b) const noexcept
{
    return *static_cast<const sequence_type*>(this) == *static_cast<const sequence_type*>(&b);
}

//-------------------------------------------//

// WHATWG byte sequence comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept
{
    return a.size() <= b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin());
}
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept
{
    if (is_prefix(b, a)) return false;
    else if (is_prefix(a, b)) return true;
    else return std::equal(a.cbegin(), a.cend(), b.cbegin(), std::less_equal<infra_byte>());
}
SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept
{
    return a.size() == b.size() && std::equal(a.cbegin(), a.cend(), b.cbegin(), [](const auto& byte_a, const auto& byte_b) { return std::tolower(static_cast<std::uint8_t>(byte_a)) == std::tolower(static_cast<std::uint8_t>(byte_b)); });
}

//-------------------------------------------//
}