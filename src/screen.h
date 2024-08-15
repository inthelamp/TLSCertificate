/*
 * screen.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#if defined(EMSCRIPTEN)
#include <emscripten/emscripten.h>
#endif

namespace tls_certificate {

// Vector2, 2 components
typedef struct Size {
    int width;   // Vector x component
    int height;  // Vector y component
} Size;

// Static class
class Screen {
   public:
    Screen() = delete;

    constexpr static int kMinWidth = 480;   // Minimum window width
    constexpr static int kMinHeight = 270;  // Minimum window height
    constexpr static int kMaxWidth = 960;   // Minimum window width
    constexpr static int kMaxHeight = 540;  // Minimum window height

// For Webassembly
#if defined(EMSCRIPTEN)
    constexpr static Size MaxWindowSize() {
        int width, height;
        emscripten_get_screen_size(&width, &height);

        if (width < height) {
            const int temp = width;
            width = height;
            height = temp;
        }

        height = width / 1.78;
        width *= 0.8;
        height *= 0.8;
        width = width < kMinWidth ? kMinWidth : width;
        width = width > kMaxWidth ? kMaxWidth : width;
        height = height < kMinHeight ? kMinHeight : height;
        height = height > kMaxHeight ? kMaxHeight : height;
        return (Size){width, height};
    }
#endif
    constexpr static Size MaxWindowSize() { return (Size){kWidth, kHeight}; }
    constexpr static bool IsMobile() { return kWidth <= 800 ? true : false; }
    // static const bool IsMobile() { return true; }

   private:
    // Actual window size
    static const int kWidth;   // Window width
    static const int kHeight;  // Window height
};

}  // namespace tls_certificate

#endif  // SCREEN_H_