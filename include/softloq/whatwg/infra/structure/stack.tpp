/**
 * @file stack.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra stack data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/stack.hpp"

namespace softloq::whatwg
{
// Member functions //

template <class T> std::optional<T> infra_stack<T>::peek() const noexcept
{
    if (infra_list<T>::empty()) return {};
    return infra_list<T>::back();
}
template <class T> void infra_stack<T>::push(const_reference item) noexcept { infra_list<T>::push_back(item); }
template <class T> void infra_stack<T>::push(value_type&& item) noexcept { infra_list<T>::push_back(std::move(item)); }
template <class T> std::optional<T> infra_stack<T>::pop() noexcept
{
    if (infra_list<T>::empty()) return {};
    value_type back = infra_list<T>::back();
    infra_list<T>::pop_back();
    return back;
}

//------------------//
}