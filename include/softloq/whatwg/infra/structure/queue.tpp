/**
 * @file queue.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra queue data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/queue.hpp"

namespace softloq::whatwg
{
// Member functions //

template <class T> std::optional<T> infra_queue<T>::peek() const noexcept
{
    if (infra_list<T>::empty()) return {};
    return infra_list<T>::front();
}
template <class T> void infra_queue<T>::enqueue(const_reference item) noexcept { infra_list<T>::push_back(item); }
template <class T> void infra_queue<T>::enqueue(value_type&& item) noexcept { infra_list<T>::push_back(std::move(item)); }
template <class T> std::optional<T> infra_queue<T>::dequeue() noexcept
{
    if (infra_list<T>::empty()) return {};
    value_type front = infra_list<T>::front();
    infra_list<T>::pop_front();
    return front;
}

//------------------//
}