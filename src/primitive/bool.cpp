/**
 * @file bool.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra bool primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/bool.hpp"

namespace softloq::whatwg
{
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool() noexcept : value(false) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const bool value) noexcept : value(value) {}
#ifdef SOFTLOQ_MULTITHREADING
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const infra_bool& src) noexcept : infra_bool(src, std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(infra_bool&& src) noexcept : infra_bool(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const infra_bool& src, const std::lock_guard<std::mutex>&) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(infra_bool&& src, const std::lock_guard<std::mutex>&) noexcept : value(std::move(src.value)) {}
#else
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(const infra_bool& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_bool::infra_bool(infra_bool&& src) noexcept : value(std::move(src.value)) {}
#endif  
SOFTLOQ_WHATWG_INFRA_API infra_bool::~infra_bool() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const bool value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_bool::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(const infra_bool& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    #endif
    value = src.value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_bool& infra_bool::operator=(infra_bool&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> src_lock(src.mtx);
    #endif
    value = std::move(src.value);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_bool::operator const bool() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_bool::primitive_type() const noexcept { return infra_primitive_type::infra_bool; }
SOFTLOQ_WHATWG_INFRA_API void infra_bool::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    out << std::boolalpha << value;
}

//---------------------------------//
}