#include <vector>
#include <iostream>
#include <string>

using namespace std;


template<class T>
void
_print(T arg) {
    cout << arg << " ";
}

template<class... Args>
void
log(Args... args) {
    int arr[] = { (_print(args), 0)... };
    cout << endl;
}

void
ensure(bool condition, const string &message) {
    // 在条件不成立的时候, 输出 message
    if (!condition) {
        log("*** 测试失败: ", message);
    } else {
        log("||| 测试成功");
    }
}

// 作业 1
//
string nChar(int n) {
    char fillchar = '0';
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}


string
zfill(int n, int width) {
    string n_str = to_string(n);
    if (n_str.length() < width) {
        return nChar(width - n_str.length()) + n_str;
    } else {
        return n_str; 
    }
}

// 测试函数
void
testZfill() {
    ensure(zfill(1, 4) == "0001", "zfill 测试 1");
    ensure(zfill(23, 4) == "0023", "zfill 测试 2");
    ensure(zfill(12345, 4) == "12345", "zfill 测试 3");
    ensure(zfill(169, 5) == "00169", "zfill 测试 4");
}

// 作业 2
//
string
rjust(const string &s, int width, char fillchar=' ') {
    // 如果 s 长度小于 width, 则在开头用 fillchar 填充并返回

    // 返回 string 类型

    // 提示:
    // 类似于作业 1, 但有几个区别
    // 一是不需要先用 string() 转换类型
    // 二是填充的字符不是 0 而是可以自行定义

    // 分步提示：
    // 1. 计算需要用 fillchar 生成的字符串长度
    // 2. 使用作业 1 中的辅助函数 nChar, 修改它以便符合本题的使用
    // 3. 调用修改后的 nChar 生成填充用的字符串
    // 4. 拼接并返回结果
    string result = ""; 
    int n = s.length() - width;
    if (n < 0) {
        n = -n; 
        string r = "";
        int i = 0;
        while(i < n) {
            r += fillchar;
            i += 1;
        }
        result = r + s; 
    } else {
        result = s; 
    }
    
    return result; 
}

// 测试函数
void
testRjust() {
    ensure(rjust("gua", 5) == "  gua", "rjust 测试 1");
    ensure(rjust("guagua", 5) == "guagua", "rjust 测试 2");
    ensure(rjust("gua", 5, '*') == "**gua", "rjust 测试 3");
}

void
test() {
    // testZfill();
    testRjust();
    // testLjust();
    // 剩下的测试函数调用需要你自行补足
}

int
main(int argc, const char *argv[]) {
    test();

    return 0;
}