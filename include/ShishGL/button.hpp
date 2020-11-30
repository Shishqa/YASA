#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <cstddef>
#include "window.hpp"
#include "draw.hpp"


namespace ShishGL {

    struct ButtonColorScheme {
        Color bg_default,
                bg_hover,
                bg_click,
                fg_default;
    };


    constexpr ButtonColorScheme DEFAULT_BUTTON_COLORS = {
            LEMON_CHIFFON, PAPAYA_WHIP, WHITE, BLACK
    };


    class Button : public Window {
    public:

        Button() = delete;

        Button(const std::string_view& button_label, const Event& click_event,
               const Vector2<int>& position, const Vector2<size_t>& size,
               const ButtonColorScheme& colors = DEFAULT_BUTTON_COLORS);

        ~Button() override = default;

    protected:

        const Event on_click;

        const std::string_view label;

        ButtonColorScheme color_scheme;
        Color bg_current;

        void onRender() override;

        void onEntry(int state) override;

        void onMouseClick(int button, int state, int x, int y) override;
    };

}


#endif //BUTTON_HPP
