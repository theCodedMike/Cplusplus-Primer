//
// Created by lixia on 2025/9/6.
//

#include <vector>
#include <list>
#include <forward_list>
#include <queue>
#include <stack>

#include "../include/Utils.h"
using namespace std;

void container_type_member();
void init();
void assign_and_swap();
void size_operation();
void relation_operation();
void insert_elem();
void access_elem();
void remove_elem();
void operate_forward_list();
void resize();
void iterator_invalid();
void manage_capacity();
void more_string_operation();
void container_adapter();

int main(int argc, char *argv[]) {
    //container_type_member();
    //init();
    //assign_and_swap();
    //size_operation();
    //relation_operation();
    //add_elem();
    //access_elem();
    //remove_elem();
    //operate_forward_list();
    //resize();
    //iterator_invalid();
    //manage_capacity();
    //more_string_operation();
    container_adapter();
}

// 容器类型成员
void container_type_member() {
    int val = 42;
    vector<int>::iterator iter;
    vector<int>::const_iterator citer;
    vector<int>::reverse_iterator riter;
    vector<int>::const_reverse_iterator criter;
    vector<int>::size_type sz;
    vector<int>::value_type vt;
    vector<int>::difference_type diff;

    vector<int>::allocator_type alloc;
    vector<int>::pointer p;
    vector<int>::const_pointer ptr;
    vector<int>::reference ref = val;
    vector<int>::const_reference cref = 0;
}

void init() {
    const vector<int> v1 = {1, 3, 5, 7, 9};
    print_collection(v1); // [1, 3, 5, 7, 9]

    const vector<int> v2{2, 4, 6, 8, 10};
    print_collection(v2); // [2, 4, 6, 8, 10]

    const vector<int> v3;
    print_collection(v3); // []

    const vector<int> v4(v1);
    print_collection(v4); // [1, 3, 5, 7, 9]

    const vector<int> v5 = v2;
    print_collection(v5); // [2, 4, 6, 8, 10]

    const vector<int> v6(v1.cbegin(), v1.cend());
    print_collection(v6); // [1, 3, 5, 7, 9]

    const vector<int> v7(5);
    print_collection(v7); // [0, 0, 0, 0, 0]

    const vector<int> v8(5, 1);
    print_collection(v8); // [1, 1, 1, 1, 1]
}


void assign_and_swap() {
    vector<string> v1 = {"1", "2", "3"};
    vector<string> v2 = {"4", "5"};

    std::swap(v1, v2);
    print_collection(v1); // [4, 5]
    print_collection(v2); // [1, 2, 3]

    v1.swap(v2);
    print_collection(v1); // [1, 2, 3]
    print_collection(v2); // [4, 5]

    vector<string> v3;
    v3.assign(v1.cbegin(), v1.cend());
    print_collection(v3); // [1, 2, 3]

    vector<string> v4;
    initializer_list<string> ilist = {"Allen", "Bob", "Tomas"};
    v4.assign(ilist);
    print_collection(v4); // [Allen, Bob, Tomas]

    vector<string> v5;
    v5.assign(7, "Tom");
    print_collection(v5); // [Tom, Tom, Tom, Tom, Tom, Tom, Tom]
}

void size_operation() {
    vector<int> v = {9, 3, 5, 2, 8};
    cout << "size: " << v.size() << endl;         // 5
    cout << "capacity: " << v.capacity() << endl; // 5
    cout << "max_size: " << v.max_size() << endl; // 2305843009213693951
    cout << "empty: " << v.empty() << endl;       // 0 false
}

void relation_operation() {
    const vector<int> v1 = { 1, 3, 5, 7, 9, 12};
    const vector<int> v2 = { 1, 3, 9};
    const vector<int> v3 = { 1, 3, 5, 7};
    const vector<int> v4 = { 1, 3, 5, 7, 9, 12};
    cout << "v1 < v2: " << (v1 < v2) << endl; // true
    cout << "v1 < v3: " << (v1 < v3) << endl; // false
    cout << "v1 == v4: " << (v1 == v4) << endl; // true
    cout << "v1 == v2: " << (v1 == v2) << endl; // false
}

void insert_elem() {
    vector<int> v;

    v.push_back(1);
    print_collection(v); // [1]

    // 直接使用传入的参数在容器分配的内存中构造对象，避免了临时对象的创建
    // 对于复杂对象，emplace_back 通常更高效，因为它避免了临时对象的创建和拷贝/移动操作
    // emplace_back 是 push_back 的优化版本，通过完美转发参数直接在容器内部构造对象，避免不必要的拷贝或移动操作
    v.emplace_back(2);
    print_collection(v); // [1, 2]

    v.insert(v.cbegin(), 0);
    print_collection(v); // [0, 1, 2]

    v.insert(v.cbegin() + 1, 10);
    print_collection(v); // [0, 10, 1, 2]

    v.insert(v.cend(), 3, -1);
    print_collection(v); // [0, 10, 1, 2, -1, -1, -1]

    vector<int> v2 = {-9, 33};
    v.insert(v.cend(), v2.cbegin(), v2.cend());
    print_collection(v); // [0, 10, 1, 2, -1, -1, -1, -9, 33]

    initializer_list<int> ilist = {-2, -2};
    v.insert(v.cend(), ilist);
    print_collection(v); // [0, 10, 1, 2, -1, -1, -1, -9, 33, -2, -2]
}

void access_elem() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << *v.cbegin() << " " << v.front() << endl;   // 1 1 注意判空
    cout << *(v.cend() - 1) << " " << v.back() << endl;// 5 5
    cout << v[0] << " " << v.at(0) << endl; // 1 1

    v[0] = -1;
    print_collection(v); // [-1, 2, 3, 4, 5]
    v.front() = -2;
    print_collection(v); // [-2, 2, 3, 4, 5]
    v.at(0) = -3;
    print_collection(v); // [-3, 2, 3, 4, 5]
}

void remove_elem() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    nums.pop_back(); // 其他容器还有pop_front()
    print_collection(nums); // [1, 2, 3, 4, 5, 6, 7, 8, 9]

    nums.erase(nums.begin());
    print_collection(nums); // [2, 3, 4, 5, 6, 7, 8, 9]

    nums.erase(nums.begin(), nums.begin() + 3); //  [begin, end)
    print_collection(nums); // [5, 6, 7, 8, 9]

    nums.clear();
    print_collection(nums); // []


    // 删除奇数元素
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = lst.begin();
    while (iter != lst.end()) {
        if (*iter % 2 == 1)
            iter = lst.erase(iter);
        else
            ++iter;
    }
    print_collection(lst); // [0, 2, 4, 6, 8]
}

void operate_forward_list() {
    // 删除奇数值
    forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    while (curr != flist.end()) {
        if (*curr % 2 == 1)
            curr = flist.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
    print_collection(flist); // [0, 2, 4, 6, 8]
}

void resize() {
    list<int> ilist(5, 42);
    print_collection(ilist); // [42, 42, 42, 42, 42]

    ilist.resize(7);
    print_collection(ilist); // [42, 42, 42, 42, 42, 0, 0]

    ilist.resize(10, -1);
    print_collection(ilist); // [42, 42, 42, 42, 42, 0, 0, -1, -1, -1]

    ilist.resize(6);
    print_collection(ilist); // [42, 42, 42, 42, 42, 0]
}

void iterator_invalid() {
    // 删除偶数元素，复制每个奇数元素
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2 == 1) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else
            iter = vi.erase(iter);
    }
    print_collection(vi); // [1, 1, 3, 3, 5, 5, 7, 7, 9, 9]
}

void manage_capacity() {
    vector<int> nums = {0, 1, 2, 3, 4};
    cout << "size: " << nums.size() << endl;     // 5
    cout << " cap: " << nums.capacity() << endl; // 5

    nums.push_back(5);
    cout << "size: " << nums.size() << endl;    // 6
    cout << " cap: " << nums.capacity() << endl;// 10

    nums.shrink_to_fit(); // make size and cap same
    cout << "size: " << nums.size() << endl;    // 6
    cout << " cap: " << nums.capacity() << endl;// 6

    nums.reserve(10);
    print_collection(nums); // [0, 1, 2, 3, 4, 5]
    cout << "size: " << nums.size() << endl;    // 6
    cout << " cap: " << nums.capacity() << endl;// 10

    nums.reserve(3); // 如果需求大小小于或等于当前容量，则什么也不做
    print_collection(nums); // [0, 1, 2, 3, 4, 5]
    cout << "size: " << nums.size() << endl;    // 6
    cout << " cap: " << nums.capacity() << endl;// 10

    nums.reserve(20);
    print_collection(nums); // [0, 1, 2, 3, 4, 5]
    cout << "size: " << nums.size() << endl;    // 6
    cout << " cap: " << nums.capacity() << endl;// 20
}

void more_string_operation() {
    const char *cp = "hello world!";
    char noNull[] = {'H', 'i'};
    string s1(cp); cout << s1 << endl; // hello world!
    string s2(noNull, 2); cout << s2 << endl; // Hi
    string s3(noNull); cout << s3 << endl; // 未定义，noNull不是以空字符结束
    string s4(cp + 6, 5); cout << s4 << endl; // world
    string s5(s1, 6, 5); cout << s5 << endl; // world
    string s6(s1, 6); cout << s6 << endl; // world!
    string s7(s1, 6, 20); cout << s7 << endl; // world!
    //string s8(s1, 16); cout << s8 << endl; // std::out_of_range
    cout << endl;

    string s("hello world");
    s2 = s.substr(0, 5); cout << s2 << endl; // hello
    s3 = s.substr(6); cout << s3 << endl; // world
    s4 = s.substr(6, 11); cout << s4 << endl; // world
    //s5 = s.substr(12); cout << s5 << endl; // std::out_of_range
    cout << endl;

    string non_ascii = "我爱你";
    s2 = non_ascii.substr(0, 2); cout << s2 << endl; // 乱码
    cout << endl;

    // s.insert(pos, args)
    // s.erase(pos, len)
    // s.assign(args)
    // s.append(args)
    // s.replace(range, args)
    //
    // args可以是下列形式之一
    // str               字符串str
    // str, pos, len     str中从pos开始最多len个子
    // cp, len           cp指向的字符数组前(最多)len个字符
    // cp                cp指向的以'\0'结束的字符数组
    // n, c              n个字符c
    // beg, end          迭代器[beg, end)范围内的字符
    // 初始化列表          花括号包围的，以逗号分割的字符列表
    s = "111111";
    s.insert(2, "222"); cout << s << endl; // 112221111
    s.erase(2, 3); cout << s << endl; // 111111
    s.assign("222222"); cout << s << endl; // 222222
    s.append("333"); cout << s << endl; // 222222333
    s.replace(6,3, "4444"); cout << s << endl; // 2222224444
    cout << endl;

    // s.find(args)
    // s.rfind(args)
    // s.find_first_of(args)
    // s.find_last_of(args)
    // s.find_first_not_of(args)
    // s.find_last_not_of(args)
    //
    // args必须是以下形式之一
    // c, pos
    // s2, pos
    // cp, pos
    // cp, pos, n
    s = "AnnaAnllemoe";
    const size_t pos1 = s.find("An"); // 0
    const size_t pos2 = s.rfind("An");// 4
    const size_t pos3 = s.find("BB"); // 18446744073709551615
    cout << (pos3 == string::npos) << endl; // 1
    string::size_type pos = 0;
    while ((pos = s.find_first_of("A", pos)) != string::npos) {
        cout << "find A at index: " << pos << endl;
        ++pos;
    }
    cout << endl;

    s = "Abc";
    s2 = "abc";
    cout << s.compare(s2) << endl; // -1
    cout << s2.compare(1, 1, s) << endl; // 1
    cout << endl;

    // to_string(val)
    // stoi(s, pos, bass)
    // stol(s, pos, base)
    // stoul(s, pos, base)
    // stoll(s, pos, base)
    // stoull(s, pos, base)
    // stof(s, pos)
    // stod(s, pos)
    // stold(s, pos)
    int i = 42;
    s = to_string(i);
    cout << s << " " << stoi(s) << endl; // 42 42
}

void container_adapter() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    cout << stk.top() << endl; // 2
    stk.pop();
    cout << stk.size() << endl; // 1
    cout << endl;

    queue<int> que;
    que.push(1);
    que.push(2);
    cout << que.front() << endl; // 1
    cout << que.back() << endl;  // 2
    que.pop();
    cout << que.size() << endl; // 1
    cout << endl;

    priority_queue<int> max_heap;
    max_heap.push(5); max_heap.push(1);
    max_heap.push(33);max_heap.push(-5);
    max_heap.push(55);max_heap.push(16);
    while (!max_heap.empty()) {
        cout << max_heap.top() << " "; // 55 33 16 5 1 -5
        max_heap.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<>> min_heap;
    min_heap.push(5); min_heap.push(1);
    min_heap.push(33);min_heap.push(-5);
    min_heap.push(55);min_heap.push(16);
    while (!min_heap.empty()) {
        cout << min_heap.top() << " "; // -5 1 5 16 33 55
        min_heap.pop();
    }
}