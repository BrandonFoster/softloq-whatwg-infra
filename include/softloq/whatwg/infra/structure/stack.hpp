// /**
//  * @file stack.hpp
//  * @author Brandon Foster (https://github.com/BrandonFoster)
//  * @brief Declaration of the WHATWG infra stack data structure class.
//  * @version 1.0.0 */

// #ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_STACK_HPP
// #define SOFTLOQ_WHATWG_INFRA_STRUCTURE_STACK_HPP

// #include "softloq/whatwg/infra/structure/list.hpp"

// #include <optional>

// namespace softloq::whatwg
// {
// /** @brief WHATWG infra stack data structure class. */
// template <class T> class infra_stack : public infra_list<T>
// {
// public:
//     // Standard member types //

//     using value_type = T;
//     using container_type = std::list<value_type>;
//     using size_type	= std::size_t;
//     using reference = value_type&;
//     using const_reference = const value_type&;
//     using iterator = container_type::iterator;
//     using const_iterator = container_type::const_iterator;
//     using reverse_iterator = container_type::reverse_iterator;
//     using const_reverse_iterator = container_type::const_reverse_iterator;

//     //-----------------------//

//     // Deleted functions //

//     reference front() noexcept = delete;
//     const_reference front() const noexcept = delete;
//     reference back() noexcept = delete;
//     const_reference back() const noexcept = delete;
    
//     void append(const_reference item) noexcept = delete;
//     void append(value_type&& item) noexcept = delete;
//     void pop_back() noexcept = delete;

//     void prepend(const_reference item) noexcept = delete;
//     void prepend(value_type&& item) noexcept = delete;
//     void pop_front() noexcept = delete;

//     void remove(const_reference item) noexcept = delete;
//     void remove_if(const std::function<const bool (const_reference item)>& cond) noexcept = delete;

//     //-------------------//

//     // Member functions //

//     std::optional<value_type> peek() const noexcept;
//     void push(const_reference item) noexcept;
//     void push(value_type&& item) noexcept;
//     std::optional<value_type> pop() noexcept;

//     //------------------//
// };
// }

// #include "softloq/whatwg/infra/structure/stack.tpp"

// #endif