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
/** @brief WHATWG infra byte sequence primitive class (https://infra.spec.whatwg.org/#byte-sequences). Inheritly thread-safe. */
class infra_byte_sequence final: public infra_sequence<infra_byte>, public infra_primitive_base
{
public:
    // common member types //

    /** @brief The sequence type that is used internally. */
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
    /** @brief Default destructor. */
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

    /** @brief Returns a space delimited string of each byte character in their 0x notation. */
    SOFTLOQ_WHATWG_INFRA_API std::string byte_string() const noexcept;
    /** @brief Returns a backtick quoted string of the UTF-8 encoded byte sequence. */
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_string() const noexcept;
    /** @brief Returns the byte sequence in ascii lowercase format. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence lowercase() const noexcept;
    /** @brief Returns the byte sequence in ascii uppercase format. */
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

    /**
     * @brief Applies byte less than algorithm. The algorithm is explained in (https://infra.spec.whatwg.org/#byte-sequences).
     * @param b The sequence that will be compared.
     * @note this sequence < b iff this sequence is byte less than b. */
    SOFTLOQ_WHATWG_INFRA_API const bool operator<(const infra_byte_sequence& b) const noexcept;
    /**
     * @brief Applies byte less than algorithm. The algorithm is explained in (https://infra.spec.whatwg.org/#byte-sequences).
     * @param b The sequence that will be compared.
     * @note this sequence > b iff b is byte less than this sequence. */
    SOFTLOQ_WHATWG_INFRA_API const bool operator>(const infra_byte_sequence& b) const noexcept;
    /**
     * @brief Determines if both sequence contains the same sequence of bytes.
     * @param b The sequence that will be compared. */
    SOFTLOQ_WHATWG_INFRA_API const bool operator==(const infra_byte_sequence& b) const noexcept;

    //-------------------------------------------//
};

// WHATWG byte sequence comparison functions //

/**
 * @brief Applies potential prefix algorithm. The algorithm is explained in (https://infra.spec.whatwg.org/#byte-sequences).
 * 
 * @param a The sequence that will be checked as the prefix of the entire sequence.
 * @param b The sequence that will be used as the entire sequence.
 * @note a is a prefix of b iff the sequence of bytes in a appears at the beginning of b.
 */
SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
/**
 * @brief Applies byte less than algorithm. The algorithm is explained in (https://infra.spec.whatwg.org/#byte-sequences).
 * 
 * @param a The sequence that will be compared.
 * @param b The sequence that will be compared.
 */
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
/**
 * @brief Applies case-insensitive equal algorithm. The algorithm is explained in (https://infra.spec.whatwg.org/#byte-sequences).
 * 
 * @param a The sequence that will be compared.
 * @param b The sequence that will be compared.
 * @note a is iequal to b iff the lowercase sequence of bytes in a is the same as the lowercase sequence of bytes in b.
 */
SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;

//-------------------------------------------//

}

#endif