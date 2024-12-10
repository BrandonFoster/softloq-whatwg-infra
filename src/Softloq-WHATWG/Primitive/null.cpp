#include "Softloq-WHATWG/Primitive/null.hpp"

#include <utility>

namespace Softloq::WHATWG
{
    SOFTLOQ_WHATWG_INFRA_API std::ostream &operator<<(std::ostream &out, const Null null) { return out; }
}