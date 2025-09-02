//
// Created by lixia on 2025/9/2.
//

#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr {
    std::vector<Screen> screens{Screen(24, 80, ' ')};

public:
    using ScreenIdx = std::vector<Screen>::size_type;

    void clear(ScreenIdx);
    ScreenIdx add_screen(const Screen &);
};


inline void Window_mgr::clear(const ScreenIdx idx) {
    Screen & s = screens[idx];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Window_mgr::ScreenIdx Window_mgr::add_screen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}



#endif //WINDOW_MGR_H