/**
 * @file stack.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra stack data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/stack.hpp"

namespace softloq::whatwg
{
// constructors //

template <class T> infra_stack<T>::infra_stack() noexcept {}
template <class T> infra_stack<T>::infra_stack(const std::initializer_list<T>& values) noexcept : infra_list<T>{values} {}
template <class T> infra_stack<T>::infra_stack(const infra_stack& src) noexcept : infra_list<T>{src.values} {}
template <class T> infra_stack<T>::infra_stack(infra_stack&& src) noexcept : infra_list<T>{std::move(src)} {}
template <class T> infra_stack<T>::~infra_stack() noexcept {}

//--------------//

// assignments //

template <class T> infra_stack<T>& infra_stack<T>::operator=(const infra_stack& src) noexcept { infra_list<T>::values = src.values; return *this; }
template <class T> infra_stack<T>& infra_stack<T>::operator=(infra_stack&& src) noexcept { infra_list<T>::values = std::move(src.values); return *this; }

//-------------//

// WHATWG stack member functions //

template <class T> std::optional<T> infra_stack<T>::peek() const noexcept { return infra_list<T>::empty() ? std::optional<T>{} : infra_list<T>::back(); }
template <class T> void infra_stack<T>::push(const T& item) noexcept { infra_list<T>::push_back(T); }
template <class T> void infra_stack<T>::push(T&& item) noexcept { infra_list<T>::push_back(std::move(T)); }
template <class T> std::optional<T> infra_stack<T>::pop() noexcept
{
    if (infra_list<T>::empty()) return std::optional<T>{};
    std::optional<T> back = infra_list<T>::back();
    infra_list<T>::pop_back();
    return back;
}

//------------------//
}