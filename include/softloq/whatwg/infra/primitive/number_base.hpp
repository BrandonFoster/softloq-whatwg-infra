/**
 * @file number_base.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra number primitive base class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_BASE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_BASE_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra number types */
enum class infra_number_type { infra_uint8, infra_int8, infra_uint16, infra_int16, infra_uint32, infra_int32, infra_uint64, infra_int64, infra_uint128 };

/** @brief WHATWG infra number primitive base class */
class infra_number_base: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;

    //---------------------------------//

    SOFTLOQ_WHATWG_INFRA_API virtual const infra_number_type number_type() const noexcept = 0;
};
}

#endif