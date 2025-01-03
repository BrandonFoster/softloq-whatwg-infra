/**
 * @file byte.cpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Implementation of the WHATWG infra byte primitive class.
 * @version 1.0.0 */

#include "softloq/whatwg/infra/primitive/byte.hpp"

#include <iomanip>

namespace softloq::whatwg
{
// constructors //

SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte() noexcept : value(0x00) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const std::int32_t value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_uint8& value) noexcept : value(value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_uint8&& value) noexcept : value(std::move(value)) {}
#ifdef SOFTLOQ_MULTITHREADING
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_byte& src) noexcept : infra_byte(src, std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_byte&& src) noexcept : infra_byte(std::move(src), std::lock_guard<std::mutex>(src.mtx)) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_byte& src, const std::lock_guard<std::mutex>&) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_byte&& src, const std::lock_guard<std::mutex>&) noexcept : value(std::move(src.value)) {}
#else
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(const infra_byte& src) noexcept : value(src.value) {}
SOFTLOQ_WHATWG_INFRA_API infra_byte::infra_byte(infra_byte&& src) noexcept : value(std::move(src.value)) {}
#endif
SOFTLOQ_WHATWG_INFRA_API infra_byte::~infra_byte() noexcept {}

//--------------//

// assignments //

SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const std::int32_t value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_byte::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_uint8& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_byte::value = value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_uint8&& value) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    infra_byte::value = std::move(value);
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(const infra_byte& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = src.value;
    return *this;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte& infra_byte::operator=(infra_byte&& src) noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    value = std::move(src.value);
    return *this;
}

//-------------//

// conversions //

SOFTLOQ_WHATWG_INFRA_API infra_byte::operator std::uint8_t() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}
SOFTLOQ_WHATWG_INFRA_API infra_byte::operator infra_uint8() const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    return value;
}

//-------------//

// WHATWG primitive base overrides //

SOFTLOQ_WHATWG_INFRA_API const infra_primitive_type infra_byte::primitive_type() const noexcept { return infra_primitive_type::infra_byte; }
SOFTLOQ_WHATWG_INFRA_API void infra_byte::print(std::ostream& out) const noexcept
{
    #ifdef SOFTLOQ_MULTITHREADING
    std::lock_guard<std::mutex> lock(mtx);
    #endif
    out << "0x" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << value;
}

//---------------------------------//
}