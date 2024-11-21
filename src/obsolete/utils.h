#pragma once

template<typename T>
struct EnumHash {
    std::size_t operator()(T const t) const
    {
        return static_cast<std::size_t>(t);
    }
};
