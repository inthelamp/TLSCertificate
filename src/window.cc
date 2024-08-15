/*
 * window.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "window.h"

namespace tls_certificate {

Window::Window(const Color &background_color) : background_color_(background_color) { MakeMenus(); }

Window::Window(Window &&that) noexcept { *this = std::move(that); }

Window &Window::operator=(Window &&that) noexcept {
    if (this != &that) {
        background_color_ = that.background_color_;
        menus_ = std::move(that.menus_);
    }
    return *this;
}

void Window::MakeMenus() {
    float pos_x = 0;

    // Home
    std::unique_ptr<components::Menu> home = std::make_unique<components::Menu>("Home ", Vector2{pos_x, 0});
    pos_x = pos_x + home.get()->shape().width;
    menus_.emplace_back(std::move(home));

    // Sign-in
    std::unique_ptr<components::Menu> sign_in = std::make_unique<components::Menu>("Sign In", Vector2{pos_x, 0});
    sign_in->workspace = std::make_shared<workspaces::SignIn>(sign_in->name(), 8);
    menus_.emplace_back(std::move(sign_in));
}

void Window::Update(Vector2 mouse_point) {
    // Check if one of menus is clicked
    for (auto &menu : menus_) {
        menu.get()->CheckClick(mouse_point);
        if (menu.get()->state() == components::kPressed) {
            workspace = menu.get()->workspace;
            break;  // Pressed, then out of this loop
        }
    }
    if (workspace != nullptr) {
        workspace->Update();
    }
}

void Window::DrawMenuBar() {
    DrawRectangle(0, 0, Screen::MaxWindowSize().width, components::Menu::kHeight, background_color_);
    for (auto const &menu : menus_) {
        menu.get()->Draw();
    }
}

void Window::DrawWorkspace() {
    DrawRectangle(0, components::Menu::kHeight, Screen::MaxWindowSize().width,
                  Screen::MaxWindowSize().height - components::Menu::kHeight, background_color_);
    if (workspace.get() != nullptr) {
        workspace.get()->Draw();
    }
}

}  // namespace tls_certificate