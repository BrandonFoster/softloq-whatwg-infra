/**
 * @file stack.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra stack data structure class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_STACK_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_STACK_HPP

#include "softloq/whatwg/infra/structure/list.hpp"

#include <optional>

namespace softloq::whatwg
{
/** @brief WHATWG infra stack data structure class. */
template <class T> class infra_stack : public infra_list<T>
{
public:
    // constructors //

    infra_stack() noexcept;
    infra_stack(const std::initializer_list<T>& values) noexcept;
    infra_stack(const infra_stack& src) noexcept;
    infra_stack(infra_stack&& src) noexcept;
    ~infra_stack() noexcept;

    //--------------//

    // assignments //

    infra_stack& operator=(const infra_stack& src) noexcept;
    infra_stack& operator=(infra_stack&& src) noexcept;

    //-------------//

    // Deleted functions //

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

    // Member functions //

    std::optional<T> peek() const noexcept;
    void push(const T& item) noexcept;
    void push(T&& item) noexcept;
    std::optional<T> pop() noexcept;

    //------------------//
};
}

#include "softloq/whatwg/infra/structure/stack.tpp"

#endif