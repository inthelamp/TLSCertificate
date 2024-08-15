/*
 * button.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "button.h"

namespace tls_certificate::components {

Button::Button(const Texture2D &button, float pos_x)
    : GraphicsEntity<Rectangle>(rectangle((float)button.width, frame_height(button), pos_x),
                                position(frame_height(button), pos_x)),
      button_(button),
      source_rectangle_((Rectangle){0, 0, (float)button.width, frame_height(button)}) {}

Button::Button(const Texture2D &button, const Rectangle &source_rec, const Vector2 &position)
    : GraphicsEntity<Rectangle>(rectangle((float)button.width, frame_height(button), position), position),
      button_(button),
      source_rectangle_(source_rec) {}

void Button::CheckClick(const Vector2 &mouse_point) {
    if (CheckCollisionPointRec(mouse_point, shape())) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            state(kPressed);
        else
            state(kMouseHover);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) activated(true);
    } else
        state(kNormal);

    // Calculate button frame rectangle to draw depending on button state
    Rectangle rec = source_rectangle();
    rec.y = state() * (int)frame_height(button());
    source_rectangle(rec);
}

void Button::Draw() {
    const float rotation = 0.0f;
    DrawTexturePro(button(), source_rectangle(), shape(), (Vector2){0.0f, 0.0f}, rotation, color());
}

}  // namespace tls_certificate::components