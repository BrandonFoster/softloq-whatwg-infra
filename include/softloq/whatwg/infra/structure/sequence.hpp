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

    infra_sequence() noexcept;
    infra_sequence(const std::initializer_list<T>& values) noexcept;
    infra_sequence(const infra_sequence& src) noexcept;
    infra_sequence(infra_sequence&& src) noexcept;
    ~infra_sequence() noexcept;

    //--------------//

    // assignments //

    infra_sequence& operator=(const infra_sequence& src) noexcept;
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
    
    void push_back(const T& item) noexcept;
    void push_back(T&& item) noexcept;
    void pop_back() noexcept;

    const size_type size() const noexcept;
    const bool empty() const noexcept;
    void clear() noexcept;

    T& operator[](const size_type index) noexcept;
    const T& operator[](const size_type index) const noexcept;
    
    //------------------//

private:
    std::vector<T> values;
};
}

#include "softloq/whatwg/infra/structure/sequence.tpp"

#endif