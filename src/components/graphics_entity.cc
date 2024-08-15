/*
 * graphics_entity.cc
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */
#include "graphics_entity.h"

namespace tls_certificate::components {

#if !defined(EMSCRIPTEN)
template class GraphicsEntity<Circle>;
template class GraphicsEntity<Rectangle>;

template <typename T>
GraphicsEntity<T>::GraphicsEntity(const T &shape, const Vector2 &position, const Color &color)
    : shape_(shape), position_(position), color_(color) {}
#endif

#if defined(EMSCRIPTEN)
template <>
GraphicsEntity<Circle>::GraphicsEntity(const Circle &shape, const Vector2 &position, const Color &color)
    : shape_(shape), position_(position), color_(color) {}

template <>
GraphicsEntity<Rectangle>::GraphicsEntity(const Rectangle &shape, const Vector2 &position, const Color &color)
    : shape_(shape), position_(position), color_(color) {}
#endif

template <>
void GraphicsEntity<Rectangle>::position(const Vector2 &position) {
    shape_.x = position.x;
    shape_.y = position.y;

    position_ = position;
}

template <>
void GraphicsEntity<Circle>::position(const Vector2 &position) {
    position_ = position;
}

template <>
void GraphicsEntity<Rectangle>::position(Vector2 &&position) {
    shape_.x = position.x;
    shape_.y = position.y;
    position_ = std::move(position);
}

template <>
void GraphicsEntity<Circle>::position(Vector2 &&position) {
    position_ = std::move(position);
}

template <>
void GraphicsEntity<Rectangle>::position_x(float x) {
    shape_.x = x;
    position_.x = x;
}

template <>
void GraphicsEntity<Circle>::position_x(float x) {
    position_.x = x;
}

template <>
void GraphicsEntity<Rectangle>::position_y(float y) {
    shape_.y = y;
    position_.y = y;
}

template <>
void GraphicsEntity<Circle>::position_y(float y) {
    position_.y = y;
}

}  // namespace tls_certificate::components