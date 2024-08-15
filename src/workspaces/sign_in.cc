/*
 * sign_in.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "sign_in.h"

namespace tls_certificate::workspaces {

SignIn::SignIn(const char* name, int name_length) : Workspace(name, name_length) { MakeWorkspace(); }

void SignIn::MakeWorkspace() {
    user_name_input_ = new components::InputBox(20, 150.0f);
    password_input_ = new components::InputBox(20, 300.0f);
    // sign_in_ = new components::Button();
    // sign_up_ = new components::Button();
    // forgot_ = new components::Button();
}

void SignIn::Update() {
    user_name_input_->Update();
    password_input_->Update();
}

void SignIn::Draw() {
    // Draw workspace name as default
    Workspace::Draw();

    // Draw labels
    user_name_label_.Draw(user_name_input_->position_x(), user_name_input_->position_y() - kLabelFontSize,
                          kLabelFontSize);
    password_label_.Draw(password_input_->position_x(), password_input_->position_y() - kLabelFontSize, kLabelFontSize);

    // Draw inputs
    user_name_input_->Draw();  // Draw user name input
    password_input_->Draw();   // Draw password input
}

}  // namespace tls_certificate::workspaces