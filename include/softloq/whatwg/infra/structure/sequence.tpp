// /**
//  * @file sequence.tpp
//  * @author Brandon Foster (https://github.com/BrandonFoster)
//  * @brief Template implementation of the WHATWG infra sequence data structure class.
//  * @version 1.0.0 */

// #include "softloq/whatwg/infra/structure/sequence.hpp"
// #include <string>

// namespace softloq::whatwg
// {
// // Standard iterator functions //

// template <class T> infra_sequence<T>::iterator infra_sequence<T>::begin() noexcept { return container_type::begin(); }
// template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::begin() const noexcept { return container_type::begin(); }
// template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cbegin() const noexcept { return container_type::cbegin(); }

// template <class T> infra_sequence<T>::iterator infra_sequence<T>::end() noexcept { return container_type::end(); }
// template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::end() const noexcept { return container_type::end(); }
// template <class T> infra_sequence<T>::const_iterator infra_sequence<T>::cend() const noexcept { return container_type::cend(); }

// template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rbegin() noexcept { return container_type::rbegin(); }
// template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rbegin() const noexcept { return container_type::rbegin(); }
// template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crbegin() const noexcept { return container_type::crbegin(); }

// template <class T> infra_sequence<T>::reverse_iterator infra_sequence<T>::rend() noexcept { return container_type::rend(); }
// template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::rend() const noexcept { return container_type::rend(); }
// template <class T> infra_sequence<T>::const_reverse_iterator infra_sequence<T>::crend() const noexcept { return container_type::crend(); }

// //-----------------------------//

// // WHATWG structure base overrides //

// template <class T> const infra_structure_type infra_sequence<T>::structure_type() const noexcept { return infra_structure_type::infra_sequence; }
// template <class T> void infra_sequence<T>::print(std::ostream& out) const noexcept
// {
//     auto curr_it = cbegin();
//     auto last_it = cend();
//     for(const_reference item: *this)
//     {
//         out << item;
//         if(++curr_it != last_it) out << " ";
//     }
// }

// //---------------------------------//

// // Constructors //

// template <class T> infra_sequence<T>::infra_sequence() noexcept
// :   container_type{} {}
// template <class T> infra_sequence<T>::infra_sequence(const std::initializer_list<T>& values) noexcept
// :   container_type{values} {}
// template <class T> infra_sequence<T>::infra_sequence(const infra_sequence& src) noexcept
// :   container_type{*static_cast<const container_type*>(&src)} {}
// template <class T> infra_sequence<T>::infra_sequence(infra_sequence&& src) noexcept
// :   container_type{std::move(*static_cast<container_type*>(&src))} {}
// template <class T> infra_sequence<T>::~infra_sequence() noexcept {}

// //--------------//

// // Assignments //

// template <class T> infra_sequence<T>& infra_sequence<T>::operator=(const infra_sequence& src) noexcept
// {
//     *static_cast<container_type*>(this) = *static_cast<const container_type*>(&src);
//     return *this;
// }
// template <class T> infra_sequence<T>& infra_sequence<T>::operator=(infra_sequence&& src) noexcept
// {
//     *static_cast<container_type*>(this) = std::move(*static_cast<container_type*>(&src));
//     return *this;
// }

// //-------------//

// // Member functions //

// template <class T> infra_sequence<T>::reference infra_sequence<T>::front() noexcept { return container_type::front(); }
// template <class T> infra_sequence<T>::const_reference infra_sequence<T>::front() const noexcept { return container_type::front(); }
// template <class T> infra_sequence<T>::reference infra_sequence<T>::back() noexcept { return container_type::back(); }
// template <class T> infra_sequence<T>::const_reference infra_sequence<T>::back() const noexcept { return container_type::back(); }

// template <class T> void infra_sequence<T>::push_back(const_reference item) noexcept { container_type::push_back(item); }
// template <class T> void infra_sequence<T>::push_back(T&& item) noexcept { container_type::push_back(std::move(item)); }
// template <class T> void infra_sequence<T>::pop_back() noexcept { container_type::pop_back(); }

// template <class T> const infra_sequence<T>::size_type infra_sequence<T>::size() const noexcept { return container_type::size(); }
// template <class T> const bool infra_sequence<T>::empty() const noexcept { return container_type::empty(); }
// template <class T> void infra_sequence<T>::clear() noexcept { container_type::clear(); }

// template <class T> infra_sequence<T>::reference infra_sequence<T>::operator[](const size_type index) noexcept { return container_type::operator[](index); }
// template <class T> infra_sequence<T>::const_reference infra_sequence<T>::operator[](const size_type index) const noexcept { return container_type::operator[](index); }

// //------------------//
// }