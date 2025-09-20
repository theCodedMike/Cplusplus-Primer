//
// Created by lixia on 2025/9/19.
//

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include <utility>
#include "Folder.h"


class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs) noexcept;
public:
    explicit Message(std::string str = "") :
        contents(std::move(str)) {}
    Message(const Message &); // 拷贝构造
    Message &operator=(const Message &); // 拷贝赋值
    ~Message(); // 析构函数

    void save(Folder &);
    void remove(Folder &);
private:
    std::string contents; // 消息内容
    std::set<Folder*> folders; // 包含本消息的folder

    void add_to_folders(const Message &);
    void remove_from_folders();
};

/****************************************************private****************************************************/
inline void Message::add_to_folders(const Message & m) {
    for (const auto f: m.folders) {
        f->add_msg(this);
    }
}

inline void Message::remove_from_folders() {
    for (const auto f: folders) {
        f->rem_msg(this);
    }
}

/****************************************************public****************************************************/
inline Message::Message(const Message & m) :
    contents(m.contents), folders(m.folders)
{
    add_to_folders(m);
}

inline Message &Message::operator=(const Message & m) {
    remove_from_folders();
    contents = m.contents;
    folders = m.folders;
    add_to_folders(m);
    return *this;
}

inline Message::~Message() {
    remove_from_folders();
}

inline void Message::save(Folder & f) {
    folders.insert(&f);
    f.add_msg(this);
}

inline void Message::remove(Folder & f) {
    folders.erase(&f);
    f.rem_msg(this);
}

/****************************************************friend****************************************************/
inline void swap(Message &lhs, Message &rhs) noexcept {
    using std::swap; // 在本例中严格来说并不需要，但这是一个好习惯
    for (const auto f: lhs.folders) {
        f->rem_msg(&lhs);
    }
    for (const auto f: rhs.folders) {
        f->rem_msg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (const auto f: lhs.folders) {
        f->add_msg(&lhs);
    }
    for (const auto f: rhs.folders) {
        f->add_msg(&rhs);
    }
}

#endif //MESSAGE_H