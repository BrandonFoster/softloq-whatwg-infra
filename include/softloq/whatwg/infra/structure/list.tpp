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

template <class T> infra_list<T>::infra_list() noexcept
{
}
template <class T> infra_list<T>::infra_list(const std::initializer_list<T>& values) noexcept
: data(values)
{
}
template <class T> infra_list<T>::infra_list(const infra_list& src) noexcept
: infra_list(src, std::lock_guard<std::mutex>(src.mtx))
{
}
template <class T> infra_list<T>::infra_list(infra_list&& src) noexcept
: infra_list(std::move(src), std::lock_guard<std::mutex>(src.mtx))
{
}
template <class T> infra_list<T>::infra_list(const infra_list& src, const std::lock_guard<std::mutex>&) noexcept
: data(src.data)
{
}
template <class T> infra_list<T>::infra_list(infra_list&& src, const std::lock_guard<std::mutex>&) noexcept
: data(std::move(src.data))
{
}
template <class T> infra_list<T>::~infra_list() noexcept
{
}

//--------------//

// assignments //

template <class T> infra_list<T>& infra_list<T>::operator=(const infra_list& src) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    data = src.data;
    return *this;
}
template <class T> infra_list<T>& infra_list<T>::operator=(infra_list&& src) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    data = std::move(src.data);
    return *this;
}

//-------------//

// iterator member functions //

template <class T> infra_list<T>::iterator infra_list<T>::begin()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.begin();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::begin() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.begin();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::cbegin() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.cbegin();
}

template <class T> infra_list<T>::iterator infra_list<T>::end()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.end();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::end() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.end();
}
template <class T> infra_list<T>::const_iterator infra_list<T>::cend() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.cend();
}

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rbegin()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rbegin();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rbegin() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rbegin();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crbegin() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.crbegin();
}

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rend()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rend();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rend() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rend();
}
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crend() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.crend();
}

//---------------------------//

// WHATWG list member functions //

template <class T> T& infra_list<T>::front() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.front();
}
template <class T> const T& infra_list<T>::front() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.front();
}
template <class T> T& infra_list<T>::back() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.back();
}
template <class T> const T& infra_list<T>::back() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.back();
}

template <class T> void infra_list<T>::append(const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(item);
}
template <class T> void infra_list<T>::append(T&& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(std::move(item));
}
template <class T> void infra_list<T>::pop_back() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.pop_back();
}

template <class T> void infra_list<T>::prepend(const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_front(item);
}
template <class T> void infra_list<T>::prepend(T&& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_front(std::move(item));
}
template <class T> void infra_list<T>::pop_front() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.pop_front();
}

template <class T> void infra_list<T>::extend(const infra_list& list) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> list_lock(list.mtx);
    data.insert_range(data.cend(), list.data);
}
template <class T> void infra_list<T>::extend(infra_list&& list) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> list_lock(list.mtx);
    data.insert_range(data.cend(), std::move(list.data));
}

template <class T> void infra_list<T>::replace(const T& item, const std::function<const bool (const T& item)>& cond) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::transform(data.cbegin(), data.cend(), data.begin(), [&](auto& x) { return cond(x) ? item : x; });
}

template <class T> void infra_list<T>::insert(const size_type index, const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.insert(std::next(data.cbegin(), index), item);
}
template <class T> void infra_list<T>::insert(const size_type index, T&& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.insert(std::next(data.cbegin(), index), std::move(item));
}

template <class T> void infra_list<T>::remove(const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.remove(item);
}
template <class T> void infra_list<T>::remove_if(const std::function<const bool (const T& item)>& cond) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.remove_if(cond);
}

template <class T> const infra_list<T>::size_type infra_list<T>::size() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.size();
}
template <class T> const bool infra_list<T>::empty() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.empty();
}
template <class T> void infra_list<T>::clear() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.clear();
}

template <class T> const bool infra_list<T>::contains(const T& item) const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    for (const auto& x: data) if (item == x) return true;
    return false;
}
template <class T> infra_list<T> infra_list<T>::clone() const noexcept
{
    return *this;
}
template <class T> void infra_list<T>::sort_ascending() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.sort(std::less<T>());
}
template <class T> void infra_list<T>::sort_descending() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.sort(std::greater<T>());
}

//------------------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_list<T>::structure_type() const noexcept
{
    return infra_structure_type::infra_list;
}
template <class T> void infra_list<T>::print(std::ostream& out) const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    auto curr_it = data.cbegin();
    auto last_it = data.cend();
    out << "« ";
    for(const T& item: data) out << item << (++curr_it != last_it ? ", " : " ");
    out << "»";
}

//---------------------------------//
}