/**
 * @file list.tpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Template implementation of the WHATWG infra list data structure class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/structure/list.hpp"

#include <algorithm>
#include <string>

namespace softloq::whatwg
{
// constructors //

template <class T> infra_list<T>::infra_list() noexcept {}
template <class T> infra_list<T>::infra_list(const std::initializer_list<T>& values) noexcept : values(values) {}
#ifdef SOFTLOQ_MULTITHREADING
template <class T> infra_list<T>::infra_list(const infra_list& src) noexcept : infra_list(src, std::lock_guard<std::mutex>(src.mtx)) {}
template <class T> infra_list<T>::infra_list(infra_list&& src) noexcept : infra_list(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
template <class T> infra_list<T>::infra_list(const infra_list& src, const std::lock_guard<std::mutex>&) noexcept : values(src.values) {}
template <class T> infra_list<T>::infra_list(infra_list&& src, const std::lock_guard<std::mutex>&) noexcept : values(std::move(src.values)) {}
#else
template <class T> infra_list<T>::infra_list(const infra_list& src) noexcept : values(src.values) {}
template <class T> infra_list<T>::infra_list(infra_list&& src) noexcept : values(std::move(src.values)) {}
#endif
template <class T> infra_list<T>::~infra_list() noexcept {}

//--------------//

// assignments //

template <class T> infra_list<T>& infra_list<T>::operator=(const infra_list& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    #endif
    values = src.values;
    return *this;
}
template <class T> infra_list<T>& infra_list<T>::operator=(infra_list&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    #endif
    values = std::move(src.values);
    return *this;
}

//-------------//

// iterator member functions //

template <class T> infra_list<T>::iterator infra_list<T>::begin()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.begin();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::begin() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.begin();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::cbegin() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.cbegin();
}

template <class T> infra_list<T>::iterator infra_list<T>::end()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.end();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::end() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.end();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::cend() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.cend();
}

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rbegin()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rbegin();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rbegin() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rbegin();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crbegin() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.crbegin();
}

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rend()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rend();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rend() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rend();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crend() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.crend();
}

//---------------------------//

// WHATWG list member functions //

template <class T> T& infra_list<T>::front() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.front();
}
template <class T> const T& infra_list<T>::front() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.front();
}
template <class T> T& infra_list<T>::back() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.back();
}
template <class T> const T& infra_list<T>::back() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.back();
}

template <class T> void infra_list<T>::append(const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(item);
}
template <class T> void infra_list<T>::append(T&& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(std::move(item));
}
template <class T> void infra_list<T>::pop_back() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.pop_back();
}

template <class T> void infra_list<T>::prepend(const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_front(item);
}
template <class T> void infra_list<T>::prepend(T&& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_front(std::move(item));
}
template <class T> void infra_list<T>::pop_front() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.pop_front();
}

template <class T> void infra_list<T>::extend(const infra_list& list) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> list_lock(list.mtx);
    #endif
    values.insert_range(values.cend(), list.values);
}
template <class T> void infra_list<T>::extend(infra_list&& list) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> list_lock(list.mtx);
    #endif
    values.insert_range(values.cend(), std::move(list.values));
}

template <class T> void infra_list<T>::replace(const T& item, const std::function<const bool (const T& item)>& cond) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    std::transform(values.cbegin(), values.cend(), values.begin(), [&](auto& x) { return cond(x) ? item : x; });
}

template <class T> void infra_list<T>::insert(const size_type index, const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.insert(std::next(values.cbegin(), index), item);
}
template <class T> void infra_list<T>::insert(const size_type index, T&& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.insert(std::next(values.cbegin(), index), std::move(item));
}

template <class T> void infra_list<T>::remove(const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.remove(item);
}
template <class T> void infra_list<T>::remove_if(const std::function<const bool (const T& item)>& cond) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.remove_if(cond);
}

template <class T> const infra_list<T>::size_type infra_list<T>::size() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.size();
}
template <class T> const bool infra_list<T>::empty() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.empty();
}
template <class T> void infra_list<T>::clear() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.clear();
}

template <class T> const bool infra_list<T>::contains(const T& item) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    for (const auto& x: values) if (item == x) return true;
    return false;
}
template <class T> infra_list<T> infra_list<T>::clone() const noexcept
{
    return *this;
}
template <class T> void infra_list<T>::sort_ascending() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.sort(std::less<T>());
}
template <class T> void infra_list<T>::sort_descending() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.sort(std::greater<T>());
}

//------------------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_list<T>::structure_type() const noexcept { return infra_structure_type::infra_list; }
template <class T> void infra_list<T>::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    auto curr_it = values.cbegin();
    auto last_it = values.cend();
    out << "« ";
    for(const T& item: values) out << item << (++curr_it != last_it ? ", " : " ");
    out << "»";
}

//---------------------------------//
}