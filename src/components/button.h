/*
 * button.h
 *
 *  Created on: June 27, 2024
 *      Author: Dong Won Kim
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../screen.h"
#include "clickable.h"
#include "graphics_entity.h"
#include "raylib.h"

namespace tls_certificate::components {

class Button : public Clickable, public GraphicsEntity<Rectangle> {
   public:
    Button(const Texture2D &button, float pos_x);
    Button(const Texture2D &button, const Rectangle &source_rec, const Vector2 &position);

    const Texture2D &button() const { return button_; }
    const Rectangle &source_rectangle() const { return source_rectangle_; }
    void source_rectangle(const Rectangle &source_rectangle) { source_rectangle_ = source_rectangle; }

    void CheckClick(const Vector2 &mouse_point) override;
    void Draw() override;

   private:
    constexpr static int kNumberOfFrames = 3;

    Texture2D button_;
    Rectangle source_rectangle_;

    constexpr static float frame_height(const Texture2D &button) { return (float)button.height / kNumberOfFrames; }

    static Rectangle rectangle(float width, float height, float pos_x) {
        return (Rectangle){Screen::MaxWindowSize().width / 2 + pos_x, Screen::MaxWindowSize().height / 2 - height / 2,
                           width, height};
    }

    constexpr static Rectangle rectangle(float width, float height, const Vector2 &position) {
        return (Rectangle){position.x, position.y, width, height};
    }

    static Vector2 position(float height, float pos_x) {
        return (Vector2){Screen::MaxWindowSize().width / 2 + pos_x, Screen::MaxWindowSize().height / 2 - height / 2};
    }
};

}  // namespace tls_certificate::components

#endif  // BUTTON_H_