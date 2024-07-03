

#ifndef KOI_UTILITY_OBSERVER_HPP
#define KOI_UTILITY_OBSERVER_HPP


#include "utility/enums.hpp"

#include <functional>


namespace Koi { namespace Utility {

template<typename T>
class Observer final {
private:
    std::function<Error(const T&)> _callback;

public:
    explicit Observer(const std::function<Error(const T&)>& in_callback) : _callback(in_callback) {

    }

    Error operator()(const T& value) {
        return _callback(value);
    }

    Error on_notified(const T& value) const {
        return _callback(value);
    }
};

}
}


#endif //KOI_UTILITY_OBSERVER_HPP
