/**
 * @file queue.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra queue data structure class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_QUEUE_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_QUEUE_HPP

#include "softloq/whatwg/infra/structure/list.hpp"

#include <optional>

namespace softloq::whatwg
{
/** @brief WHATWG infra queue data structure class. */
template <class T> class infra_queue : public infra_list<T>
{
public:
    // constructors //

    infra_queue() noexcept;
    infra_queue(const std::initializer_list<T>& values) noexcept;
    infra_queue(const infra_queue& src) noexcept;
    infra_queue(infra_queue&& src) noexcept;
    ~infra_queue() noexcept;

    //--------------//

    // assignments //

    infra_queue& operator=(const infra_queue& src) noexcept;
    infra_queue& operator=(infra_queue&& src) noexcept;

    //-------------//

    // deleted functions //

    T& front() noexcept = delete;
    const T& front() const noexcept = delete;
    T& back() noexcept = delete;
    const T& back() const noexcept = delete;
    
    void append(const T& item) noexcept = delete;
    void append(T&& item) noexcept = delete;
    void pop_back() noexcept = delete;

    void prepend(const T& item) noexcept = delete;
    void prepend(T&& item) noexcept = delete;
    void pop_front() noexcept = delete;

    void remove(const T& item) noexcept = delete;
    void remove_if(const std::function<const bool (const T& item)>& cond) noexcept = delete;

    //-------------------//

    // WHATWG queue member functions //

    std::optional<T> peek() const noexcept;
    void enqueue(const T& item) noexcept;
    void enqueue(T&& item) noexcept;
    std::optional<T> dequeue() noexcept;

    //------------------//
};
}

#include "softloq/whatwg/infra/structure/queue.tpp"

#endif