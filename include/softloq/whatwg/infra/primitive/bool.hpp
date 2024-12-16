/**
 * @file bool.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra bool primitive class */
class infra_bool: public infra_primitive_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_bool() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_bool(const bool value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_bool(const infra_bool& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_bool(infra_bool&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_bool() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const bool value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const infra_bool& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(infra_bool&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator bool() const noexcept;

    //-------------//

private:
    bool value;
};
}

#endif