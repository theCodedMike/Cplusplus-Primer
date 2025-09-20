//
// Created by lixia on 2025/9/19.
//

#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include "Message.h"

class Folder {
    friend void swap(Folder &lhs, Folder &rhs) noexcept;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void add_msg(Message * msg);
    void rem_msg(Message * msg);
private:
    std::set<Message *> messages;

    void save_msgs(const Folder &);
    void clear_msgs();
};

/****************************************************private****************************************************/
inline void Folder::save_msgs(const Folder &f) {
    for (const auto msg: f.messages) {
        msg->save(*this);
    }
}

inline void Folder::clear_msgs() {
    for (const auto msg: messages) {
        msg->remove(*this);
    }
}

/****************************************************public****************************************************/
inline Folder::Folder(const Folder & f) :
    messages(f.messages)
{
    save_msgs(f);
}

inline Folder &Folder::operator=(const Folder & f) {
    clear_msgs();
    messages = f.messages;
    save_msgs(f);
    return *this;
}

inline Folder::~Folder() {
    clear_msgs();
}


inline void Folder::add_msg(Message *msg) {
    messages.insert(msg);
}

inline void Folder::rem_msg(Message *msg) {
    messages.erase(msg);
}

/****************************************************friend****************************************************/
inline void swap(Folder &lhs, Folder &rhs) noexcept {
    using std::swap;
    for (const auto msg: lhs.messages) {
        msg->remove(lhs);
    }
    for (const auto msg: rhs.messages) {
        msg->remove(rhs);
    }

    swap(lhs.messages, rhs.messages);

    for (const auto msg: lhs.messages) {
        msg->save(lhs);
    }
    for (const auto msg: rhs.messages) {
        msg->save(rhs);
    }
}
#endif //FOLDER_H