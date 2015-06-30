#ifndef _MONAD_UTILS_H
#define _MONAD_UTILS_H

// Return operation, monad type contructor for Right type
// a -> M a
template<template<typename, typename> class M, typename TLeft, typename TRigth>
M<TLeft, TRigth> mreturn(const TRigth& x) {
    return x;
}

// Return operation, monad type contructor for Left type
// a -> M a
template<template<typename, typename> class M, typename TLeft, typename TRigth>
M<TLeft, TRigth> mreturn(const TLeft& x) {
    return x;
}

// Bind operator
// M a -> (a -> M b) -> M b 
// Must be overloaded
template<template<typename,typename> class M, typename TLeft, typename TRight, typename F>
auto operator>>=(const M<TLeft, TRight>& m, F f)->decltype(f(std::declval<const TRight>()));


#endif
