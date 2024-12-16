/**
 * @file sequence.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra sequence data structure class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_SEQUENCE_HPP

#include "softloq/whatwg/infra/structure/base.hpp"

#include <initializer_list>
#include <vector>

namespace softloq::whatwg
{
/** @brief WHATWG infra sequence data structure class. */
template <class T> class infra_sequence : private std::vector<T>, public infra_structure_base
{
public:
    // Standard member types //

    using value_type = T;
    using container_type = std::vector<value_type>;
    using size_type	= std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;
    using reverse_iterator = container_type::reverse_iterator;
    using const_reverse_iterator = container_type::const_reverse_iterator;

    //-----------------------//

    // Standard iterator functions //

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;

    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    //-----------------------------//

    // WHATWG structure base overrides //

    const infra_structure_type structure_type() const noexcept override;
    void print(std::ostream& out) const noexcept override;
    
    //---------------------------------//

    // Constructors //

    infra_sequence() noexcept;
    infra_sequence(const std::initializer_list<value_type>& values) noexcept;
    infra_sequence(const infra_sequence& src) noexcept;
    infra_sequence(infra_sequence&& src) noexcept;
    ~infra_sequence() noexcept;

    //--------------//

    // Assignments //

    infra_sequence& operator=(const infra_sequence& src) noexcept;
    infra_sequence& operator=(infra_sequence&& src) noexcept;

    //-------------//

    // Member functions //

    reference front() noexcept;
    const_reference front() const noexcept;
    reference back() noexcept;
    const_reference back() const noexcept;
    void push_back(const_reference item) noexcept;
    void push_back(value_type&& item) noexcept;
    void pop_back() noexcept;
    const size_type size() const noexcept;
    const bool empty() const noexcept;
    void clear() noexcept;
    reference operator[](const size_type index) noexcept;
    const_reference operator[](const size_type index) const noexcept;
    
    //------------------//
};
}

#include "softloq/whatwg/infra/structure/sequence.tpp"

#endif