#ifndef _EITHER_MONAD_H
#define _EITHER_MONAD_H

#include <iostream>
#include "MonadUtils.h"
#include "Either.h"

// Bind operator
// M a -> (a -> M b) -> M b 
template<typename TLeft, typename TRight, typename F>
auto operator>>=(const Either<TLeft, TRight>& x, F f)->decltype(f(std::declval<const TRight>())) {
    return x.IsRight() ? f(x.Right()) : x.Left();
}

template<typename TLeft, typename TRight>
std::ostream& operator<<(std::ostream& os, const Either<TLeft, TRight>& x) {
    if (x.IsRight()) return os << x.Right();
    else return os << x.Left();
}

#endif
