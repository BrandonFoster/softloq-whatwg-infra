/**
 * @file list.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra list data structure class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_LIST_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_LIST_HPP

#include "softloq/whatwg/infra/structure/base.hpp"

#include <initializer_list>
#include <functional>
#include <list>

namespace softloq::whatwg
{
/** @brief WHATWG infra sequence data structure class. */
template <class T> class infra_list : private std::list<T>, public infra_structure_base
{
public:
    // Standard member types //

    using value_type = T;
    using container_type = std::list<value_type>;
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

    infra_list() noexcept;
    infra_list(const std::initializer_list<value_type>& values) noexcept;
    infra_list(const infra_list& src) noexcept;
    infra_list(infra_list&& src) noexcept;
    ~infra_list() noexcept;

    //--------------//

    // Assignments //

    infra_list& operator=(const infra_list& src) noexcept;
    infra_list& operator=(infra_list&& src) noexcept;

    //-------------//

    // Member functions //

    reference front() noexcept;
    const_reference front() const noexcept;
    reference back() noexcept;
    const_reference back() const noexcept;

    virtual void append(const_reference item) noexcept;
    virtual void append(value_type&& item) noexcept;
    virtual void pop_back() noexcept;

    virtual void prepend(const_reference item) noexcept;
    virtual void prepend(value_type&& item) noexcept;
    virtual void pop_front() noexcept;

    virtual void extend(const infra_list& list) noexcept;
    virtual void extend(infra_list&& list) noexcept;

    virtual void replace(const_reference item, const std::function<const bool (const_reference item)>& cond) noexcept;

    virtual void insert(const size_type index, const_reference item) noexcept;
    virtual void insert(const size_type index, value_type&& item) noexcept;

    virtual void remove(const_reference item) noexcept;
    virtual void remove_if(const std::function<const bool (const_reference item)>& cond) noexcept;
    
    const size_type size() const noexcept;
    const bool empty() const noexcept;
    virtual void clear() noexcept;

    virtual const bool contains(const_reference item) const noexcept;
    infra_list clone() const noexcept;

    void sort_ascending() noexcept;
    void sort_descending() noexcept;
    
    //------------------//
};
}

#include "softloq/whatwg/infra/structure/list.tpp"

#endif