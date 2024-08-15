/*
 * control_point.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "control_point.h"

namespace tls_certificate::components {

// ControlPoint::ControlPoint() : GraphicsEntity<Circle>(circle(), (Vector2){0.0f, 0.0f}, kColor) {}

ControlPoint::ControlPoint(const Vector2 &position) : GraphicsEntity<Circle>(circle(), position, kColor) {}

ControlPoint::ControlPoint(float radius, const Vector2 &position, const Color &color)
    : GraphicsEntity<Circle>(circle(radius), position, color) {}

void ControlPoint::Draw() { DrawCircleV(position(), this->shape().radius(), color()); }

}  // namespace tls_certificate::components