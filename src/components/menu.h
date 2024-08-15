/*
 * menu.h
 *
 *  Created on: June 27, 2024
 *      Author: Dong Won Kim
 */

#ifndef MENU_H_
#define MENU_H_

#include <cstring>
#include <iostream>

#include "../workspaces/workspace.h"
#include "clickable.h"
#include "graphics_entity.h"
#include "raylib.h"

namespace tls_certificate::components {

class Menu : public Clickable, public GraphicsEntity<Rectangle> {
   public:
    Menu(const char *name, const Vector2 &position, const Color &text_color = kTextColor, int font_size = kFontSize);
    Menu(const Menu &that) = delete;             // Copy constructor
    Menu(Menu &&) = delete;                      // Move constructor
    Menu &operator=(const Menu &that) = delete;  // Copy assignment operator
    Menu &operator=(Menu &&) = delete;           // Move assignment operator
    ~Menu() = default;

    const char *name() { return name_; }

    std::shared_ptr<workspaces::Workspace> workspace{};

    void CheckClick(const Vector2 &mouse_point) override;
    void Draw() override;

    constexpr static float kMargin = 5.0f;
    constexpr static float kHeight = 25.0f;
    constexpr static int kFontSize = 15;
    constexpr static Color kTextColor = BLACK;

   private:
    const char *name_;  // Menu name
    Color text_color_;
    int font_size_;

    const Color mouse_over_text_color() { return BLUE; }
    const Color pressed_text_color() { return RED; }

    // Background color
    const Color kBackgroundColor =
        Color{(unsigned char)(255 - (int)text_color_.r), (unsigned char)(255 - (int)text_color_.g),
              (unsigned char)(255 - (int)text_color_.b), text_color_.a};

    constexpr static float name_width(const char *name, int font_size) { return strlen(name) * font_size / 2; }
    constexpr static Rectangle rectangle(const char *name, const Vector2 &position, int font_size) {
        const float width = name_width(name, font_size) + 2 * kMargin;
        return (Rectangle){position.x, position.y, width, kHeight};
    }
};

}  // namespace tls_certificate::components

#endif  // MENU_H_