/*
 * window.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>
#include <memory>
#include <vector>

#include "./components/menu.h"
#include "./workspaces/sign_in.h"
#include "./workspaces/workspace.h"
#include "raylib.h"
#include "screen.h"

namespace tls_certificate {

class Window {
   public:
    constexpr static float kMargin = 2.0f;

    Window(const Color &background);
    Window(const Window &that) = delete;             // Copy constructor
    Window(Window &&that) noexcept;                  // Move constructor
    Window &operator=(const Window &that) = delete;  // Copy assignment operator
    Window &operator=(Window &&that) noexcept;       // Move assignment operator
    ~Window() = default;

    std::shared_ptr<workspaces::Workspace> workspace{};

    const std::vector<std::unique_ptr<components::Menu>> &menus() const & { return menus_; }
    std::vector<std::unique_ptr<components::Menu>> menus() && { return std::move(menus_); }

    void Update(Vector2 mouse_point);
    void DrawMenuBar();    // Display menu bar
    void DrawWorkspace();  // Display Window workspace

   private:
    Color background_color_ = WHITE;
    std::vector<std::unique_ptr<components::Menu>> menus_;

    void MakeMenus();
};

}  // namespace tls_certificate

#endif  // WINDOW_H_