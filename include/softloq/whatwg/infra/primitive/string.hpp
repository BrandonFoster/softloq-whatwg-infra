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
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra string primitive class (https://infra.spec.whatwg.org/#strings). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_string: public infra_primitive_base
{
public:

    // common member types //

    using tokens_type = infra_list<infra_string>;

    using code_unit_sequence_type = infra_sequence<infra_code_unit>;
    using code_point_sequence_type = infra_sequence<infra_code_point>;

    using sequence_type = infra_sequence<infra_code_unit>;
    using value_type = infra_code_unit;
    using size_type = sequence_type::size_type;

    //-----------------------//

    // iterator member types //

    using iterator = sequence_type::iterator;
    using const_iterator = sequence_type::const_iterator;
    using reverse_iterator = sequence_type::reverse_iterator;
    using const_reverse_iterator = sequence_type::const_reverse_iterator;

    //-----------------------//

    // constructors //

    /** @brief Constructs an empty WHATWG infra string. */
    SOFTLOQ_WHATWG_INFRA_API infra_string() noexcept;
    /** 
     * @brief Constructs a WHATWG infra string with an initializer list of code units.
     * @param values The initializer list for the string. */
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::initializer_list<infra_code_unit>& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra string with a string.
     * @param values The string whose sequence of characters will be used for the code units of the infra string. */
    SOFTLOQ_WHATWG_INFRA_API infra_string(const std::string& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra string from another infra string.
     * @param values The infra string that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_string(const infra_string& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra string from another infra string.
     * @param values The infra string that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_string(infra_string&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_string() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra string with a string.
     * @param values The string whose sequence of characters will be used for the code units of the infra string. */
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const std::string& values) noexcept;
    /** 
     * @brief Assigns the WHATWG infra string from another infra string.
     * @param values The infra string that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(const infra_string& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra string from another infra string.
     * @param values The infra string that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator=(infra_string&& src) noexcept;

    //-------------//

    // iterator member functions //

    SOFTLOQ_WHATWG_INFRA_API iterator begin();
    SOFTLOQ_WHATWG_INFRA_API const_iterator begin() const;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API iterator end();
    SOFTLOQ_WHATWG_INFRA_API const_iterator end() const;
    SOFTLOQ_WHATWG_INFRA_API const_iterator cend() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rbegin();
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rbegin() const;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crbegin() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API reverse_iterator rend();
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator rend() const;
    SOFTLOQ_WHATWG_INFRA_API const_reverse_iterator crend() const noexcept;

    //---------------------------//

    // WHATWG string member functions //

    SOFTLOQ_WHATWG_INFRA_API const code_unit_sequence_type& code_units() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const code_point_sequence_type& code_points() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API std::string code_unit_str() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string code_point_str() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API std::string quoted_str() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API infra_string scalar() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API size_type size() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API code_unit_sequence_type::size_type code_unit_size() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API code_point_sequence_type::size_type code_point_size() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API const bool is_ascii() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_isomorphic() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool is_scalar() const noexcept;

    
    SOFTLOQ_WHATWG_INFRA_API infra_string code_unit_substr(const size_type start, const size_type length) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string code_unit_substr(const size_type start) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string code_point_substr(const size_type start, const size_type length) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string code_point_substr(const size_type start) const noexcept;

    SOFTLOQ_WHATWG_INFRA_API infra_byte_sequence byte_encoding() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string ascii_lowercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string ascii_uppercase() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string strip_newlines() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string normalize_newlines() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string strip_spaces() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string collapse_spaces() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string collect(const std::function<const bool (const infra_code_point)>& cond) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API void skip_spaces(code_point_sequence_type::size_type& point_pos) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split(const infra_code_point& delim) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split_spaces() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API tokens_type split_commas() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API static infra_string concatenate(const infra_list<infra_string>& list, infra_string separator = {}) noexcept;

    //--------------------------------//

    // WHATWG sequence member functions //
    
    SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& front_code_unit() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_code_point& front_code_point() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& back_code_unit() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const infra_code_point& back_code_point() const noexcept;

    SOFTLOQ_WHATWG_INFRA_API infra_string& operator+=(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator+=(const infra_code_unit& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator+=(infra_code_unit&& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator+=(const infra_code_point& point) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_string& operator+=(infra_code_point&& point) noexcept;
    
    SOFTLOQ_WHATWG_INFRA_API void push_back(const std::string& values) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_back(const infra_code_unit& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_back(infra_code_unit&& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_back(const infra_code_point& point) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_back(infra_code_point&& point) noexcept;

    SOFTLOQ_WHATWG_INFRA_API void pop_code_unit() noexcept;
    SOFTLOQ_WHATWG_INFRA_API void pop_code_point() noexcept;

    SOFTLOQ_WHATWG_INFRA_API const bool empty() const noexcept;
    SOFTLOQ_WHATWG_INFRA_API void clear() noexcept;

    SOFTLOQ_WHATWG_INFRA_API const infra_code_unit& operator[](const code_unit_sequence_type::size_type index) const noexcept;
    
    //----------------------------------//

    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG string comparison functions //

    SOFTLOQ_WHATWG_INFRA_API const bool operator<(const infra_string& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator>(const infra_string& b) const noexcept;
    SOFTLOQ_WHATWG_INFRA_API const bool operator==(const infra_string& b) const noexcept;

    //------------------------------------//

private:
    infra_sequence<infra_code_point> points;
    infra_sequence<infra_code_unit> units;

    // auxiliary member functions //

    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_unit& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(infra_code_unit&& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(const infra_code_point& point) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_unit(infra_code_point&& point) noexcept;

    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_unit& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(infra_code_unit&& unit) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(const infra_code_point& point) noexcept;
    SOFTLOQ_WHATWG_INFRA_API void push_code_point(infra_code_point&& point) noexcept;

    //----------------------------//
};

// auxiliary functions //

SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const std::string& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_code_unit& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_code_point& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API infra_string operator+(const infra_string& a, const infra_string& b) noexcept;

//---------------------//

// WHATWG string comparison functions //

SOFTLOQ_WHATWG_INFRA_API const bool is_prefix(const infra_string& a, const infra_string& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_suffix(const infra_string& a, const infra_string& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_code_unit_less_than(const infra_string& a, const infra_string& b) noexcept;
SOFTLOQ_WHATWG_INFRA_API const bool is_ascii_iequal(const infra_string& a, const infra_string& b) noexcept;

//------------------------------------//
}

#endif