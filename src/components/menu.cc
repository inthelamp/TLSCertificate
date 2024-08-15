/*
 * menu.cc
 *
 *  Created on: June 27, 2024
 *      Author: Dong Won Kim
 */

#include "menu.h"

namespace tls_certificate::components {

Menu::Menu(const char *name, const Vector2 &position, const Color &text_color, int font_size)
    : GraphicsEntity<Rectangle>(rectangle(name, position, font_size), position, kBackgroundColor),
      name_(name),
      text_color_(text_color),
      font_size_(font_size) {}

void Menu::CheckClick(const Vector2 &mouse_point) {
    if (CheckCollisionPointRec(mouse_point, shape())) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            state(kPressed);
        else
            state(kMouseHover);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) activated(true);
    } else
        state(kNormal);
}

void Menu::Draw() {
    DrawRectangleRec(shape(), color());
    // DrawRectangleRec(Rectangle{shape().x + kMargin, shape().y, name_width(name_, font_size_), kHeight - kMargin},
    //                  GREEN);
    if (state() == kMouseHover) {
        DrawText(name_, shape().x + kMargin, shape().y + kMargin, font_size_, mouse_over_text_color());
    } else if (state() == kPressed) {
        DrawText(name_, shape().x + kMargin, shape().y + kMargin, font_size_, pressed_text_color());
    } else {
        DrawText(name_, shape().x + kMargin, shape().y + kMargin, font_size_, text_color_);
    }
}

}  // namespace tls_certificate::components