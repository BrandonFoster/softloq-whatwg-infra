/**
 * @file byte_sequence.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte sequence primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP

#include "softloq/whatwg/infra/structure/sequence.hpp"
#include "softloq/whatwg/infra/primitive/byte.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra byte sequence primitive class */
class infra_byte_sequence: public infra_sequence<infra_byte>, public infra_primitive_base
{
public:
    using infra_sequence<infra_byte>::infra_sequence;

    // Standard member types //

    using container_type = infra_sequence<infra_byte>;

    //-----------------------//
    

    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_byte_sequence& sequence) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(const infra_byte_sequence& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence(infra_byte_sequence&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte_sequence() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(const infra_byte_sequence& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence& operator=(infra_byte_sequence&& src) noexcept;

    //-------------//

    // Byte sequence functions //

    SOFTLOQ_WHATWG_INFRA_API std::string byte_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_string() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence lowercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence uppercase() const noexcept;

    //-------------------------//
};

SOFTLOQ_WHATWG_INFRA_API const bool iequal(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_byte_less(const infra_byte_sequence& a, const infra_byte_sequence& b) noexcept;
}

#endif