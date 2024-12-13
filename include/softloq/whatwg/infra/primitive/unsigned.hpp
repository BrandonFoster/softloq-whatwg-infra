/**
 * @file unsigned.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra unsigned integer primitive classes.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_UNSIGNED_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_UNSIGNED_HPP

#include "softloq/whatwg/infra/primitive/number_base.hpp"

namespace softloq::whatwg::infra
{
/** @brief WHATWG infra 8-bit unsigned integer primitive base class */
class unsigned8: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 8-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int8. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 8-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8() noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8(const std::uint8_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from the copy of another.
     * @param src the infra 8-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8(const unsigned8& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 8-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8(unsigned8&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~unsigned8() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8& operator=(const std::uint8_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 8-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8& operator=(const unsigned8& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 8-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned8& operator=(unsigned8&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 8-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint8_t() const noexcept;

    //-------------//

private:
    std::uint8_t value;
};

/** @brief WHATWG infra 16-bit unsigned integer primitive base class */
class unsigned16: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 16-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int16. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 16-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16() noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16(const std::uint16_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from the copy of another.
     * @param src the infra 16-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16(const unsigned16& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 16-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16(unsigned16&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~unsigned16() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16& operator=(const std::uint16_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 16-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16& operator=(const unsigned16& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 16-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned16& operator=(unsigned16&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 16-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint16_t() const noexcept;

    //-------------//

private:
    std::uint16_t value;
};

/** @brief WHATWG infra 32-bit unsigned integer primitive base class */
class unsigned32: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 32-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int32. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 32-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32() noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32(const std::uint32_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from the copy of another.
     * @param src the infra 32-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32(const unsigned32& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 32-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32(unsigned32&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~unsigned32() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32& operator=(const std::uint32_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 32-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32& operator=(const unsigned32& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 32-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned32& operator=(unsigned32&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 32-bit unsigned integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::uint32_t() const noexcept;

    //-------------//

private:
    std::uint32_t value;
};

/** @brief WHATWG infra 64-bit unsigned integer primitive base class */
class unsigned64: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 64-bit unsigned integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int64. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 64-bit unsigned integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64() noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64(const std::uint64_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from the copy of another.
     * @param src the infra 64-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64(const unsigned64& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 64-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64(unsigned64&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~unsigned64() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64& operator=(const std::uint64_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitivefrom the copy of another.
     * @param src the infra 64-bit unsigned integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64& operator=(const unsigned64& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit unsigned integer primitive from the L-value of another.
     * @param src the infra 64-bit unsigned integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API unsigned64& operator=(unsigned64&& src) noexcept;

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