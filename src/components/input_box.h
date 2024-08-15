/*
 * input_box.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef INPUTBOX_H_
#define INPUTBOX_H_

#include "../screen.h"
#include "../text.h"
#include "graphics_entity.h"

namespace tls_certificate::components {

// inline float InputBoxWidth(int max_input_chars) { return max_input_chars * InputBox::kCharWidth; }

class InputBox : public GraphicsEntity<Rectangle> {
   public:
    InputBox(int max_input_chars, float pos_y);
    InputBox(int max_input_chars, const Vector2 &position);
    InputBox(int max_input_chars, const Rectangle &rec);  // Width => 25 per a character

    InputBox(const InputBox &that) = delete;
    InputBox(InputBox &&) = delete;
    InputBox &operator=(const InputBox &that) = delete;
    InputBox &operator=(InputBox &&) = delete;
    ~InputBox() { delete[] input_; }

    // int max_input_chars() { return max_input_chars_; }
    // int char_count() { return char_count_; }
    // void char_count(int letter_count) { char_count_ = letter_count; }
    // bool mouse_on_text() { return mouse_on_text_; }
    // void mouse_on_text(bool mouse_on_text) { mouse_on_text_ = mouse_on_text; }
    // const Color &text_color() const { return text_color_; }
    int cursor_blink_interval() { return cursor_blink_interval_; }
    void cursor_blink_interval(int cursor_blink_interval) { cursor_blink_interval_ = cursor_blink_interval; }

    void Update();

    void Draw() override;

   private:
    int max_input_chars_;
    char *input_;
    int char_count_ = 0;
    Color text_color_ = Text::kTextColor;
    bool mouse_on_text_ = false;

    // Cursor blink interval, sharing value between instances as defined with static
    inline static int cursor_blink_interval_ = 0;

    constexpr static float kHeight = Text::kFontSize + 5;
    constexpr static float kLineThick = 2.0f;
    constexpr static Color kLineColor = GRAY;

    constexpr static float input_width(int max_input_chars) { return max_input_chars * Text::kCharWidth; }

    constexpr static float x_center_pos(int max_input_chars) {
        return Screen::MaxWindowSize().width / 2 - input_width(max_input_chars) / 2;
    }
    constexpr static float x_center_pos(float width) { return Screen::MaxWindowSize().width / 2 - width / 2; }

    constexpr static Rectangle rectangle(float pos_y, float width, float height) {
        return (Rectangle){x_center_pos(width), pos_y, width, height};
    }

    constexpr static Rectangle rectangle(const Vector2 &position, int max_input_chars) {
        return (Rectangle){position.x, position.y, input_width(max_input_chars), kHeight};
    }
};

}  // namespace tls_certificate::components

#endif  // INPUTBOX_H_