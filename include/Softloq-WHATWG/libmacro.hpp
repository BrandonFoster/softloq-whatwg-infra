#ifndef SOFTLOQ_WHATWG_INFRA_LIBMACRO_HPP
#define SOFTLOQ_WHATWG_INFRA_LIBMACRO_HPP

/**
 * @author Brandon Foster
 * @file libmacro.hpp
 * @version 1.0.0
 * @brief Shared|Static Library Macro.
 *
 * This library holds important macros for building the library as shared or static.
 */

// Static|Shared Build Macros.

#if defined(_MSC_VER)
#define SOFTLOQ_WHATWG_INFRA_EXPORT __declspec(dllexport)
#define SOFTLOQ_WHATWG_INFRA_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define SOFTLOQ_WHATWG_INFRA_EXPORT __attribute__((visibility("default")))
#define SOFTLOQ_WHATWG_INFRA_IMPORT
#endif

// For Standalone Builds.

#if defined(SOFTLOQ_WHATWG_INFRA_NO_API)
#define SOFTLOQ_WHATWG_INFRA_API
#elif defined(SOFTLOQ_WHATWG_INFRA_BUILD_API)
#define SOFTLOQ_WHATWG_INFRA_API SOFTLOQ_WHATWG_INFRA_EXPORT
#elif defined(SOFTLOQ_WHATWG_INFRA_USE_API)
#define SOFTLOQ_WHATWG_INFRA_API SOFTLOQ_WHATWG_INFRA_IMPORT
#endif

// For Monolithic Builds.

#ifndef SOFTLOQ_WHATWG_INFRA_API
#if defined(SOFTLOQ_NO_API)
#define SOFTLOQ_WHATWG_INFRA_API
#elif defined(SOFTLOQ_BUILD_API)
#define SOFTLOQ_WHATWG_INFRA_API SOFTLOQ_WHATWG_INFRA_EXPORT
#elif defined(SOFTLOQ_USE_API)
#define SOFTLOQ_WHATWG_INFRA_API SOFTLOQ_WHATWG_INFRA_IMPORT
#endif
#endif

// Default Values and Documentation.

#ifndef SOFTLOQ_WHATWG_INFRA_EXPORT
/** @brief Library Export Macro. */
#define SOFTLOQ_WHATWG_INFRA_EXPORT
#endif

#ifndef SOFTLOQ_WHATWG_INFRA_IMPORT
/** @brief Library Import Macro. */
#define SOFTLOQ_WHATWG_INFRA_IMPORT
#endif

#ifndef SOFTLOQ_WHATWG_INFRA_API
/** @brief Static|Shared Build Macro. */
#define SOFTLOQ_WHATWG_INFRA_API
#endif

#endif