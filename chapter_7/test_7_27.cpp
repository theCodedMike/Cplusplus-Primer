//
// Created by lixia on 2025/9/2.
//
#include <iostream>
#include "../include/Screen.h"
using namespace std;


int main(int argc, char *argv[]) {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";

    myScreen.display(cout);
    cout << "\n";

    //XXXXXXXXXXXXXXXXXXXX#XXXX
    //XXXXXXXXXXXXXXXXXXXX#XXXX
}
