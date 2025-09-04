# 第8章 类
## 8.1 IO类
<table>
    <tr>
        <th colspan="4">表8.1 IO库类型和头文件</th>
    </tr>
    <tr>
        <td>头文件</td> <th colspan="3">类型</th>
    </tr>
    <tr>
        <td>iostream</td> 
            <td>istream, wistream 从流读取数据</td>
            <td>ostream, wostream 从流写入数据</td>
            <td>iostream, wiostream 读写流</td>
    </tr>
    <tr>
        <td>fstream</td> 
            <td>ifstream, wifstream 从文件读取数据</td>
            <td>ofstream, wofstream 向文件写入数据</td>
            <td>fstream, wfstream 读写文件</td>
    </tr>
    <tr>
        <td>sstream</td> 
            <td>istringstream, wistringstream 从string读取数据</td>
            <td>ostringstream, wostringstream 向string写入数据</td>
            <td>stringstream, wstringstream 读写string</td>
    </tr>
</table>

### 8.1.1 IO对象无拷贝或赋值
### 8.1.2 条件状态
### 8.1.3 管理输出缓冲
缓冲区刷新的原因可能有：
- 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行
- 缓冲区满时，需要刷新缓冲
- 使用操作符如endl来显式刷新缓冲区
- 在输出操作之后，使用操作符unitbuf设置流的内部状态来清空缓冲区。默认情况下，对cerr是设置了unitbuf的
- 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。默认情况下，cin和cout被关联到cout

## 8.2 文件输入输出
### 8.2.1 使用文件流对象
### 8.2.2 文件模式

## 8.3 string流
### 8.3.1 使用istringstream
### 8.3.2 使用ostringstream










## 第8章 练习题
### 8.1.2节练习
<b>练习8.1</b> 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。
它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

<b>练习8.2</b> 测试函数，调用参数为cin。

<b>练习8.3</b> 什么情况下，下面的while循环会终止？
```c++
while(cin >> i) /* ... */
```



