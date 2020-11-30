#ifndef OBJECT_HPP
#define OBJECT_HPP


#include "event.hpp"


namespace ShishGL {

    class Object {
    public:

        Object() = default;
        ~Object() = default;

    protected:

        virtual bool getEvent(const Event &) { return false; }

        friend EventSystem;
    };

}

#endif //OBJECT_HPP
