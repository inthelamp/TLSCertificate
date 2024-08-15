/*
 * text.h
 *
 *  Created on: July 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef TEXT_H_
#define TEXT_H_

#include <utility>

#include "raylib.h"
#include "screen.h"

namespace tls_certificate {

class Text {
   public:
    constexpr static int kFontSize = 30;              // Default font size
    constexpr static int kCharWidth = kFontSize - 9;  // Default font width
    constexpr static Color kTextColor = MAROON;       // Default text color

    Text(const char *text, int text_length);
    Text(const Text &) = delete;             // Copy constructor
    Text(Text &&) noexcept;                  // Move constructor
    Text &operator=(const Text &) = delete;  // Copy assignment operator
    Text &operator=(Text &&) = delete;       // Move assignment operator
    ~Text() = default;

    const char *text() { return text_; }
    const int text_length() { return text_length_; }

    void DrawMiddle(int pos_y);
    void DrawMiddle(int pos_y, int font_size, const Color &color);
    void DrawCentre();
    void DrawCentre(int font_size, const Color &color);
    void Draw(int pos_x, int pos_y);
    void Draw(int pos_x, int pos_y, int font_size);
    void Draw(int pos_x, int pos_y, int font_size, const Color &color);

   private:
    const char *text_{nullptr};
    int text_length_;
};

}  // namespace tls_certificate

#endif  // TEXT_H_