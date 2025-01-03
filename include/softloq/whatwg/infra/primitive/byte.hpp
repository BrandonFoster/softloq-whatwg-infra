/**
 * @file byte.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra byte primitive class (https://infra.spec.whatwg.org/#bytes). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_byte: public infra_primitive_base
{
public:
    // constructors //

    /** @brief Constructs a WHATWG infra byte with a default value of 0x00. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte() noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte with a specified 32-bit signed integer value.
     * @param value The initial value. Will be converted to an 8-bit unsigned integer via underflow/overflow. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const std::int32_t value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte with a infra 8-bit unsigned integer value.
     * @param value The initial value of the byte that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_uint8& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte with a infra 8-bit unsigned integer value.
     * @param value The initial value of the byte that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_uint8&& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte from another infra byte.
     * @param value The infra byte that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_byte& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra byte from another infra byte.
     * @param value The infra byte that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_byte&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_byte() noexcept;

    //--------------//

    // assignments //
    /** 
     * @brief Assigns the WHATWG infra byte with a specified 32-bit signed integer value.
     * @param value The initial value. Will be converted to an 8-bit unsigned integer via underflow/overflow. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const std::int32_t value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte with a infra 8-bit unsigned integer value.
     * @param value The initial value of the byte that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_uint8& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte with a infra 8-bit unsigned integer value.
     * @param value The initial value of the byte that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(infra_uint8&& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte from another infra byte.
     * @param value The infra byte that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(const infra_byte& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra byte from another infra byte.
     * @param value The infra byte that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_byte& operator=(infra_byte&& src) noexcept;

    //-------------//

    // conversions //

    /** @brief Converts the WHATWG infra byte to a C++ 8-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;
    /** @brief Converts the WHATWG infra byte to a infra 8-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint8() const noexcept;

    //-------------//

    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_byte. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra byte primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//
private:
    infra_uint8 value;
    
    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex mtx;
    
    // used for threadsafe copy construction
    SOFTLOQ_WHATWG_INFRA_API infra_byte(const infra_byte& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    SOFTLOQ_WHATWG_INFRA_API infra_byte(infra_byte&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif  
};
}

#endif