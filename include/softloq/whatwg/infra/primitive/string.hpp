/**
 * @file string.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra string primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP

#include "softloq/whatwg/infra/primitive/byte_sequence.hpp"
#include "softloq/whatwg/infra/primitive/code_unit.hpp"
#include "softloq/whatwg/infra/primitive/code_point.hpp"
#include "softloq/whatwg/infra/structure/list.hpp"

#include <initializer_list>
#include <functional>

namespace softloq::whatwg
{
/** @brief WHATWG infra string primitive class */
class infra_string: private infra_sequence<infra_code_point>, private infra_sequence<infra_code_unit>, public infra_primitive_base
{
public:
    // Standard member types //

    using tokens_type = infra_list<infra_string>;
    using code_unit_sequence_type = infra_sequence<infra_code_unit>;
    using code_point_sequence_type = infra_sequence<infra_code_point>;
    using size_type = code_unit_sequence_type::size_type;
    using iterator = code_unit_sequence_type::iterator;
    using const_iterator = code_unit_sequence_type::const_iterator;
    using reverse_iterator = code_unit_sequence_type::reverse_iterator;
    using const_reverse_iterator = code_unit_sequence_type::const_reverse_iterator;

    //-----------------------//

    // Standard iterator functions //

    SOFTLOQ_WHATWG_INFRA_API iterator begin() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_iterator begin() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API iterator end() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_iterator end() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cend() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rbegin() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rbegin() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rend() noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rend() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crend() const noexcept;

    //-----------------------------//

    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API friend std::ostream& operator<<(std::ostream& out, const infra_string& sequence) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_string() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::initializer_list<infra_code_unit>& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(const infra_string& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string(infra_string&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_string() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const infra_string& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(infra_string&& src) noexcept;

    //-------------//

    // Member functions //

    SOFTLOQ_WHATWG_INFRA_API std::string code_unit_str() const;
    SOFTLOQ_WHATWG_INFRA_API std::string code_point_str() const;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_str() const;

    SOFTLOQ_WHATWG_INFRA_API infra_string scalar() const;

    SOFTLOQ_WHATWG_INFRA_API size_type size() const;
    SOFTLOQ_WHATWG_INFRA_API size_type code_point_size() const;

    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const;
    SOFTLOQ_WHATWG_INFRA_API const bool is_isomorphic() const;
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const;

    
    SOFTLOQ_WHATWG_INFRA_API infra_string code_unit_substr(const size_type start, const size_type length) const;
    SOFTLOQ_WHATWG_INFRA_API infra_string code_unit_substr(const size_type start) const;

    SOFTLOQ_WHATWG_INFRA_API infra_string code_point_substr(const size_type start, const size_type length) const;
    SOFTLOQ_WHATWG_INFRA_API infra_string code_point_substr(const size_type start) const;

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence byte_encoding() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string ascii_lowercase() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string ascii_uppercase() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string strip_newlines() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string normalize_newlines() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string strip_spaces() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string collapse_spaces() const;
    SOFTLOQ_WHATWG_INFRA_API infra_string collect(const std::function<const bool (const infra_code_point)>& cond) const;
    SOFTLOQ_WHATWG_INFRA_API void skip_spaces(code_point_sequence_type::size_type& point_pos) const;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split(const infra_code_point& delim) const;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split_spaces() const;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split_commas() const;
    SOFTLOQ_WHATWG_INFRA_API static infra_string concatenate(const infra_list<infra_string>& list, infra_string separator = {});

    //------------------//

private:
    // Private member functions //

    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_unit& unit);
    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_point& point);
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_unit& unit);
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_point& point);

    //--------------------------//
};

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_string& a, const infra_string& b);
SOFTLOQ_WHATWG_INFRA_API const bool is_suffix(const infra_string& a, const infra_string& b);
SOFTLOQ_WHATWG_INFRA_API const bool is_code_unit_less_than(const infra_string& a, const infra_string& b);
SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_iequal(const infra_string& a, const infra_string& b);
}

#endif