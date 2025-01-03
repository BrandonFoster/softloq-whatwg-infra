/**
 * @file code_point.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code point primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra code point primitive class (https://infra.spec.whatwg.org/#code-points). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_code_point: public infra_primitive_base
{
public:
    // constructors //

    /** @brief Constructs a WHATWG infra code point with a default value of U+0000. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point() noexcept;
    /** 
     * @brief Constructs a WHATWG infra code point with a 32-bit unsigned integer value.
     * @param value The initial value of the code point. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const std::uint32_t value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code point with a infra 32-bit unsigned integer value.
     * @param value The initial value of the code point that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const infra_uint32& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code point with a infra 32-bit unsigned integer value.
     * @param value The initial value of the code point that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(infra_uint32&& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code point from another infra code point.
     * @param value The infra code point that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const infra_code_point& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code point from another infra code point.
     * @param value The infra code point that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(infra_code_point&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_code_point() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra code point with a 32-bit unsigned integer value.
     * @param value The initial value of the code point. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const std::uint32_t value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code point with a infra 32-bit unsigned integer value.
     * @param value The initial value of the code point that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const infra_uint32& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code point with a infra 32-bit unsigned integer value.
     * @param value The initial value of the code point that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(infra_uint32&& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code point from another infra code point.
     * @param value The infra code point that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(const infra_code_point& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code point from another infra code point.
     * @param value The infra code point that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_point& operator=(infra_code_point&& src) noexcept;

    //-------------//

    // conversions //

    /** @brief Converts the WHATWG infra code point to a C++ 32-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint32_t() const noexcept;
    /** @brief Converts the WHATWG infra code point to a infra 32-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint32() const noexcept;

    //-------------//

    // WHATWG code point member functions //
    
    /** @brief The C++ string representation of the WHATWG infra code point. Ex: U+0000 */
    SOFTLOQ_WHATWG_INFRA_API std::string code_point_str() const noexcept;
    /** @brief The C++ string hex representation of the WHATWG infra code point. Ex: 0x0000 */
    SOFTLOQ_WHATWG_INFRA_API std::string hex_str() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API const bool is_valid() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_leading_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_trailing_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_surrogate() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_nonchar() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_tab_or_newline() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_whitespace() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control_or_space() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_control() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_digit() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_hex() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_alpha() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_alnum() const noexcept;

    //------------------------------------//

    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_code_point. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra code point primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//
private:
    infra_uint32 value;

    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex mtx;
    
    // used for threadsafe copy construction
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(const infra_code_point& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    SOFTLOQ_WHATWG_INFRA_API infra_code_point(infra_code_point&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif
};
}

#endif