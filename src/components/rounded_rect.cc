/*
 * rounded_rect.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#include "rounded_rect.h"

namespace tls_certificate::components {
RoundedRect::RoundedRect(const Rectangle &rec, float roundness, float segments)
    : GraphicsEntity<Rectangle>(rec, (Vector2){rec.x, rec.y}), roundness_(roundness), segments_(segments) {}

RoundedRect::RoundedRect(const Rectangle &rec, float pos_y, float roundness, float segments)
    : GraphicsEntity<Rectangle>(rec, position(rec, pos_y)), roundness_(roundness), segments_(segments) {}

}  // namespace tls_certificate::components