/*
 * rounded_rect.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef ROUNDEDRECT_H_
#define ROUNDEDRECT_H_

#include "../screen.h"
#include "graphics_entity.h"
#include "raylib.h"

namespace tls_certificate::components {

class RoundedRect : public GraphicsEntity<Rectangle> {
   public:
    RoundedRect(const Rectangle &rec, float roundness, float segments);
    RoundedRect(const Rectangle &rec, float pos_y, float roundness, float segments);

    float roundness() { return roundness_; }
    float segments() { return segments_; }

   private:
    float roundness_ = 0.2f;
    float segments_ = 0.0f;

    constexpr static Vector2 position(const Rectangle &rec, float pos_y) {
        return (Vector2){Screen::MaxWindowSize().width / 2 - rec.width / 2, pos_y};
    }
};

}  // namespace tls_certificate::components

#endif  // ROUNDEDRECT_H_
