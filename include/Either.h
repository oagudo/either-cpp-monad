#ifndef _EITHER_H
#define _EITHER_H

#include <boost/optional.hpp>

template <typename TLeft, typename TRight>
class Either {
    public:
        Either(const TLeft& l) : _l(l) {}
        Either(const TRight& r) : _r(r) {}
        Either(TLeft&& l) : _l(l) {}
        Either(TRight&& r) : _r(r) {}
        bool IsLeft() const { return _l; }
        bool IsRight() const { return _r; }
        TLeft Left() const { return _l.get();}
        TRight Right() const { return _r.get();}
   private:
        boost::optional<TLeft> _l;
        boost::optional<TRight> _r;
};

#endif
