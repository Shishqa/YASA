#ifndef EVENT_HPP
#define EVENT_HPP


#include <queue>


namespace ShishGL {

    class Object;
    class WindowManager;


    struct Event {
        Object* target;
        int event_code;
    };


    class EventSystem {
    public:

        EventSystem()  = default;
        ~EventSystem() = default;

        static void addEvent(const Event& event);

    private:

        using EventQueue = std::queue<Event>;

        static EventQueue& Events();
        static void processNewEvents();

        friend Object;
        friend WindowManager;
    };
}


#endif //EVENT_HPP
