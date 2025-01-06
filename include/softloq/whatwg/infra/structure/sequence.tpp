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

template <class T> infra_sequence<T>::infra_sequence() noexcept
{
}
template <class T> infra_sequence<T>::infra_sequence(const std::initializer_list<T>& values) noexcept
: data(values)
{
}
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept
: infra_sequence(src, std::lock_guard<std::mutex>(src.mtx))
{
}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept
: infra_sequence(std::move(src), std::lock_guard<std::mutex>(src.mtx))
{
}
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src, const std::lock_guard<std::mutex>&) noexcept
: data(src.data)
{
}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src, const std::lock_guard<std::mutex>&) noexcept
: data(std::move(src.data))
{
}
template <class T> infra_sequence<T>::~infra_sequence() noexcept
{
}

//--------------//

// assignments //

template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const infra_sequence& src) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    data = src.data;
    return *this;
}
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(infra_sequence&& src) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    data = std::move(src.data);
    return *this;
}

//-------------//

// iterator member functions //

template <class T> infra_sequence<T>::iterator infra_sequence<T>::begin()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.begin();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::begin() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.begin();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cbegin() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.cbegin();
}

template <class T> infra_sequence<T>::iterator infra_sequence<T>::end()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.end();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::end() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.end();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cend() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.cend();
}

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rbegin()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rbegin();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rbegin() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rbegin();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crbegin() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.crbegin();
}

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rend()
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rend();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rend() const
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.rend();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crend() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.crend();
}

//---------------------------//

// WHATWG sequence member functions //

template <class T> T& infra_sequence<T>::front() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.front();
}
template <class T> const T& infra_sequence<T>::front() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.front();
}
template <class T> T& infra_sequence<T>::back() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.back();
}
template <class T> const T& infra_sequence<T>::back() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.back();
}

template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(const infra_sequence& sequence) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> sequence_lock(sequence.mtx);
    for (const auto& item: sequence.data) data.push_back(item);
    return *this;
}

template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(item);
    return *this;
}
template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(T&& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(item);
    return *this;
}

template <class T> void infra_sequence<T>::extend(const infra_sequence<T>& sequence) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> sequence_lock(sequence.mtx);
    for (const auto& item: sequence.data) data.push_back(item);
    return *this;
}

template <class T> void infra_sequence<T>::push_back(const T& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(item);
}
template <class T> void infra_sequence<T>::push_back(T&& item) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.push_back(std::move(item));
}
template <class T> void infra_sequence<T>::pop_back() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.pop_back();
}

template <class T> const infra_sequence<T>::size_type infra_sequence<T>::size() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.size();
}
template <class T> const bool infra_sequence<T>::empty() const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data.empty();
}
template <class T> void infra_sequence<T>::clear() noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    data.clear();
}

template <class T> T& infra_sequence<T>::operator[](const size_type index) noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data[index];
}
template <class T> const T& infra_sequence<T>::operator[](const size_type index) const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    return data[index];
}

//------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_sequence<T>::structure_type() const noexcept
{
    return infra_structure_type::infra_sequence;
}
template <class T> void infra_sequence<T>::print(std::ostream& out) const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    auto curr_it = data.cbegin();
    auto last_it = data.cend();
    for(const T& item: data)
    {
        out << item;
        if(++curr_it != last_it) out << " ";
    }
}

//---------------------------------//

// WHATWG sequence comparison functions //

template <class T> const bool infra_sequence<T>::operator==(const infra_sequence<T>& b) const noexcept
{
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> b_lock(b.mtx);
    return data == b.data;
}

//--------------------------------------//

template <class T> infra_sequence<T> operator+(const infra_sequence<T>& a, const infra_sequence<T>& b) noexcept
{
    infra_sequence<T> combine{a};
    return combine += b;
}
template <class T> infra_sequence<T> operator+(const infra_sequence<T>& a, const T& b) noexcept
{
    infra_sequence<T> combine{a};
    return combine += b;
}
}