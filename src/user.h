/*
 * user.h
 *
 *  Created on: June 21, 2024
 *      Author: Dong Won Kim
 */

#ifndef USER_H_
#define USER_H_

namespace tls_certificate {

enum UserState { kIntro, kPlay, kLevelUp, kOut, kEnd, kGoodbye };

class User {
   public:
    UserState state() { return state_; }
    void state(UserState state) { state_ = state; }

   private:
    UserState state_ = kIntro;  // User status
};

}  // namespace tls_certificate
#endif  // USER_H_