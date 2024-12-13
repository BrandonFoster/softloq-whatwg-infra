/**
 * @file number_base.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra number primitive base class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_BASE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_BASE_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg::infra
{
/** @brief WHATWG infra number types */
enum class number_type { uint8, int8, uint16, int16, uint32, int32, uint64, int64, uint128 };

/** @brief WHATWG infra number primitive base class */
class number_base: public primitive_base
{
public:
    // WHATWG primitive base overrides //

    /** @brief gets the primitive type of the class. returns infra::primitive_type::number. */
    SOFTLOQ_WHATWG_INFRA_API const infra::primitive_type primitive_type() const noexcept override;

    //---------------------------------//

    /** @brief gets the number type of the class. */
    SOFTLOQ_WHATWG_INFRA_API virtual const number_type number_type() const noexcept = 0;
};
}

#endif