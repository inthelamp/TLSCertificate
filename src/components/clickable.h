/*
 * clickable.h
 *
 *  Created on: June 27, 2024
 *      Author: Dong Won Kim
 */

#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include "raylib.h"

namespace tls_certificate::components {

enum ClickState { kNormal, kMouseHover, kPressed };

class Clickable {
   public:
    Clickable() = default;
    Clickable(const Clickable &) = delete;
    Clickable(Clickable &&) = delete;
    Clickable &operator=(const Clickable &) = delete;
    Clickable &operator=(Clickable &&) = delete;
    virtual ~Clickable() = default;

    const ClickState &state() const { return state_; }
    void state(const ClickState &state) { state_ = state; }
    bool activated() { return activated_; }
    void activated(bool activated) { activated_ = activated; }

    virtual void CheckClick(const Vector2 &mouse_point) = 0;

   private:
    ClickState state_ = kNormal;
    bool activated_ = false;
};

}  // namespace tls_certificate::components

#endif  // CLICKABLE_H_