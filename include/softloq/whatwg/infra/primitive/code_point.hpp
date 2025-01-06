/**
 * @file code_point.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code point primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra code point primitive class (https://infra.spec.whatwg.org/#code-points). */
class infra_code_point final: public infra_primitive_base
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
    /** @brief Default destructor. */
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

    /** @brief Checks if the code point is within the range of U+0000 to U+10FFFF, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_valid() const noexcept;
    /** @brief Checks if the code point is within the range of U+D800 to U+DBFF, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_leading_surrogate() const noexcept;
    /** @brief Checks if the code point is within the range of U+DC00 to U+DFFF, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_trailing_surrogate() const noexcept;
    /** @brief Checks if the code point is a leading surrogate or trailing surrogate. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_surrogate() const noexcept;
    /** @brief Checks if the code point is not a surrogate. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const noexcept;
    /** 
     * @brief Checks if the code point is within the range of U+FDD0 to U+FDEF, inclusive,
     * or U+FFFE, U+FFFF, U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, U+3FFFE,
     * U+3FFFF, U+4FFFE, U+4FFFF, U+5FFFE, U+5FFFF, U+6FFFE, U+6FFFF, U+7FFFE, U+7FFFF, U+8FFFE, U+8FFFF, U+9FFFE, U+9FFFF, U+AFFFE, U+AFFFF, U+BFFFE, U+BFFFF, U+CFFFE, U+CFFFF, U+DFFFE, U+DFFFF, U+EFFFE, U+EFFFF, U+FFFFE, U+FFFFF,
     * U+10FFFE, or U+10FFFF. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_nonchar() const noexcept;
    /** @brief Checks if the code point is within the range of U+0000 NULL to U+007F DELETE, inclusive */
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const noexcept;
    /** @brief Checks if the code point is U+0009 TAB, U+000A LF, or U+000D CR. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_tab_or_newline() const noexcept;
    /** @brief Checks if the code point is U+0009 TAB, U+000A LF, U+000C FF, U+000D CR, or U+0020 SPACE. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_whitespace() const noexcept;
    /** @brief Checks if the code point is within the range of U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control() const noexcept;
    /** @brief Checks if the code point is a C0 control or U+0020 SPACE. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control_or_space() const noexcept;
    /** @brief Checks if the code point is a C0 control or a code point within the range of U+007F DELETE to U+009F APPLICATION PROGRAM COMMAND, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_control() const noexcept;
    /** @brief Checks if the code point is within the range of U+0030 (0) to U+0039 (9), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_digit() const noexcept;
    /** @brief Checks if the code point is an ASCII digit or a code point within the range of U+0041 (A) to U+0046 (F), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper_hex() const noexcept;
    /** @brief Checks if the code point is an ASCII digit or a code point within the range of U+0061 (a) to U+0066 (f), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower_hex() const noexcept;
    /** @brief Checks if the code point is an ASCII upper hex digit or ASCII lower hex digit. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_hex() const noexcept;
    /** @brief Checks if the code point is within the range of U+0041 (A) to U+005A (Z), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper() const noexcept;
    /** @brief Checks if the code point is within the range of U+0061 (a) to U+006A (z), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower() const noexcept;
    /** @brief Checks if the code point is an ASCII upper alpha or ASCII lower alpha. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_alpha() const noexcept;
    /** @brief Checks if the code point is an ASCII digit or ASCII alpha. */
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
    infra_uint32 data;
};
}

#endif