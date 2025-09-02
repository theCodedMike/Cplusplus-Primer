//
// Created by lixia on 2025/9/1.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using pos = std::string::size_type;

class Screen {
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_cnt = 0; // 可变数据成员

    void do_display(std::ostream &os) const { os << contents;}

public:
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; } // 隐式内联
    inline char get(pos r, pos c) const; // 显示内联方式1
    Screen & move(pos r, pos c); // 显示内联方式2  推荐
    void member_fn_call() const;

    Screen & set(char);
    Screen & set(pos, pos, char);

    Screen & display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen & display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

// friend
    friend class Window_mgr; // 令类作为友元
    //friend void Window_mgr::clear(ScreenIdx); // 令成员函数作为友元 好像行不通？？？
};

char Screen::get(pos r, pos c) const {
    return contents[ r * width + c];
}

inline Screen & Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline void Screen::member_fn_call() const {
    ++access_cnt;
}

inline Screen & Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen & Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

#endif //SCREEN_H