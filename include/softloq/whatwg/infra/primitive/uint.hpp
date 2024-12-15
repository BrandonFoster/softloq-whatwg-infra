/**
 * @file unsigned.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra unsigned integer primitive classes.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_UINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_UINT_HPP

#include "softloq/whatwg/infra/primitive/number_base.hpp"

namespace softloq::whatwg
{
/** @brief WHATWG infra 8-bit unsigned integer primitive base class */
class infra_uint8: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 8-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_uint8. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 8-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8() noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8(const std::uint8_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from the copy of another.
     * @param src the infra 8-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8(const infra_uint8& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 8-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8(infra_uint8&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_uint8() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8& operator=(const std::uint8_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 8-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8& operator=(const infra_uint8& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 8-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint8& operator=(infra_uint8&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 8-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;

    //-------------//

private:
    std::uint8_t value;
};

/** @brief WHATWG infra 16-bit unsigned integer primitive base class */
class infra_uint16: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 16-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_uint16. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 16-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16() noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16(const std::uint16_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from the copy of another.
     * @param src the infra 16-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16(const infra_uint16& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 16-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16(infra_uint16&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_uint16() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16& operator=(const std::uint16_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 16-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16& operator=(const infra_uint16& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 16-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint16& operator=(infra_uint16&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 16-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint16_t() const noexcept;

    //-------------//

private:
    std::uint16_t value;
};

/** @brief WHATWG infra 32-bit unsigned integer primitive base class */
class infra_uint32: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 32-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_uint32. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 32-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32() noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32(const std::uint32_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from the copy of another.
     * @param src the infra 32-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32(const infra_uint32& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 32-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32(infra_uint32&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_uint32() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32& operator=(const std::uint32_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 32-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32& operator=(const infra_uint32& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 32-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint32& operator=(infra_uint32&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 32-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint32_t() const noexcept;

    //-------------//

private:
    std::uint32_t value;
};

/** @brief WHATWG infra 64-bit unsigned integer primitive base class */
class infra_uint64: public infra_number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 64-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra_number_type::infra_uint64. */
    SOFTLOQ_WHATWG_INFRA_API const infra_number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 64-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64() noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64(const std::uint64_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from the copy of another.
     * @param src the infra 64-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64(const infra_uint64& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 64-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64(infra_uint64&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~infra_uint64() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64& operator=(const std::uint64_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 64-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64& operator=(const infra_uint64& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 64-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API infra_uint64& operator=(infra_uint64&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 64-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint64_t() const noexcept;

    //-------------//

private:
    std::uint64_t value;
};
}

#endif