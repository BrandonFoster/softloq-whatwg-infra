/**
 * @file signed.hpp
 * @author Brandon Foster (https://github.com/BrandonFoster)
 * @brief Declaration of the WHATWG infra signed integer primitive classes.
 * @version 1.0.0 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_SIGNED_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_SIGNED_HPP

#include "softloq/whatwg/infra/primitive/number_base.hpp"

namespace softloq::whatwg::infra
{
/** @brief WHATWG infra 8-bit signed integer primitive base class */
class signed8: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 8-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int8. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 8-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API signed8() noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed8(const std::int8_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from the copy of another.
     * @param src the infra 8-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed8(const signed8& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 8-bit signed integer primitive from the L-value of another.
     * @param src the infra 8-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed8(signed8&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~signed8() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed8& operator=(const std::int8_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitivefrom the copy of another.
     * @param src the infra 8-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed8& operator=(const signed8& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 8-bit signed integer primitive from the L-value of another.
     * @param src the infra 8-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed8& operator=(signed8&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 8-bit signed integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::int8_t() const noexcept;

    //-------------//

private:
    std::int8_t value;
};

/** @brief WHATWG infra 16-bit signed integer primitive base class */
class signed16: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 16-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int16. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 16-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API signed16() noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed16(const std::int16_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from the copy of another.
     * @param src the infra 16-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed16(const signed16& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 16-bit signed integer primitive from the L-value of another.
     * @param src the infra 16-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed16(signed16&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~signed16() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed16& operator=(const std::int16_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitivefrom the copy of another.
     * @param src the infra 16-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed16& operator=(const signed16& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 16-bit signed integer primitive from the L-value of another.
     * @param src the infra 16-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed16& operator=(signed16&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 16-bit signed integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::int16_t() const noexcept;

    //-------------//

private:
    std::int16_t value;
};

/** @brief WHATWG infra 32-bit signed integer primitive base class */
class signed32: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 32-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int32. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 32-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API signed32() noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed32(const std::int32_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from the copy of another.
     * @param src the infra 32-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed32(const signed32& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 32-bit signed integer primitive from the L-value of another.
     * @param src the infra 32-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed32(signed32&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~signed32() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed32& operator=(const std::int32_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitivefrom the copy of another.
     * @param src the infra 32-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed32& operator=(const signed32& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 32-bit signed integer primitive from the L-value of another.
     * @param src the infra 32-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed32& operator=(signed32&& src) noexcept;

    //-------------//

    // Conversions //

    /** @brief gets the C++ 32-bit signed integer representation. */
    SOFTLOQ_WHATWG_INFRA_API operator std::int32_t() const noexcept;

    //-------------//

private:
    std::int32_t value;
};

/** @brief WHATWG infra 64-bit signed integer primitive base class */
class signed64: public number_base
{
public:
    // WHATWG primitive base overrides //

    /**
     * @brief prints the WHATWG infra representation of the 64-bit signed integer primitive to the outstream.
     * @param out the outstream that will be used. */
    SOFTLOQ_WHATWG_INFRA_API void print(std::ostream& out) const noexcept override;

    //---------------------------------//

    // WHATWG number base overrides //

    /** @brief gets the number type of the class. returns infra::number_type::int64. */
    SOFTLOQ_WHATWG_INFRA_API const infra::number_type number_type() const noexcept;

    //------------------------------//

    // Constructors //

    /** @brief constructs a WHATWG infra 64-bit signed integer primitive with the value 0. */
    SOFTLOQ_WHATWG_INFRA_API signed64() noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed64(const std::int64_t value) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from the copy of another.
     * @param src the infra 64-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed64(const signed64& src) noexcept;
    /**
     * @brief constructs a WHATWG infra 64-bit signed integer primitive from the L-value of another.
     * @param src the infra 64-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed64(signed64&& src) noexcept;
    /** @brief applies default destructor. */
    SOFTLOQ_WHATWG_INFRA_API ~signed64() noexcept;

    //--------------//

    // Assignments //

    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitive from a value.
     * @param value the value that will be used. */
    SOFTLOQ_WHATWG_INFRA_API signed64& operator=(const std::int64_t value) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitivefrom the copy of another.
     * @param src the infra 64-bit signed integer primitive that will be copied. */
    SOFTLOQ_WHATWG_INFRA_API signed64& operator=(const signed64& src) noexcept;
    /**
     * @brief assigns a WHATWG infra 64-bit signed integer primitive from the L-value of another.
     * @param src the infra 64-bit signed integer primitive that will be moved. */
    SOFTLOQ_WHATWG_INFRA_API signed64& operator=(signed64&& src) noexcept;

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