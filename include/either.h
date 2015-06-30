#ifndef _EITHER_H
#define _EITHER_H

#include <boost/optional.hpp>

template <typename Left_t, typename Right_t>
class Either {
    public:
        Either(const Left_t&& l) : _l(l) {}
        Either(const Right_t&& r) : _r(r) { }
        bool IsLeft() const { return _l; }
        bool IsRight() const { return _r; }
        Left_t Left() const { return _l.get();}
        Right_t Right() const { return _r.get();}
   private:
        boost::optional<Left_t> _l;
        boost::optional<Right_t> _r;
};

#endif
