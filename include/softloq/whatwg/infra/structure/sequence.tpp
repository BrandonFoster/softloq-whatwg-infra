/**
 * @file sequence.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra sequence data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/sequence.hpp"
#include <string>

namespace softloq::whatwg
{
// constructors //

template <class T> infra_sequence<T>::infra_sequence() noexcept {}
template <class T> infra_sequence<T>::infra_sequence(const std::initializer_list<T>& values) noexcept : values(values) {}
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept : values(src.values) {}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept : values(std::move(src.values)) {}
template <class T> infra_sequence<T>::~infra_sequence() noexcept {}

//--------------//

// assignments //

template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const infra_sequence& src) noexcept { values = src.values; return *this; }
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(infra_sequence&& src) noexcept { values = std::move(src.values); return *this; }

//-------------//

// iterator member functions //

template <class T> infra_sequence<T>::iterator infra_sequence<T>::begin() { return values.begin(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::begin() const { return values.begin(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cbegin() const noexcept { return values.cbegin(); }

template <class T> infra_sequence<T>::iterator infra_sequence<T>::end() { return values.end(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::end() const { return values.end(); }
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cend() const noexcept { return values.cend(); }

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rbegin() { return values.rbegin(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rbegin() const { return values.rbegin(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crbegin() const noexcept { return values.crbegin(); }

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rend() { return values.rend(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rend() const { return values.rend(); }
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crend() const noexcept { return values.crend(); }

//---------------------------//

// WHATWG sequence member functions //

template <class T> T& infra_sequence<T>::front() noexcept { return values.front(); }
template <class T> const T& infra_sequence<T>::front() const noexcept { return values.front(); }
template <class T> T& infra_sequence<T>::back() noexcept { return values.back(); }
template <class T> const T& infra_sequence<T>::back() const noexcept { return values.back(); }

template <class T> void infra_sequence<T>::push_back(const T& item) noexcept { values.push_back(T); }
template <class T> void infra_sequence<T>::push_back(T&& item) noexcept { values.push_back(std::move(T)); }
template <class T> void infra_sequence<T>::pop_back() noexcept { values.pop_back(); }

template <class T> const infra_sequence<T>::size_type infra_sequence<T>::size() const noexcept { return values.size(); }
template <class T> const bool infra_sequence<T>::empty() const noexcept { return values.empty(); }
template <class T> void infra_sequence<T>::clear() noexcept { values.clear(); }

template <class T> T& infra_sequence<T>::operator[](const size_type index) noexcept { return values[index]; }
template <class T> const T& infra_sequence<T>::operator[](const size_type index) const noexcept { return values[index]; }

//------------------//
}