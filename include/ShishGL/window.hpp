#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <cstddef>
#include <vector>
#include <unordered_map>

#include "essential.hpp"
#include "object.hpp"


namespace ShishGL {

    class WindowManager;

    class Window : public Object {
    public:

        static constexpr int ID_UNDEFINED = 0;

        struct WindowInfo {
            const std::string_view title;
            int id;
            Vector2<int> pos;
            Vector2<size_t> size;
        };

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        Window() = delete;

        explicit Window(const Vector2<size_t>& size,
                        const Vector2<int>& pos = {0, 0},
                        const std::string_view& win_title = "");

        virtual ~Window();

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        void display();

        void close();

        void refresh() const;

        void dump();

        [[nodiscard]] const WindowInfo& getInfo();

    protected:

        friend WindowManager;

        WindowInfo info;

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        std::vector<Window*> subwindows;

        template <typename T, typename... Args>
        T* attach(Args&&... args) {
            T* win_ptr = new T(std::forward<Args>(args)...);
            subwindows.emplace_back(win_ptr);
            return win_ptr;
        }

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        virtual void onRender() = 0;

        virtual void onReshape(int, int) { /*nothing*/ };

        virtual void onIdle() { /*nothing to do on idle*/ }

        virtual void onEntry(int) { /*nothing*/ }

        virtual void onKeyPress(unsigned char, int, int) { /*nothing*/ }

        virtual void onMouseClick(int, int, int, int) { /*nothing*/ }
    };

}


#endif //WINDOW_HPP
