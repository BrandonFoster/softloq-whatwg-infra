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
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra sequence data structure class (https://infra.spec.whatwg.org/#lists). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
template <class T> class infra_list : public infra_structure_base
{
public:
    
    // common member types //

    using container_type = std::list<T>;
    using value_type = T;
    using size_type	= std::size_t;

    //---------------------//

    // iterator member types //

    using iterator = container_type::iterator;
    using const_iterator = container_type::const_iterator;
    using reverse_iterator = container_type::reverse_iterator;
    using const_reverse_iterator = container_type::const_reverse_iterator;

    //-----------------------//

    // constructors //

    /** @brief Constructs an empty WHATWG infra list. */
    infra_list() noexcept;
    /** 
     * @brief Constructs a WHATWG infra list with an initializer list of values.
     * @param values The initializer list for the list. */
    infra_list(const std::initializer_list<T>& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra list from another infra list.
     * @param values The infra list that will be copied. */
    infra_list(const infra_list& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra list from another infra list.
     * @param values The infra list that will be moved. */
    infra_list(infra_list&& src) noexcept;
    ~infra_list() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra list from another infra list.
     * @param values The infra list that will be copied. */
    infra_list& operator=(const infra_list& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra list from another infra list.
     * @param values The infra list that will be moved. */
    infra_list& operator=(infra_list&& src) noexcept;

    //-------------//

    // iterator member functions //

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const noexcept;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const noexcept;

    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crend() const noexcept;

    //---------------------------//

    // WHATWG list member functions //

    T& front() noexcept;
    const T& front() const noexcept;
    T& back() noexcept;
    const T& back() const noexcept;

    virtual void append(const T& item) noexcept;
    virtual void append(T&& item) noexcept;
    virtual void pop_back() noexcept;

    virtual void prepend(const T& item) noexcept;
    virtual void prepend(T&& item) noexcept;
    virtual void pop_front() noexcept;

    virtual void extend(const infra_list& list) noexcept;
    virtual void extend(infra_list&& list) noexcept;

    virtual void replace(const T& item, const std::function<const bool (const T& item)>& cond) noexcept;

    virtual void insert(const size_type index, const T& item) noexcept;
    virtual void insert(const size_type index, T&& item) noexcept;

    virtual void remove(const T& item) noexcept;
    virtual void remove_if(const std::function<const bool (const T& item)>& cond) noexcept;
    
    const size_type size() const noexcept;
    const bool empty() const noexcept;
    virtual void clear() noexcept;

    virtual const bool contains(const T& item) const noexcept;
    infra_list clone() const noexcept;

    void sort_ascending() noexcept;
    void sort_descending() noexcept;
    
    //------------------//

    // WHATWG structure base overrides //

    const infra_structure_type structure_type() const noexcept override;
    void print(std::ostream& out) const noexcept override;
    
    //---------------------------------//

protected:
    std::list<T> values;

    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex mtx;
    
    // used for threadsafe copy construction
    infra_list(const infra_list& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    infra_list(infra_list&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif
};
}

#include "softloq/whatwg/infra/structure/list.tpp"

#endif