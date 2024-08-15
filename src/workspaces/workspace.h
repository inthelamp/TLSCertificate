/*
 * workspace.h
 *
 *  Created on: July 19, 2024
 *      Author: Dong Won Kim
 */

#ifndef WORKSPACE_H_
#define WORKSPACE_H_

#include <utility>

#include "../text.h"

namespace tls_certificate::workspaces {

class Workspace {
   public:
    constexpr static int kLabelFontSize = 25;  // Default Y-axis of workspace name
    Workspace(const char *name, int name_length) : name_{name, name_length} {}
    Workspace(const Workspace &) = delete;             // Copy constructor
    Workspace(Workspace &&) = delete;                  // Move constructor
    Workspace &operator=(const Workspace &) = delete;  // Copy assignment operator
    Workspace &operator=(Workspace &&) = delete;       // Move assignment operator
    virtual ~Workspace() = default;

    const Text &name() const & { return name_; }
    Text name() && { return std::move(name_); }

    virtual void MakeWorkspace() = 0;
    virtual void Update() = 0;
    virtual void Draw() { DrawName(); }

   private:
    constexpr static int kNamePosY = 30;  // Default Y-axis of workspace name
    Text name_;                           // Workspace name

    void DrawName() { name_.DrawMiddle(kNamePosY); }  // Draw workspace name
};

}  // namespace tls_certificate::workspaces

#endif  // WORKSPACE_H_