/**
 * @file int.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra signed integer primitive classes.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_INT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_INT_HPP

#include "softloq/whatwg/infra/primitive/number_base.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra 8-bit signed integer primitive base class */
class infra_int8: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_int8() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8(const std::int8_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8(const infra_int8& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8(infra_int8&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_int8() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(const std::int8_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(const infra_int8& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(infra_int8&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::int8_t() const noexcept;

    //-------------//

private:
    std::int8_t value;
};

/** @brief WHATWG infra 16-bit signed integer primitive base class */
class infra_int16: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_int16() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16(const std::int16_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16(const infra_int16& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16(infra_int16&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_int16() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(const std::int16_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(const infra_int16& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(infra_int16&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::int16_t() const noexcept;

    //-------------//

private:
    std::int16_t value;
};

/** @brief WHATWG infra 32-bit signed integer primitive base class */
class infra_int32: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_int32() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int32(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int32(const infra_int32& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int32(infra_int32&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_int32() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(const std::int32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(const infra_int32& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(infra_int32&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::int32_t() const noexcept;

    //-------------//

private:
    std::int32_t value;
};

/** @brief WHATWG infra 64-bit signed integer primitive base class */
class infra_int64: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    SOFTLOQ_WHATWG_INFRA_API infra_int64() noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int64(const std::int64_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int64(const infra_int64& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int64(infra_int64&& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~infra_int64() noexcept;

    //--------------//

    // Assignments //

    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(const std::int64_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(const infra_int64& src) noexcept;
    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(infra_int64&& src) noexcept;

    //-------------//

    // Conversions //

    SOFTLOQ_WHATWG_INFRA_API operator std::int64_t() const noexcept;

    //-------------//

private:
    std::int64_t value;
};
}

#endif