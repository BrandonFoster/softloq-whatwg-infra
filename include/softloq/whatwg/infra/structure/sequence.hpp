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
    // Standard member types //

    using value_type = T;
    using size_type	= std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = std::vector<T>::iterator;
    using const_iterator = std::vector<T>::const_iterator;
    using reverse_iterator = std::vector<T>::reverse_iterator;
    using const_reverse_iterator = std::vector<T>::const_reverse_iterator;

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

    /** @brief gets the structure type of the class. returns infra_structure_type::infra_sequence. */
    const infra_structure_type structure_type() const noexcept override;
    /**
     * @brief prints the WHATWG infra representation of the sequence data structure to the outstream.
     * @param out the outstream that will be used. */
    void print(std::ostream& out) const noexcept override;
    
    //---------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra sequence data structure with no items. */
    infra_sequence() noexcept;
    /**
     * @brief constructs a WHATWG infra sequence data structure from an initializer_list.
     * @param values the values that will be copied. */
    infra_sequence(const std::initializer_list<T>& values) noexcept;
    /**
     * @brief constructs a WHATWG infra sequence data structure from a vector.
     * @param values the values that will be used. */
    infra_sequence(const std::vector<T>& values) noexcept;
    /**
     * @brief constructs a WHATWG infra sequence data structure from the copy of another.
     * @param src the infra bool primitive that will be copied. */
    infra_sequence(const infra_sequence& src) noexcept;
    /**
     * @brief constructs a WHATWG infra sequence data structure from the L-value of a vector.
     * @param values the values that will be moved. */
    infra_sequence(std::vector<T>&& values) noexcept;
    /**
     * @brief constructs a WHATWG infra sequence data structure from the L-value of another.
     * @param src the infra sequence data structure that will be moved. */
    infra_sequence(infra_sequence&& src) noexcept;
    /** @brief applies default destructor. */
    ~infra_sequence() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra sequence data structure from a vector.
     * @param values the values that will be used. */
    infra_sequence& operator=(const std::vector<T>& values) noexcept;
    /**
     * @brief assigns a WHATWG infra sequence data structure from the copy of another.
     * @param src the infra sequence data structure that will be copied. */
    infra_sequence& operator=(const infra_sequence& src) noexcept;
    /**
     * @brief assigns a WHATWG infra sequence data structure from the L-value of a vector.
     * @param values the values that will be moved. */
    infra_sequence& operator=(std::vector<T>&& values) noexcept;
    /**
     * @brief assigns a WHATWG infra sequence data structure from the L-value of another.
     * @param src the infra sequence data structure that will be moved. */
    infra_sequence& operator=(infra_sequence&& src) noexcept;

    //-------------//

    // Sequence functions //

    /** @brief gets the item in the front. */
    reference front() noexcept;
    /** @brief gets the item in the front. */
    const_reference front() const noexcept;
    /** @brief gets the item in the back. */
    reference back() noexcept;
    /** @brief gets the item in the back. */
    const_reference back() const noexcept;
    /**
     * @brief appends the item to the end.
     * @param item the item that will be copied. */
    void push_back(const_reference item) noexcept;
    /**
     * @brief appends the item to the end.
     * @param item the item that will be moved. */
    void push_back(T&& item) noexcept;
    /** @brief removes the item from the end. */
    void pop_back() noexcept;
    /** @brief gets the number of items. */
    const size_type size() const noexcept;
    /** @brief returns whether the structure is empty. */
    const bool empty() const noexcept;
    /** @brief clears all of the items. */
    void clear() noexcept;
    /**
     * @brief gets the item at an index.
     * index the index of the item. */
    reference operator[](const size_type index) noexcept;
    /**
     * @brief gets the item at an index.
     * index the index of the item. */
    const_reference operator[](const size_type index) const noexcept;

    // iterator insert(const_iterator pos, const_reference value) noexcept;
    // iterator insert(const_iterator pos, T&& value) noexcept;
    // iterator insert(const_iterator pos, size_type count, const_reference value) noexcept;
    // iterator insert(const_iterator pos, std::initializer_list<T> values) noexcept;
    
    
    //--------------------//

protected:
    std::vector<T> values;
};
}

#include "softloq/whatwg/infra/structure/sequence.tpp"

#endif