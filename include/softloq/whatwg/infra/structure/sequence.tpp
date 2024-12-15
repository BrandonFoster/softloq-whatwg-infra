/**
 * @file sequence.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra sequence data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/sequence.hpp"

namespace softloq::whatwg
{
// Standard iterator functions //

template <class T> infra_sequence<T>::iterator infra_sequence<T>::begin() noexcept { return values.begin(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::begin() const noexcept { return values.begin(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cbegin() const noexcept { return values.cbegin(); }

template <class T> infra_sequence<T>::iterator infra_sequence<T>::end() noexcept { return values.end(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::end() const noexcept { return values.end(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cend() const noexcept { return values.cend(); }

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rbegin() noexcept { return values.rbegin(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rbegin() const noexcept { return values.rbegin(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crbegin() const noexcept { return values.crbegin(); }

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rend() noexcept { return values.rend(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rend() const noexcept { return values.rend(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crend() const noexcept { return values.crend(); }

//-----------------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_sequence<T>::structure_type() const noexcept { return infra_structure_type::infra_sequence; }
template <class T> void infra_sequence<T>::print(std::ostream& out) const noexcept
{
    auto curr_it = cbegin();
    auto last_it = cend();
    for(const_reference item: values)
    {
        out << item;
        if(++curr_it != last_it) out << " ";
    }
}

//---------------------------------//

// Constructors //

template <class T> infra_sequence<T>::infra_sequence() noexcept : values() {}
template <class T> infra_sequence<T>::infra_sequence(const std::initializer_list<T>& values) noexcept : values(values) {}
template <class T> infra_sequence<T>::infra_sequence(const std::vector<T>& values) noexcept : values(values) {}
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept : values(src.values) {}
template <class T> infra_sequence<T>::infra_sequence(std::vector<T>&& values) noexcept : values(std::move(values)) {}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept : values(std::move(src.values)) {}
template <class T> infra_sequence<T>::~infra_sequence() noexcept {}

//--------------//

// Assignments //

template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const std::vector<T>& values) noexcept { infra_sequence<T>::values = values; return *this; }
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const infra_sequence& src) noexcept { values = src.values; return *this; }
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(std::vector<T>&& values) noexcept { infra_sequence<T>::values = std::move(values); return *this; }
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(infra_sequence&& src) noexcept { values = std::move(src.values); return *this; }

//-------------//

// Sequence functions //

template <class T> infra_sequence<T>::reference infra_sequence<T>::front() noexcept { return values.front(); }
template <class T> infra_sequence<T>::const_reference infra_sequence<T>::front() const noexcept { return values.front(); }
template <class T> infra_sequence<T>::reference infra_sequence<T>::back() noexcept { return values.back(); }
template <class T> infra_sequence<T>::const_reference infra_sequence<T>::back() const noexcept { return values.back(); }
template <class T> void infra_sequence<T>::push_back(const_reference item) noexcept { values.push_back(item); }
template <class T> void infra_sequence<T>::push_back(T&& item) noexcept { values.push_back(std::move(item)); }
template <class T> void infra_sequence<T>::pop_back() noexcept { values.pop_back(); }
template <class T> const infra_sequence<T>::size_type infra_sequence<T>::size() const noexcept { return values.size(); }
template <class T> const bool infra_sequence<T>::empty() const noexcept { return values.empty(); }
template <class T> void infra_sequence<T>::clear() noexcept { values.clear(); }
template <class T> infra_sequence<T>::reference infra_sequence<T>::operator[](const size_type index) noexcept { return values[index]; }
template <class T> infra_sequence<T>::const_reference infra_sequence<T>::operator[](const size_type index) const noexcept { return values[index]; }

//--------------------//
}