
/*
 * app.cc
 *
 *  Created on: June 23, 2024
 *      Author: Dong Won Kim
 */

#include "win_proc.h"

using namespace tls_certificate;

int main(void) {
    //----------------------------------------------------------------------------------
    // Initialization
    //----------------------------------------------------------------------------------
    WinProc win_proc(Window(WinProc::kBackgroundColor));
    win_proc.user(new User());

    // Loading game data
    //----------------------------------------------------------------------------------

    // Initializing window
    //----------------------------------------------------------------------------------
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);  // Make the window resizable
    InitWindow(Screen::MaxWindowSize().width, Screen::MaxWindowSize().height, "TLS Certificate");
    SetWindowMinSize(Screen::kMinWidth, Screen::kMinHeight);

    // Initializing sound
    //--------------------------------------------------------------------------------------
    InitAudioDevice();  // Initialize audio device

#if defined(EMSCRIPTEN)
    const char *button_sound_file_name = "/audio/button.wav";
    const char *hit_bar_sound_file_name = "/audio/hit.wav";
    const char *hit_block_sound_file_name = "/audio/shoot.wav";
#else
    const char *button_sound_file_name = "./resources/audio/button.wav";
    const char *hit_bar_sound_file_name = "./resources/audio/hit.wav";
    const char *hit_block_sound_file_name = "./resources/audio/shoot.wav";
#endif

    const Sound button_sound = LoadSound(button_sound_file_name);
    const Sound hit_bar_sound = LoadSound(hit_bar_sound_file_name);      // Load hitting bar audio file
    const Sound hit_block_sound = LoadSound(hit_block_sound_file_name);  // Load hitting block audio file
    SetMasterVolume(0.1f);

    // Initialize HUD
    if (Screen::IsMobile()) {
    }

    // Loading windows

    // #if defined(EMSCRIPTEN)
    //     const char *play_button_texture_file_name = "/images/play_buttons.png";
    //     const char *end_button_texture_file_name = "/images/end_buttons.png";
    // #else
    //     const char *play_button_texture_file_name = "./resources/images/play_buttons.png";
    //     const char *end_button_texture_file_name = "./resources/images/end_buttons.png";
    // #endif

    // const Texture2D play_button_texture = LoadTexture(play_button_texture_file_name);
    // play_button = new Button(play_button_texture, &button_sound, -130);

    // const Texture2D end_button_texture = LoadTexture(end_button_texture_file_name);
    // end_button = new Button(end_button_texture, &button_sound, 10);

    // Loading window objects
    //----------------------------------------------------------------------------------

#if defined(EMSCRIPTEN)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(WinProc::kFPS);  // Set frames per second, by default 10 frames per second.
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!win_proc.exit_window) {
        win_proc.UpdateDrawFrame();
    }
#endif

    //--------------------------------------------------------------------------------------
    // De-Initialization
    //--------------------------------------------------------------------------------------
    // UnloadTexture(play_button_texture); // Unload button texture
    // UnloadTexture(end_button_texture);  // Unload button texture

    UnloadSound(hit_block_sound);  // Unload sound data
    UnloadSound(hit_bar_sound);    // Unload sound data
    UnloadSound(button_sound);

    // UnloadMusicStream(background_sound);          // Unload music stream buffers from RAM

    // Deleting dynamic storages
    //-------------------------------------------------------------------------------------
    if (Screen::IsMobile()) {
        // delete hud;
    }

    // Deleting buttons
    // Delete play_button;
    // Delete end_button;

    CloseAudioDevice();  // Close audio device

    CloseWindow();  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}