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
/** @brief WHATWG infra byte sequence primitive class (https://infra.spec.whatwg.org/#byte-sequences). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_byte_sequence: public infra_sequence<infra_byte>, public infra_primitive_base
{
public:
    // common member types //

    using sequence_type = infra_sequence<infra_byte>;

    //---------------------//

    // constructors //

    /** @brief Constructs an empty WHATWG infra byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence() noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte sequence with an initializer list.
     * @param values The initializer list for the byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::initializer_list<infra_byte>& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte sequence with a string.
     * @param values The string whose sequence of characters will be used for the byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::string& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte sequence with a u8string.
     * @param values The u8string whose sequence of characters will be used for the byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::u8string& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte sequence from another infra byte sequence.
     * @param values The infra byte sequence that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const infra_byte_sequence& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte sequence from another infra byte sequence.
     * @param values The infra byte sequence that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(infra_byte_sequence&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte_sequence() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra byte sequence with a string.
     * @param values The string whose sequence of characters will be used for the byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::string& values) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte sequence with a u8string.
     * @param values The u8string whose sequence of characters will be used for the byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::u8string& values) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte sequence from another infra byte sequence.
     * @param values The infra byte sequence that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const infra_byte_sequence& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte sequence from another infra byte sequence.
     * @param values The infra byte sequence that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(infra_byte_sequence&& src) noexcept;

    //-------------//

    // WHATWG byte sequence member functions //

    SOFTLOQ_WHATWG_INFRA_API std::string byte_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence lowercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence uppercase() const noexcept;

    //-------------------------//

    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_byte_sequence. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra byte sequence primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG byte sequence comparison functions //

    SOFTLOQ_WHATWG_INFRA_API const bool operator<(const infra_byte_sequence& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator>(const infra_byte_sequence& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator==(const infra_byte_sequence& b) const noexcept;

    //-------------------------------------------//
};

// WHATWG byte sequence comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;

//-------------------------------------------//

}

#endif