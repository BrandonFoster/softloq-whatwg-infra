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
// Standard iterator functions //

template <class T> infra_list<T>::iterator infra_list<T>::begin() noexcept { return container_type::begin(); }
template <class T> infra_list<T>::const_iterator infra_list<T>::begin() const noexcept { return container_type::begin(); }
template <class T> infra_list<T>::const_iterator infra_list<T>::cbegin() const noexcept { return container_type::cbegin(); }

template <class T> infra_list<T>::iterator infra_list<T>::end() noexcept { return container_type::end(); }
template <class T> infra_list<T>::const_iterator infra_list<T>::end() const noexcept { return container_type::end(); }
template <class T> infra_list<T>::const_iterator infra_list<T>::cend() const noexcept { return container_type::cend(); }

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rbegin() noexcept { return container_type::rbegin(); }
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rbegin() const noexcept { return container_type::rbegin(); }
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crbegin() const noexcept { return container_type::crbegin(); }

template <class T> infra_list<T>::reverse_iterator infra_list<T>::rend() noexcept { return container_type::rend(); }
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::rend() const noexcept { return container_type::rend(); }
template <class T> infra_list<T>::const_reverse_iterator infra_list<T>::crend() const noexcept { return container_type::crend(); }

//-----------------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_list<T>::structure_type() const noexcept { return infra_structure_type::infra_list; }
template <class T> void infra_list<T>::print(std::ostream& out) const noexcept
{
    auto curr_it = cbegin();
    auto last_it = cend();
    for(const_reference item: *this)
    {
        out << item;
        if(++curr_it != last_it) out << " ";
    }
}

//---------------------------------//

// Constructors //

template <class T> infra_list<T>::infra_list() noexcept
:   container_type{} {}
template <class T> infra_list<T>::infra_list(const std::initializer_list<T>& values) noexcept
:   container_type{values} {}
template <class T> infra_list<T>::infra_list(const infra_list& src) noexcept
:   container_type{*static_cast<const container_type*>(&src)} {}
template <class T> infra_list<T>::infra_list(infra_list&& src) noexcept
:   container_type{std::move(*static_cast<container_type*>(&src))} {}
template <class T> infra_list<T>::~infra_list() noexcept {}

//--------------//

// Assignments //

template <class T> infra_list<T>& infra_list<T>::operator=(const infra_list& src) noexcept
{
    *static_cast<container_type*>(this) = *static_cast<const container_type*>(&src);
    return *this;
}
template <class T> infra_list<T>& infra_list<T>::operator=(infra_list&& src) noexcept
{
    *static_cast<container_type*>(this) = std::move(*static_cast<container_type*>(&src));
    return *this;
}

//-------------//

// Member functions //

template <class T> infra_list<T>::reference infra_list<T>::front() noexcept { return container_type::front(); }
template <class T> infra_list<T>::const_reference infra_list<T>::front() const noexcept { return container_type::front(); }
template <class T> infra_list<T>::reference infra_list<T>::back() noexcept { return container_type::back(); }
template <class T> infra_list<T>::const_reference infra_list<T>::back() const noexcept { return container_type::back(); }

template <class T> void infra_list<T>::append(const_reference item) noexcept { container_type::push_back(item); }
template <class T> void infra_list<T>::append(T&& item) noexcept { container_type::push_back(std::move(item)); }
template <class T> void infra_list<T>::pop_back() noexcept { container_type::pop_back(); }

template <class T> void infra_list<T>::prepend(const_reference item) noexcept { container_type::push_front(item); }
template <class T> void infra_list<T>::prepend(T&& item) noexcept { container_type::push_front(std::move(item)); }
template <class T> void infra_list<T>::pop_front() noexcept { container_type::pop_front(); }

template <class T> void infra_list<T>::extend(const infra_list& list) noexcept { container_type::insert_range(cend(), list); }
template <class T> void infra_list<T>::extend(infra_list&& list) noexcept { container_type::insert_range(cend(), std::move(list)); }

template <class T> void infra_list<T>::replace(const value_type& item, const std::function<const bool (const value_type& item)>& cond) noexcept
{
    std::transform(cbegin(), cend(), begin(), [](auto& x) { return cond(x) ? item : x; });
}

template <class T> void infra_list<T>::insert(const size_type index, const value_type& item) noexcept { container_type::insert(cbegin() + index, item); }
template <class T> void infra_list<T>::insert(const size_type index, value_type&& item) noexcept { container_type::insert(cbegin() + index, std::move(item)); }

template <class T> void infra_list<T>::remove(const value_type& item) noexcept { container_type::remove(item); }
template <class T> void infra_list<T>::remove_if(const std::function<const bool (const value_type& item)>& cond) noexcept { container_type::remove_if(cond); }

template <class T> const infra_list<T>::size_type infra_list<T>::size() const noexcept { return container_type::size(); }
template <class T> const bool infra_list<T>::empty() const noexcept { return container_type::empty(); }
template <class T> void infra_list<T>::clear() noexcept { container_type::clear(); }

template <class T> const bool infra_list<T>::contains(const value_type& item) const noexcept
{
    for (const auto& x: *this)
        if (item == x) return true;
    return false;
}
template <class T> infra_list<T> infra_list<T>::clone() const noexcept { return *this; }

template <class T> void infra_list<T>::sort_ascending() noexcept { container_type::sort(std::less<value_type>()); }
template <class T> void infra_list<T>::sort_descending() noexcept { container_type::sort(std::greater<value_type>()); }

//------------------//
}