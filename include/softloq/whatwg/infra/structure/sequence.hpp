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
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra sequence data structure class. Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
template <class T> class infra_sequence : public infra_structure_base
{
public:

    // common member types //

    using container_type = std::vector<T>;
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

    /** @brief Constructs an empty WHATWG infra sequence. */
    infra_sequence() noexcept;
    /** 
     * @brief Constructs a WHATWG infra sequence with an initializer list of values.
     * @param values The initializer list for the sequence. */
    infra_sequence(const std::initializer_list<T>& values) noexcept;
    /** 
     * @brief Constructs a WHATWG infra sequence from another infra sequence.
     * @param values The infra sequence that will be copied. */
    infra_sequence(const infra_sequence& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra sequence from another infra sequence.
     * @param values The infra sequence that will be moved. */
    infra_sequence(infra_sequence&& src) noexcept;
    ~infra_sequence() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra sequence from another infra sequence.
     * @param values The infra sequence that will be copied. */
    infra_sequence& operator=(const infra_sequence& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra sequence from another infra sequence.
     * @param values The infra sequence that will be moved. */
    infra_sequence& operator=(infra_sequence&& src) noexcept;

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

    // WHATWG sequence member functions //

    T& front() noexcept;
    const T& front() const noexcept;
    T& back() noexcept;
    const T& back() const noexcept;
    
    infra_sequence& operator+=(const infra_sequence& sequence) noexcept;

    infra_sequence& operator+=(const T& item) noexcept;
    infra_sequence& operator+=(T&& item) noexcept;

    void extend(const infra_sequence& sequence) noexcept;

    void push_back(const T& item) noexcept;
    void push_back(T&& item) noexcept;
    void pop_back() noexcept;

    const size_type size() const noexcept;
    const bool empty() const noexcept;
    void clear() noexcept;

    T& operator[](const size_type index) noexcept;
    const T& operator[](const size_type index) const noexcept;
    
    //----------------------------------//

    // WHATWG structure base overrides //

    const infra_structure_type structure_type() const noexcept override;
    void print(std::ostream& out) const noexcept override;
    
    //---------------------------------//

    // WHATWG sequence comparison functions //

    const bool operator==(const infra_sequence<T>& b) const noexcept;

    //--------------------------------------//

private:
    std::vector<T> values;

    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex iterator_mtx, main_mtx;
    
    // used for threadsafe copy construction
    infra_sequence(const infra_sequence& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    infra_sequence(infra_sequence&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif
};

template <class T> infra_sequence<T> operator+(const infra_sequence<T>& a, const infra_sequence<T>& b) noexcept;
template <class T> infra_sequence<T> operator+(const infra_sequence<T>& a, const T& b) noexcept;
}

#include "softloq/whatwg/infra/structure/sequence.tpp"

#endif