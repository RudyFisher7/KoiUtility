#ifndef KOI_UTILITY_OBSERVABLE_HPP
#define KOI_UTILITY_OBSERVABLE_HPP


#include "utility/enums.hpp"
#include "utility/templates/observer.hpp"

#include <memory>
#include <map>


namespace Koi { namespace Utility {


template<typename T>
class Observable final {
private:
    T _data;
    std::map<int, std::weak_ptr<Observer<T>>> _observers;
    int key = 0;


public:
    operator T() const {
        return _data;
    }


    T& operator=(const T& value) {
        _data = value;

        notify_all();

        return _data;
    }


    std::shared_ptr<Observer<T>> get_observer(const std::function<Error(const T&)>& callback, bool should_add) {
        std::shared_ptr<Observer<T>> result = std::make_shared<Observer<T>>(callback);

        if (should_add) {
            add(result);
        }

        return result;
    }


    void set(const T& value) {
        _data = value;

        notify_all();
    }


    bool add(std::shared_ptr<Observer<T>>& observer) {
        bool result = false;

        _observers.emplace(key++, observer);
        result = true;

        return result;
    }


    bool erase(std::shared_ptr<Observer<T>>& observer) {
        bool result = false;

        result = _observers.erase(0) > 0;

        return result;
    }

    void notify_all() {
        for (auto observer : _observers) {
            auto shared_observer = observer.second.lock();
            if (shared_observer.use_count() > 0) {
                Error error = (*shared_observer)(_data);//fixme:: handle error
            } else {
                //todo:: remove weak_ptr
            }
        }
    }
};

}
}


#endif //KOI_UTILITY_OBSERVABLE_HPP
