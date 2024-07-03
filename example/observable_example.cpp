

#include <utility/templates/observable.hpp>
#include <utility/templates/observer.hpp>
#include <utility/enums.hpp>

#include <memory>
#include <iostream>


class IntObserver final {
public:
    std::shared_ptr<Koi::Utility::Observer<int>> observer;


    IntObserver() {
        observer = std::make_shared<Koi::Utility::Observer<int>>(
                [this](const int& value) -> Koi::Utility::Error {
                    return callback(value);
                }
        );
    }


    Koi::Utility::Error callback(const int& value) {
        std::cout << "value is now " << value << std::endl;
        return Koi::Utility::UTILITY_ERROR_OK;
    }
};


int main() {
    Koi::Utility::Observable<int> observable_int;

    IntObserver int_observer;



    int i = observable_int;

    observable_int.add(int_observer.observer);

    std::shared_ptr<Koi::Utility::Observer<int>> floater = observable_int.get_observer(
            [](const int& value) -> Koi::Utility::Error {
                std::cout << "floater says: value is now " << value << std::endl;
                return Koi::Utility::UTILITY_ERROR_OK;
            },
            true
    );

    observable_int = 9;
    observable_int = 11;
    observable_int = 9;
    observable_int = 100;
    observable_int = i;

    return 0;
}