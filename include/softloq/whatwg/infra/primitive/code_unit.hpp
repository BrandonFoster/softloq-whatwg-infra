/**
 * @file code_unit.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra code unit primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_UNIT_HPP

#include "softloq/whatwg/infra/primitive/uint.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra code unit primitive class (https://infra.spec.whatwg.org/#strings). */
class infra_code_unit final: public infra_primitive_base
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
    /** @brief Default destructor. */
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

    /** @brief Checks if the code point is within the range of U+D800 to U+DBFF, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_leading_surrogate() const noexcept;
    /** @brief Checks if the code point is within the range of U+DC00 to U+DFFF, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_trailing_surrogate() const noexcept;
    /** @brief Checks if the code point is a leading surrogate or trailing surrogate. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_surrogate() const noexcept;
    /** @brief Checks if the code point is not a surrogate. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const noexcept;
    /** @brief Checks if the code unit is within the range of U+FDD0 to U+FDEF, inclusive, or U+FFFE, or U+FFFF. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_nonchar() const noexcept;
    /** @brief Checks if the code unit is within the range of U+0000 NULL to U+007F DELETE, inclusive */
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const noexcept;
    /** @brief Checks if the code unit is U+0009 TAB, U+000A LF, or U+000D CR. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_tab_or_newline() const noexcept;
    /** @brief Checks if the code unit is U+0009 TAB, U+000A LF, U+000C FF, U+000D CR, or U+0020 SPACE. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_whitespace() const noexcept;
    /** @brief Checks if the code unit is within the range of U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control() const noexcept;
    /** @brief Checks if the code unit is a C0 control or U+0020 SPACE. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_C0_control_or_space() const noexcept;
    /** @brief Checks if the code unit is a C0 control or a code unit within the range of U+007F DELETE to U+009F APPLICATION PROGRAM COMMAND, inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_control() const noexcept;
    /** @brief Checks if the code unit is within the range of U+0030 (0) to U+0039 (9), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_digit() const noexcept;
    /** @brief Checks if the code unit is an ASCII digit or a code unit within the range of U+0041 (A) to U+0046 (F), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper_hex() const noexcept;
    /** @brief Checks if the code unit is an ASCII digit or a code unit within the range of U+0061 (a) to U+0066 (f), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower_hex() const noexcept;
    /** @brief Checks if the code unit is an ASCII upper hex digit or ASCII lower hex digit. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_hex() const noexcept;
    /** @brief Checks if the code unit is within the range of U+0041 (A) to U+005A (Z), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_upper() const noexcept;
    /** @brief Checks if the code unit is within the range of U+0061 (a) to U+006A (z), inclusive. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_lower() const noexcept;
    /** @brief Checks if the code unit is an ASCII upper alpha or ASCII lower alpha. */
    SOFTLOQ_WHATWG_INFRA_API const bool is_alpha() const noexcept;
    /** @brief Checks if the code unit is an ASCII digit or ASCII alpha. */
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
    infra_uint16 data;
};
}

#endif