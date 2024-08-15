/*
 * text.cc
 *
 *  Created on: July 20, 2024
 *      Author: Dong Won Kim
 */

#include "text.h"

namespace tls_certificate {

Text::Text(const char *text, const int text_length) : text_{text}, text_length_{text_length} {}

Text::Text(Text &&that) noexcept {
    text_ = std::move(that.text_);
    text_length_ = std::exchange(that.text_length_, 0);
}

void Text::DrawMiddle(int pos_y) { DrawMiddle(pos_y, kFontSize, kTextColor); }

void Text::DrawMiddle(int pos_y, int font_size, const Color &color) {
    DrawText(text_, Screen::MaxWindowSize().width / 2 - kCharWidth * text_length_ / 2, pos_y, font_size, color);
}

void Text::DrawCentre() { DrawCentre(kFontSize, kTextColor); }

void Text::DrawCentre(int font_size, const Color &color) {
    DrawText(text_, Screen::MaxWindowSize().width / 2 - kCharWidth * text_length_ / 2,
             Screen::MaxWindowSize().height / 2, font_size, color);
}

void Text::Draw(int pos_x, int pos_y) { Draw(pos_x, pos_y, kFontSize, kTextColor); }

void Text::Draw(int pos_x, int pos_y, int font_size) { DrawText(text_, pos_x, pos_y, font_size, kTextColor); }

void Text::Draw(int pos_x, int pos_y, int font_size, const Color &color) {
    DrawText(text_, pos_x, pos_y, font_size, color);
}

}  // namespace tls_certificate
