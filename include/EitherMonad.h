#ifndef _EITHER_MONAD_H
#define _EITHER_MONAD_H

#include "MonadUtils.h"
#include "Either.h"

// Bind operator
// M a -> (a -> M b) -> M b 
template<typename TLeft, typename TRight, typename F>
auto operator>>=(const either<TLeft, TRight>& x, F f)->decltype(f(std::declval<const TRight>())) {
    return x.is_right() ? f(x.right()) : x.left();
}

template<typename TLeft, typename TRight>
std::ostream& operator<<(std::ostream& os, const either<TLeft, TRight>& x) {
    if (x.is_right()) return os << x.right();
    else return os << x.left().ToString();
}

#endif
