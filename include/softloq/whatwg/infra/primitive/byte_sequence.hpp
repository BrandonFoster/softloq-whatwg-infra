#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP

#include "softloq/whatwg/infra/structure/sequence.hpp"
#include "softloq/whatwg/infra/primitive/byte.hpp"

namespace softloq::whatwg
{
class infra_byte_sequence: public infra_sequence<infra_byte>, public infra_primitive_base
{
public:
    using infra_sequence<infra_byte>::infra_sequence;

    // WHATWG primitive base overrides //

    /** @brief gets the primitive type of the class. returns infra_primitive_type::infra_byte_sequence. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /** @brief enables the output stream operator << on the byte sequence primitive class. */
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_byte_sequence& sequence) noexcept;
    /**
     * @brief prints the WHATWG infra representation of the byte sequence primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const infra_byte_sequence& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(infra_byte_sequence&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte_sequence() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra byte sequence from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::string& values) noexcept;
    /**
     * @brief assigns a WHATWG infra byte sequence from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::u8string& values) noexcept;
    /**
     * @brief assigns a WHATWG infra byte sequence from the copy of another.
     * @param src the byte sequence primative that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const infra_byte_sequence& src) noexcept;
    /**
     * @brief assigns a WHATWG infra byte sequence from the L-value of another.
     * @param src the byte sequence primative that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(infra_byte_sequence&& src) noexcept;

    //-------------//

    // Byte sequence functions //

    SOFTLOQ_WHATWG_INFRA_API std::string byte_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence lowercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence uppercase() const noexcept;
    
    SOFTLOQ_WHATWG_INFRA_API friend const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
    SOFTLOQ_WHATWG_INFRA_API friend const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
    SOFTLOQ_WHATWG_INFRA_API friend const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;

    //-------------------------//
};
}

#endif