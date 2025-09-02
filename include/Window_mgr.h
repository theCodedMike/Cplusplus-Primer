//
// Created by lixia on 2025/9/2.
//

#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

using ScreenIdx = std::vector<Screen>::size_type;

class Window_mgr {
    std::vector<Screen> screens{Screen(24, 80, ' ')};

public:
    void clear(ScreenIdx);
};


inline void Window_mgr::clear(const ScreenIdx idx) {
    Screen & s = screens[idx];
    s.contents = std::string(s.height * s.width, ' ');
}



#endif //WINDOW_MGR_H