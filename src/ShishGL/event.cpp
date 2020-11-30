#include "ShishGL/ShishGL.hpp"

using namespace ShishGL;


EventSystem::EventQueue& EventSystem::Events() {
    static EventQueue events;
    return events;
}


void EventSystem::addEvent(const Event& event) {
    Events().emplace(event);
}


void EventSystem::processNewEvents() {

    size_t curr_events_size = Events().size();

    while (curr_events_size--) {

        Event curr_event = Events().front();

        if (!curr_event.target) {
            printLog("Warning: event with empty target passed!");
        } else {
            printLog("Target: %p, code: %d", reinterpret_cast<void*>(curr_event.target),
                                             curr_event.event_code);

            if (!curr_event.target->getEvent(curr_event)) {
                Events().push(curr_event);
            }
        }

        Events().pop();
    }
}
