/*
 * input_box.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "input_box.h"

namespace tls_certificate::components {

InputBox::InputBox(int max_input_chars, float pos_y)
    : GraphicsEntity<Rectangle>(rectangle(pos_y, input_width(max_input_chars), kHeight),
                                (Vector2){x_center_pos(max_input_chars), pos_y}),
      max_input_chars_(max_input_chars),
      input_{new char[max_input_chars + 1]} {}

InputBox::InputBox(int max_input_chars, const Vector2 &position)
    : GraphicsEntity<Rectangle>(rectangle(position, max_input_chars), position),
      max_input_chars_(max_input_chars),
      input_{new char[max_input_chars + 1]} {}

InputBox::InputBox(int max_input_chars, const Rectangle &rec)
    : GraphicsEntity<Rectangle>(rec, (Vector2){rec.x, rec.y}),
      max_input_chars_(max_input_chars),
      input_{new char[max_input_chars + 1]} {}

void InputBox::Update() {
    // Update
    //----------------------------------------------------------------------------------
    Rectangle rec = (Rectangle)shape();
    if (CheckCollisionPointRec(GetMousePosition(), rec))
        mouse_on_text_ = true;
    else
        mouse_on_text_ = false;

    if (mouse_on_text_) {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0) {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (char_count_ < max_input_chars_)) {
                input_[char_count_] = (char)key;
                input_[char_count_ + 1] = '\0';  // Add null terminator at the end of the string.
                char_count_++;
            }

            key = GetCharPressed();  // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            char_count_--;
            if (char_count_ < 0) char_count_ = 0;
            input_[char_count_] = '\0';
        }
    } else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouse_on_text_)
        cursor_blink_interval(cursor_blink_interval() + 1);
    else
        cursor_blink_interval(0);
}

void InputBox::Draw() {
    Rectangle rec = (Rectangle)shape();
    DrawRectangleLinesEx(rec, kLineThick, kLineColor);
    input_[max_input_chars_ + 1] = '\0';
    DrawText(input_, rec.x + 3, rec.y + 3, Text::kFontSize, text_color_);

    if (mouse_on_text_) {
        if (char_count_ < max_input_chars_) {
            // Draw blinking underscore char
            if (((cursor_blink_interval() / 20) % 2) == 0)
                DrawText("_", (int)rec.x + 3 + MeasureText(input_, Text::kFontSize), (int)rec.y + kHeight - 25,
                         Text::kFontSize, text_color_);
        }
    }
}

}  // namespace tls_certificate::components