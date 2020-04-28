#include <iostream>
#include <vector>

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
    if (condition) {
        log("测试成功");
    } else {
        log(message);
    }
}
int
find(const string &s1, char s2) {
    // 返回 s2 在 s1 中的下标, 从 0 开始, 如果不存在则返回 -1
    size_t i = 0;
    int index = -1;
    while (i < s1.size()) {
        if (s2 == s1[i]) {
            index = i;
            break;
        }
        i = i + 1;
    }
    return index;
}
// 作业1
// 测试函数
void
testFind() {
    ensure(find("hello", 'a') == -1, "find 1");
    ensure(find("hello", 'e') == 1, "find 2");
    ensure(find("hello", 'l') == 2, "find 3");
}

// 下面给出一个例子作为后面作业的参考
// 返回字符串的小写形式的函数
// 注意, 这里假设了 s 字符串全是大写字母
string
lowercase(const string &s) {
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(upper, s[i]);
        // 字符串可以用加号拼接, 不明白可以 log 一下
        result += lower[index];
        i += 1;
    }
    return result;
}

// 测试函数
void
testLowercase() {
    ensure(lowercase("HELLO") == "hello", "lowercase 1");
    ensure(lowercase("GUA") == "gua", "lowercase 2");
}

// 作业2
string
uppercase(const string &s) {
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        // 字符串可以用加号拼接, 不明白可以 log 一下
        result += upper[index];
        i += 1;
    }
    return result;
}

// 测试函数
void
testUppercase() {
    ensure(uppercase("hello") == "HELLO", "uppercase 1");
    ensure(uppercase("gua") == "GUA", "uppercase 2");
}

// 作业 3
string
lowercase1(const string &s) {
   // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(upper, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += lower[index];            
        }

        i += 1;
    }
    return result;
}

void
testLowercase1() {
    ensure(lowercase1("heLLo") == "hello", "lowercase1 1");
    ensure(lowercase1("gua") == "gua", "lowercase1 2");
    ensure(lowercase1("GW") == "gw", "lowercase1 3");
}

// 作业 4
//
// 实现 uppercase1
// 它能正确处理带 大写字母 的字符串
//
// 实现步骤
//     1. 参考作业 3
string
uppercase1(const string &s) {
   // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += upper[index];            
        }

        i += 1;
    }
    return result;
}

void
testUppercase1() {
    ensure(uppercase1("helLo") == "HELLO", "uppercase1 1");
    ensure(uppercase1("gUA") == "GUA", "uppercase1 2");
}

// 作业 5
string
encode1(const string &s) {
// 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        if (index == 25) {
            result += 'a';
        } else {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += lower[index + 1];            
        }

        i += 1;
    }
    return result;
}

void
testEncode1() {
    ensure(encode1("afz") == "bga", "encode1 1");
    ensure(encode1("gw") == "hx", "encode1 2");
}

// 作业 6
string
decode1(const string &s) {
// 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        if (index == 0) {
            result += 'z';
        } else {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += lower[index - 1];            
        }

        i += 1;
    }
    return result;
}

void
testDecode1() {
    ensure(decode1("bga") == "afz", "decode1 1");
    ensure(decode1("hx") == "gw", "decode1 2");
}

// 作业 7
// 实现 encode2
// 多了一个参数 shift 表示移的位数
//
// 注意:
//     s 是一个只包含小写字母的字符串
//
// 实现步骤
//     1. 和作业 5 类似，不一样的地方在于这里是计算出 index 之后，找出 lower 中 index + shift 的元素，然后拼接在一起
//     2. 注意考虑边界情况，即 index + shift 超出了边界的情况

string
encode2(const string &s, int shift) {
// 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        if (index + shift <= 25) {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += lower[index + shift]; 
        } else {
            result += lower[(index + shift) - 26];      
        }

        i += 1;
    }
    return result;
}

void
testEncode2() {
    ensure(encode2("afz", 2) == "chb", "encode2 1");
    ensure(encode2("gw", 3) == "jz", "encode2 2");
}

// 作业 8
string
decode2(const string &s, int shift) {
// 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        if (index - shift >= 0) {
            // 字符串可以用加号拼接, 不明白可以 log 一下
            result += lower[index - shift]; 
        } else {
            result += lower[26 + (index - shift)];      
        }

        i += 1;
    }
    return result;
}

void
testDecode2() {
    ensure(decode2("chb", 2) == "afz", "decode2 1");
    ensure(decode2("jz", 3) == "gw", "decode2 2");
}

void test() {
    //testFind();   
    // testLowercase(); 
    // testUppercase();
    // testLowercase1();
    // testUppercase1();
    // testEncode1();
    // testDecode1();
    // testEncode2();
    testDecode2();
}


// main 函数的参数是规定，复制粘贴即可
int
main(int argc, const char *argv[]) {
    test(); 
    return 0;
}