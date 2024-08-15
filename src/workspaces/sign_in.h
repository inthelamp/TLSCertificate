/*
 * sign_in.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef WORKSPACE_SIGNIN_H_
#define WORKSPACE_SIGNIN_H_

#include <iostream>

#include "../components/button.h"
#include "../components/input_box.h"
#include "raylib.h"
#include "workspace.h"

namespace tls_certificate::workspaces {

class SignIn : public Workspace {
   public:
    SignIn(const char *name, int name_length);
    SignIn(const SignIn &) = delete;             // Copy constructor
    SignIn(SignIn &&) = delete;                  // Move constructor
    SignIn &operator=(const SignIn &) = delete;  // Copy assignment operator
    SignIn &operator=(SignIn &&) = delete;       // Move assignment operator
    ~SignIn() {
        delete user_name_input_;
        delete password_input_;
        delete sign_in_;
        delete sign_up_;
        delete forgot_;
    }

    void MakeWorkspace() override;
    void Update() override;
    void Draw() override;

   private:
    Text user_name_label_{"User Name", 10};
    Text password_label_{"Password", 9};
    components::InputBox *user_name_input_{nullptr};
    components::InputBox *password_input_{nullptr};
    components::Button *sign_in_{nullptr};
    components::Button *sign_up_{nullptr};
    components::Button *forgot_{nullptr};
};

}  // namespace tls_certificate::workspaces

#endif  // WORKSPACE_SIGNIN_H_