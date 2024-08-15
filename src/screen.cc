/*
 * screen.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "screen.h"

namespace tls_certificate {

// Screen size
#if defined(EMSCRIPTEN)
const int Screen::kWidth = Screen::Size().width;
const int Screen::kHeight = Screen::Size().height;
#else
const int Screen::kWidth = kMaxWidth;
const int Screen::kHeight = kMaxHeight;
#endif

}  // namespace tls_certificate
