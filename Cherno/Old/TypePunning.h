#ifndef TYPE_PUNNING_H
#define TYPE_PUNNING_H

#include <cstring>
#include <cstdint>

namespace TypePunning {
    template <typename T, typename U>
    T PunningCast(U value) {
        static_assert(sizeof(T) == sizeof(U), "Size mismatch in TypePunning::PunningCast");
        T result;
        std::memcpy(&result, &value, sizeof(T));
        return result;
    }
}

#endif // TYPE_PUNNING_H

