/**
 * @file code_unit.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code unit primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra code unit primitive class (https://infra.spec.whatwg.org/#strings). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_code_unit: public infra_primitive_base
{
public:
    // constructors //

    /** @brief Constructs a WHATWG infra code unit with a default value of 0x0000. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit() noexcept;
    /** 
     * @brief Constructs a WHATWG infra code unit with a 16-bit unsigned integer value.
     * @param value The initial value of the code unit. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const std::uint16_t value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code unit with a infra 16-bit unsigned integer value.
     * @param value The initial value of the code unit that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_uint16& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code unit with a infra 16-bit unsigned integer value.
     * @param value The initial value of the code unit that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_uint16&& value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code unit from another infra code unit.
     * @param value The infra code unit that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_code_unit& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra code unit from another infra code unit.
     * @param value The infra code unit that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_code_unit&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_code_unit() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra code unit with a 16-bit unsigned integer value.
     * @param value The value of the code unit. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const std::uint16_t value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code unit with a infra 16-bit unsigned integer value.
     * @param value The initial value of the code unit that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_uint16& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code unit with a infra 16-bit unsigned integer value.
     * @param value The initial value of the code unit that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_uint16&& value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code unit from another infra code unit.
     * @param value The infra code unit that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(const infra_code_unit& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra code unit from another infra code unit.
     * @param value The infra code unit that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit& operator=(infra_code_unit&& src) noexcept;

    //-------------//

    // conversions //

    /** @brief Converts the WHATWG infra code unit to a C++ 16-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint16_t() const noexcept;
    /** @brief Converts the WHATWG infra code unit to a infra 16-bit unsigned integer value. */
    SOFTLOQ_WHATWG_INFRA_API operator infra_uint16() const noexcept;

    //-------------//

    // WHATWG code unit member functions //

    /** @brief The C++ string representation of the WHATWG infra code unit. */
    SOFTLOQ_WHATWG_INFRA_API std::string code_unit_str() const noexcept;

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

    //-----------------------------------//

    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_code_unit. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra code unit primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//
private:
    infra_uint16 value;

    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex mtx;
    
    // used for threadsafe copy construction
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(const infra_code_unit& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    SOFTLOQ_WHATWG_INFRA_API infra_code_unit(infra_code_unit&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif
};
}

#endif