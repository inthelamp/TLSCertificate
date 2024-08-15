/*
 * graphics_entity.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef GRAPHICS_ENTITY_H_
#define GRAPHICS_ENTITY_H_

#include <typeinfo>
#include <utility>

#include "circle.h"
#include "raylib.h"

namespace tls_certificate::components {

template <typename T>
class GraphicsEntity {
   public:
    GraphicsEntity(const T &shape, const Vector2 &position, const Color &color = WHITE);
    GraphicsEntity(const GraphicsEntity &) = delete;             // Copy constructor
    GraphicsEntity(GraphicsEntity &&) = delete;                  // Move constructor
    GraphicsEntity &operator=(const GraphicsEntity &) = delete;  // Copy assignment operator
    GraphicsEntity &operator=(GraphicsEntity &&) = delete;       // Move assignment operator
    virtual ~GraphicsEntity() = default;

    const T &shape() const & { return shape_; }
    T shape() && { return std::move(shape_); }
    void shape(const T &shape) { shape_ = shape; }
    void shape(T &&shape) { shape_ = std::move(shape); }

    const Vector2 &position() const { return position_; }
    float position_x() { return position_.x; }
    float position_y() { return position_.y; }
    void position(const Vector2 &position);
    void position(Vector2 &&position);
    void position_x(float x);
    void position_y(float y);

    const Color &color() const { return color_; }

    virtual void Draw() = 0;  // Display game object

   private:
    T shape_;
    Vector2 position_;
    Color color_;
};

}  // namespace tls_certificate::components

#endif  // GRAPHICS_ENTITY_H_
