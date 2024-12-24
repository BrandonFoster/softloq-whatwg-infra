/**
 * @file set.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra set data structure class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_STRUCTURE_SET_HPP
#define SOFTLOQ_WHATWG_INFRA_STRUCTURE_SET_HPP

#include "softloq/whatwg/infra/structure/list.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra set data structure class. */
template <class T> class infra_set : public infra_list<T>
{
public:
    // Standard member types //

    using value_type = T;
    using size_type	= infra_list<T>::size_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = infra_list<T>::iterator;
    using const_iterator = infra_list<T>::const_iterator;
    using reverse_iterator = infra_list<T>::reverse_iterator;
    using const_reverse_iterator = infra_list<T>::const_reverse_iterator;

    //-----------------------//

    // Member functions //
    
    //------------------//
};
}

#include "softloq/whatwg/infra/structure/set.tpp"

#endif