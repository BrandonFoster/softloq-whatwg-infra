/**
 * @file string.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra string primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP

#include "softloq/whatwg/infra/structure/sequence.hpp"
#include "softloq/whatwg/infra/primitive/code_unit.hpp"
#include "softloq/whatwg/infra/primitive/code_point.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra string primitive class */
class infra_string: private infra_sequence<infra_code_point>, private infra_sequence<infra_code_unit>, public infra_primitive_base
{
public:
    // Standard member types //

    using code_unit_sequence_type = infra_sequence<infra_code_unit>;
    using code_point_sequence_type = infra_sequence<infra_code_point>;

    //-----------------------//

    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_string& sequence) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_string() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::u16string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::u32string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const infra_string& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(infra_string&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_string() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::u8string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::u16string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::u32string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const infra_string& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(infra_string&& src) noexcept;

    //-------------//

    // Member functions //

    SOFTLOQ_WHATWG_INFRA_API std::string code_unit_str() const;
    SOFTLOQ_WHATWG_INFRA_API std::string code_point_str() const;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_str() const;

    SOFTLOQ_WHATWG_INFRA_API infra_string scalar() const;

    //------------------//

private:
    // Private member functions //

    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_unit& unit);
    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_point& point);
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_unit& unit);
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_point& point);

    //--------------------------//
};
}

#endif