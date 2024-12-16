/**
 * @file byte.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra byte primitive class */
class infra_byte: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_byte() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const int value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_uint8& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_uint8&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_byte& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_byte&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const int value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_uint8& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(infra_uint8&& value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_byte& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(infra_byte&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint8() const noexcept;

    //-------------//

private:
    infra_uint8 value;
};
}

#endif