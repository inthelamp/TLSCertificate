/*
 * circle.h
 *
 *  Created on: June 20, 2024
 *      Author: Dong Won Kim
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <memory>

namespace tls_certificate::components {
class Circle {
   public:
    Circle(const float &radius) : radius_(radius) {}
    Circle(const Circle &) = default;
    Circle(Circle &&) noexcept = default;
    Circle &operator=(const Circle &) = default;
    Circle &operator=(Circle &&) noexcept = default;
    virtual ~Circle() = default;

    const float &radius() const & { return radius_; }
    float radius() && { return std::move(radius_); }
    void radius(const float &radius) { radius_ = radius; }

   private:
    float radius_;
};
}  // namespace tls_certificate::components

#endif  // CIRCLE_H_