/**
 * @file bool.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOL_HPP

#include "softloq/whatwg/infra/primitive/base.hpp"
#ifdef SOFTLOQ_MULTITHREADING
#include <mutex>
#endif

namespace softloq::whatwg
{
/** @brief WHATWG infra bool primitive class (https://infra.spec.whatwg.org/#booleans). Thread-safe support when SOFTLOQ_MULTITHREADING is enabled. */
class infra_bool: public infra_primitive_base
{
public:
    // constructors //

    /** @brief Constructs a WHATWG infra bool with a default value of false. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool() noexcept;
    /** 
     * @brief Constructs a WHATWG infra bool with a specified bool value.
     * @param value The initial bool value. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool(const bool value) noexcept;
    /** 
     * @brief Constructs a WHATWG infra bool from another infra bool.
     * @param value The infra bool that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool(const infra_bool& src) noexcept;
    /** 
     * @brief Constructs a WHATWG infra bool from another infra bool.
     * @param value The infra bool that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool(infra_bool&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_bool() noexcept;

    //--------------//

    // assignments //

    /** 
     * @brief Assigns the WHATWG infra bool with a specified bool value.
     * @param value The initial bool value. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const bool value) noexcept;
    /** 
     * @brief Assigns the WHATWG infra bool from another infra bool.
     * @param value The infra bool that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(const infra_bool& src) noexcept;
    /** 
     * @brief Assigns the WHATWG infra bool from another infra bool.
     * @param value The infra bool that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_bool& operator=(infra_bool&& src) noexcept;

    //-------------//

    // conversions //

    /** @brief Converts the WHATWG infra bool to a C++ bool value. */
    SOFTLOQ_WHATWG_INFRA_API operator const bool() const noexcept;

    //-------------//

    // WHATWG primitive base overrides //

    /** @brief Returns the primitive type of the class: infra_primitive_type::infra_bool. */
    SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type primitive_type() const noexcept override;
    /**
     * @brief Default ostream representation of the WHATWG infra bool primitive.
     * @param out The ostream instance. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

private:
    bool value;
    
    #ifdef SOFTLOQ_MULTITHREADING
    mutable std::mutex mtx;
    
    // used for threadsafe copy construction
    SOFTLOQ_WHATWG_INFRA_API infra_bool(const infra_bool& src, const std::lock_guard<std::mutex>&) noexcept;
    // used for threadsafe move construction
    SOFTLOQ_WHATWG_INFRA_API infra_bool(infra_bool&& src, const std::lock_guard<std::mutex>&) noexcept;
    #endif  
};
}

#endif