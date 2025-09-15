//
// Created by lixia on 2025/9/15.
//

#include <memory>
using namespace std;

struct destination;
struct connection {};

connection connect(destination *);
void disconnect(connection);

int main(int argc, char *argv[]) {

}

/*void end_connection(connection *p) {
    disconnect(*p);
}*/
auto end_connection = [](const connection *p) {
    disconnect(*p);
};

void f(destination &d) {
    connection con = connect(&d);
    shared_ptr<connection> p(&con, end_connection);
    // 使用连接
    // 当f退出时，con会被正确关闭
}

connection connect(destination * dp) {
    const connection con;
    return con;
}

void disconnect(connection) {

}
