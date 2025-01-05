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
#ifdef SOFTLOQ_MULTITHREADING
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept : infra_sequence(src, std::lock_guard<std::mutex>(src.mtx)) {}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept : infra_sequence(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src, const std::lock_guard<std::mutex>&) noexcept : values(src.values) {}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src, const std::lock_guard<std::mutex>&) noexcept : values(std::move(src.values)) {}
#else
template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept : values(src.values) {}
template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept : values(std::move(src.values)) {}
#endif
template <class T> infra_sequence<T>::~infra_sequence() noexcept {}

//--------------//

// assignments //

template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const infra_sequence& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock1(mtx);
    std::lock_guard<std::mutex> lock2(src.mtx);
    #endif
    values = src.values;
    return *this;
}
template <class T> infra_sequence<T>& infra_sequence<T>::operator=(infra_sequence&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock1(mtx);
    std::lock_guard<std::mutex> lock2(src.mtx);
    #endif
    values = std::move(src.values);
    return *this;
}

//-------------//

// iterator member functions //

template <class T> infra_sequence<T>::iterator infra_sequence<T>::begin()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.begin();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::begin() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.begin();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cbegin() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.cbegin();
}

template <class T> infra_sequence<T>::iterator infra_sequence<T>::end()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.end();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::end() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.end();
}
template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cend() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.cend();
}

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rbegin()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rbegin();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rbegin() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rbegin();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crbegin() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.crbegin();
}

template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rend()
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rend();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rend() const
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.rend();
}
template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crend() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.crend();
}

//---------------------------//

// WHATWG sequence member functions //

template <class T> T& infra_sequence<T>::front() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.front();
}
template <class T> const T& infra_sequence<T>::front() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.front();
}
template <class T> T& infra_sequence<T>::back() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.back();
}
template <class T> const T& infra_sequence<T>::back() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.back();
}

template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(const infra_sequence& sequence) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock1(mtx);
    std::lock_guard<std::mutex> lock2(sequence.mtx);
    #endif
    for (const auto& item: sequence) values.push_back(item);
    return *this;
}

template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(item);
    return *this;
}
template <class T> infra_sequence<T>& infra_sequence<T>::operator+=(T&& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(item);
    return *this;
}

template <class T> void infra_sequence<T>::extend(const infra_sequence<T>& sequence) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock1(mtx);
    std::lock_guard<std::mutex> lock2(sequence.mtx);
    #endif
    for (const auto& item: sequence) values.push_back(item);
    return *this;
}

template <class T> void infra_sequence<T>::push_back(const T& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(item);
}
template <class T> void infra_sequence<T>::push_back(T&& item) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.push_back(std::move(item));
}
template <class T> void infra_sequence<T>::pop_back() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.pop_back();
}

template <class T> const infra_sequence<T>::size_type infra_sequence<T>::size() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.size();
}
template <class T> const bool infra_sequence<T>::empty() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values.empty();
}
template <class T> void infra_sequence<T>::clear() noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    values.clear();
}

template <class T> T& infra_sequence<T>::operator[](const size_type index) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values[index];
}
template <class T> const T& infra_sequence<T>::operator[](const size_type index) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return values[index];
}

//------------------//

// WHATWG structure base overrides //

template <class T> const infra_structure_type infra_sequence<T>::structure_type() const noexcept { return infra_structure_type::infra_sequence; }
template <class T> void infra_sequence<T>::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    auto curr_it = values.cbegin();
    auto last_it = values.cend();
    for(const T& item: values)
    {
        out << item;
        if(++curr_it != last_it) out << " ";
    }
}

//---------------------------------//

// WHATWG sequence comparison functions //

template <class T> const bool infra_sequence<T>::operator==(const infra_sequence<T>& b) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock1(mtx);
    std::lock_guard<std::mutex> lock2(b.mtx);
    #endif
    return values == b.values;
}

//--------------------------------------//
}