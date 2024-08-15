/*
 * win_proc.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "win_proc.h"

namespace tls_certificate {

WinProc::WinProc(Window &&window) : window_(std::move(window)) {}

//----------------------------------------------------------------------------------
// Updating objects' activities per frame
//----------------------------------------------------------------------------------
void WinProc::UpdateDrawFrame() {
    //----------------------------------------------------------------------------------
    // Update
    //----------------------------------------------------------------------------------
    mouse_point_ = GetMousePosition();

    window_.Update(mouse_point_);

    // Check if one of buttons is clicked

    // Detect window close button or ESC key
    exit_window = WindowShouldClose();

    //----------------------------------------------------------------------------------
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(kBackgroundColor);

    window_.DrawMenuBar();
    window_.DrawWorkspace();

    EndDrawing();
    //----------------------------------------------------------------------------------
}

}  // namespace tls_certificate