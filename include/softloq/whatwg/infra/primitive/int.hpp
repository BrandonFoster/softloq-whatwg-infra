/**
 * @file signed.hpp
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

    /**
     * @brief prints the WHATWG infra representation of the 8-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::infra_int8. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 8-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8() noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8(const std::int8_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from the copy of another.
     * @param src the infra 8-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8(const infra_int8& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from the L-value of another.
     * @param src the infra 8-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8(infra_int8&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_int8() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(const std::int8_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitivefrom the copy of another.
     * @param src the infra 8-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(const infra_int8& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitive from the L-value of another.
     * @param src the infra 8-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int8& operator=(infra_int8&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 8-bit signed integer representation. */
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

    /**
     * @brief prints the WHATWG infra representation of the 16-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_int16. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 16-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16() noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16(const std::int16_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from the copy of another.
     * @param src the infra 16-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16(const infra_int16& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from the L-value of another.
     * @param src the infra 16-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16(infra_int16&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_int16() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(const std::int16_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitivefrom the copy of another.
     * @param src the infra 16-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(const infra_int16& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitive from the L-value of another.
     * @param src the infra 16-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int16& operator=(infra_int16&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 16-bit signed integer representation. */
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

    /**
     * @brief prints the WHATWG infra representation of the 32-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_int32. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 32-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32() noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32(const std::int32_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from the copy of another.
     * @param src the infra 32-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32(const infra_int32& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from the L-value of another.
     * @param src the infra 32-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32(infra_int32&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_int32() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(const std::int32_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitivefrom the copy of another.
     * @param src the infra 32-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(const infra_int32& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitive from the L-value of another.
     * @param src the infra 32-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int32& operator=(infra_int32&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 32-bit signed integer representation. */
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

    /**
     * @brief prints the WHATWG infra representation of the 64-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::infra_int64. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 64-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64() noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64(const std::int64_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from the copy of another.
     * @param src the infra 64-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64(const infra_int64& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from the L-value of another.
     * @param src the infra 64-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64(infra_int64&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_int64() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(const std::int64_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitivefrom the copy of another.
     * @param src the infra 64-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(const infra_int64& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitive from the L-value of another.
     * @param src the infra 64-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_int64& operator=(infra_int64&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 64-bit signed integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::int64_t() const noexcept;

    //-------------//

private:
    std::int64_t value;
};
}

#endif