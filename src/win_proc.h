/*
 * win_proc.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef TLS_CERTIFICATE_
#define TLS_CERTIFICATE_

// For WebAssembly
#if defined(EMSCRIPTEN)
#include <emscripten/emscripten.h>
#endif

#include <memory>

#include "./workspaces/sign_in.h"
#include "raylib.h"
#include "screen.h"
#include "user.h"
#include "window.h"

namespace tls_certificate {

class WinProc {
   public:
    WinProc(Window &&window);
    WinProc(const WinProc &) = delete;             // Copy constructor
    WinProc(WinProc &&) = delete;                  // Move constructor
    WinProc &operator=(const WinProc &) = delete;  // Copy assignment operator
    WinProc &operator=(WinProc &&) = delete;       // Move assignment operator
    virtual ~WinProc() { delete user_; }

    void user(User *user) { user_ = user; }
    void UpdateDrawFrame(void);  // Updating components' activities per frame

    constexpr static int kFPS = 10;                   // Default frames per second
    constexpr static Color kBackgroundColor = WHITE;  // Background color

    bool exit_window = false;

   private:
    Window window_;
    User *user_{nullptr};

    Vector2 mouse_point_ = {0.0f, 0.0f};  // Coordinate where mouse points to
};

}  // namespace tls_certificate

#endif  // TLS_CERTIFICATE_