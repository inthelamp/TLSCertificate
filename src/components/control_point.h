/*
 * control_point.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef CONTROL_POINT_H_
#define CONTROL_POINT_H_

#include "../screen.h"
#include "circle.h"
#include "graphics_entity.h"
#include "raylib.h"

namespace tls_certificate::components {

class ControlPoint : public GraphicsEntity<Circle> {
   public:
    constexpr static float kRadius = 34.0f;  // Control point radius
    constexpr static Color kColor = Color({255, 165, 0, 26});

    ControlPoint(const Vector2 &position);
    ControlPoint(float radius, const Vector2 &position, const Color &color);

    void Draw() override;

   private:
    static Circle circle() { return std::move(Circle(kRadius)); }

    static Circle circle(float radius) { return std::move(Circle(radius)); }
};

}  // namespace tls_certificate::components

#endif  // CONTROL_POINT_H_