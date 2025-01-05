/**
 * @file queue.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra queue data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/queue.hpp"

namespace softloq::whatwg
{
// constructors //

template <class T> infra_queue<T>::infra_queue() noexcept {}
template <class T> infra_queue<T>::infra_queue(const std::initializer_list<T>& values) noexcept : infra_list<T>{values} {}
template <class T> infra_queue<T>::infra_queue(const infra_queue& src) noexcept : infra_list<T>{src.values} {}
template <class T> infra_queue<T>::infra_queue(infra_queue&& src) noexcept : infra_list<T>{std::move(src)} {}
template <class T> infra_queue<T>::~infra_queue() noexcept {}

//--------------//

// assignments //

template <class T> infra_queue<T>& infra_queue<T>::operator=(const infra_queue& src) noexcept { infra_list<T>::values = src.values; return *this; }
template <class T> infra_queue<T>& infra_queue<T>::operator=(infra_queue&& src) noexcept { infra_list<T>::values = std::move(src.values); return *this; }

//-------------//

// WHATWG queue member functions //

template <class T> std::optional<T> infra_queue<T>::peek() const noexcept { return infra_list<T>::empty() ? std::optional<T>{} : infra_list<T>::front(); }
template <class T> void infra_queue<T>::enqueue(const T& item) noexcept { infra_list<T>::push_back(T); }
template <class T> void infra_queue<T>::enqueue(T&& item) noexcept { infra_list<T>::push_back(std::move(T)); }
template <class T> std::optional<T> infra_queue<T>::dequeue() noexcept
{
    if (infra_list<T>::empty()) return std::optional<T>{};
    std::optional<T> front = infra_list<T>::front();
    infra_list<T>::pop_front();
    return front;
}

//------------------//
}