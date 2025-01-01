/**
 * @file byte_sequence.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte sequence primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP

#include "softloq/whatwg/infra/structure/sequence.hpp"
#include "softloq/whatwg/infra/primitive/byte.hpp"

#include <initializer_list>

namespace softloq::whatwg
{
/** @brief WHATWG infra byte sequence primitive class */
class infra_byte_sequence: public infra_primitive_base
{
public:

    // command member types //

    using container_type = infra_sequence<infra_byte>;
    using value_type = infra_byte;
    using size_type	= std::size_t;

    //-----------------------//

    // iterator member types //

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;
    using reverse_iterator = container_type::reverse_iterator;
    using const_reverse_iterator = container_type::const_reverse_iterator;

    //-----------------------//

    // constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::initializer_list<infra_byte>& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const infra_byte_sequence& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(infra_byte_sequence&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte_sequence() noexcept;

    //--------------//

    // assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const infra_byte_sequence& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(infra_byte_sequence&& src) noexcept;

    //-------------//

    // iterator member functions //

    SOFTLOQ_WHATWG_INFRA_API iterator begin();
    SOFTLOQ_WHATWG_INFRA_API const_iterator begin() const;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API iterator end();
    SOFTLOQ_WHATWG_INFRA_API const_iterator end() const;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cend() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rbegin();
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rbegin() const;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rend();
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rend() const;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crend() const noexcept;

    //---------------------------//

    // WHATWG sequence member functions //

    SOFTLOQ_WHATWG_INFRA_API infra_byte& front() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_byte& front() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte& back() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_byte& back() const noexcept;
    
    SOFTLOQ_WHATWG_INFRA_API void push_back(const infra_byte& item) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_back(infra_byte&& item) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void pop_back() noexcept;

    SOFTLOQ_WHATWG_INFRA_API const size_type size() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool empty() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API void clear() noexcept;

    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator[](const size_type index) noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_byte& operator[](const size_type index) const noexcept;
    
    //------------------//

    // WHATWG byte sequence member functions //

    SOFTLOQ_WHATWG_INFRA_API std::string byte_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence lowercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence uppercase() const noexcept;

    //-------------------------//

    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG byte sequence comparison functions //

    SOFTLOQ_WHATWG_INFRA_API const bool operator<(const infra_byte_sequence& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator>(const infra_byte_sequence& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator==(const infra_byte_sequence& b) const noexcept;

    //-------------------------------------------//

private:
    infra_sequence<infra_byte> sequence;
};

// WHATWG byte sequence comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;

//-------------------------------------------//

}

#endif