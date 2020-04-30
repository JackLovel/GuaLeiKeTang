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

// 作业 3
//
string ljust(string s, int width, char fillchar=' ') {
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
        result = s + r;
    } else {
        result = s;
    }

    return result;
}

// 测试函数
void
testLjust() {
    ensure(ljust("gua", 5) == "gua  ", "ljust 测试 1");
    ensure(ljust("guagua", 5) == "guagua", "ljust 测试 2");
    ensure(ljust("gua", 5, '*') == "gua**", "ljust 测试 3");
}

// 作业 4
//

string nChar1(int n, char fillchar=' ') {
    // char fillchar = '0';
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}


string
center(const string &s, int width, char fillchar=' ') {
    string result = "";
    int n = s.length() - width;
    if (n < 0) {
        n = -n;

        int lr = 0;
        int rr = 0;

        if (n % 2 == 0) {
            lr = rr = n / 2;
        } else {
            lr = n / 2;
            rr = n - lr;
        }

        result =  nChar1(lr, fillchar) + s + nChar1(rr, fillchar);
    } else {
        result = s;
    }

    return result;
}

// 测试函数
void
testCenter() {
    // log(center)
    ensure(center("gua", 5) == " gua ", "center 测试 1");
    ensure(center("gua", 5, '*') == "*gua*", "center 测试 2");
    ensure(center("gw", 5) == " gw  ", "center 测试 3");
    ensure(center("gua", 6) == " gua  ", "center 测试 4");
}


// 作业 5
bool
isSpace(const string &s) {
    if (s == " " || s == "") {
        return false;
    }

    size_t n = 0;
    while (n < s.size()) {
        if (s[n] != ' ') {
            return false;
        }
        n++;
    }

    return true;
}

// 测试函数
void
testIsSpace() {
    ensure(isSpace(" "), "isSpace 测试 1");
    ensure(isSpace("   "), "isSpace 测试 2");
    ensure(isSpace(""), "isSpace 测试 3");
    ensure(isSpace("gua"), "isSpace 测试 4");
    ensure(isSpace("  gua"), "isSpace 测试 5");
}

// 作业 6
//
bool
isDigit(const string &s) {
    // 检查 s 中是否只包含数字
    // 返回: 布尔值

    // 提示:
    // 类似于作业 5, 判断的条件从空格变为了数字

    // 实现步骤
    // 1. 复制 isSpace 函数中的代码
    // 2. 将判断字符是否为空格的部分改为判断是否为数字
    //     通过判断字符是否在字符串 "0123456789" 中, 来判断其是否为数字
    if (s == " " || s == "") {
        return false;
    }

    size_t n = 0;
    while (n < s.size()) {
        char c = s[n];
        if (find("0123456789", c) == -1) {
            return false;
        }
        n++;
    }

    return true;
}

// 测试函数
void
testIsDigit() {
    ensure(isDigit("123"), "is_digit 测试 1");
    ensure(isDigit("0"), "is_digit 测试 2");
    ensure(!isDigit("  "), "is_digit 测试 3");
    ensure(!isDigit("1.1"), "is_digit 测试 4");
    ensure(!isDigit("gua"), "is_digit 测试 5");
    ensure(!isDigit(""), "is_digit 测试 6");
}

// 作业 7
//
string
stripLeft(const string &s) {
    // 返回一个「删除了字符串开始的所有空格」的字符串

    // 返回 string

    // 实现步骤
    // 从左侧遍历字符串, 记录第一个非空格字符的位置, 并由此切割字符串
    // 1. 使用作业 5 的 isSpace 函数来判断 s 是否只包含空格，
    //    如果 s 只包含空格，返回空字符串
    // 2. 遍历字符串找到不是空格的字符的下标
    // 3. 切片并返回
    //      string 的切片方法如下
    //             0123456789
    // string s = "kuaibiancheng";
    // string s1 = s.substr(2, 5);
    // 结果是 aibia
    // 第一个参数表示开始的下标，第二个参数表示切片的个数
    if (isSpace(s)) {
        return "";
    }

    size_t n = 0;
    size_t len = s.size();
    while (n < len) {
        auto e = s[n];
        if (e != ' ') {
            size_t sliceOfNumber = len - n;
            return s.substr(n, sliceOfNumber);
        }
        n++;
    }

    return "";
}

// 测试函数
void
testStripLeft() {
//    log(stripLeft("  gua").size());
    ensure(stripLeft("  gua") == "gua", "stripLeft 测试 1");
    ensure(stripLeft(" gua  ") == "gua  ", "stripLeft 测试 2");
    ensure(stripLeft("") == "", "stripLeft 测试 3");
    ensure(stripLeft("    ") == "", "stripLeft 测试 4");
}


// 作业 8
//
string
stripRight(const string &s) {
    // 返回一个「删除了字符串末尾的所有空格」的字符串

    // 提示:
    // 类似于作业 7
    // 区别在于这次需要从右至左遍历字符串

    // 实现步骤
    // 1. 创建一个循环, 从右到左遍历字符串
    //     从右到左遍历的方式是让数字从 n 到 0
    // 2. 遍历字符串找到不是空格的字符的下标
    // 3. 切片并返回
    if (isSpace(s)) {
        return "";
    }

    size_t sliceOfNumber = 0;
    size_t len = s.size();
    size_t n = len - 1;
    while (n >= 0) {
        auto e = s[n];
        if (e != ' ') {
            sliceOfNumber = n + 1;
            return s.substr(0, sliceOfNumber);

        }
        n--;
    }

    return "";
}

// 测试函数
void
testStripRight() {
    ensure(stripRight("gua") == "gua", "stripRight 测试 1");
    ensure(stripRight(" gua  ") == " gua", "stripRight 测试 2");
    ensure(stripRight("") == "", "stripRight 测试 3");
    ensure(stripRight("    ") == "", "stripRight 测试 4");
}


// 作业 9
//
string
strip(const string &s) {
    // 返回一个「删除了字符串首尾的所有空格」的字符串

    // 返回 string

    // 提示:
    // 依次调用作业 7 和作业 8 中的函数即可

    // 分布提示:
    // 1. 调用 stripLeft
    // 2. 对上一步的结果继续调用 stripRight
    // 3. 返回结果
    string result = "";
    result = stripLeft(s);
    result = stripRight(result);

    return result;
}

// 测试函数
void
testStrip() {
    ensure(strip("  gua") == "gua", "strip 测试 1");
    ensure(strip(" gua  ") == "gua", "strip 测试 2");
    ensure(strip("") == "", "strip 测试 3");
    ensure(strip("    ") == "", "strip 测试 4");
}


// 作业 10
//
string
replace(const string &s, const string &old_str, const string &new_str) {
    // 返回一个「将 s 中的 old_str 字符串替换为 new_str 字符串」的字符串
    // 假设 old 存在并且只出现一次

    // 返回 string

    // 提示:
    // 找到指定旧字符串的起始下标, 将其前后字符串与新字符串进行拼接

    // 实现步骤
    // 1. 找到 old_str 的下标
    // 2. 把 s 切成 2 个不包含 old_str 的字符串
    // 3. 拼接并返回结果

    size_t found = s.find(old_str);
    string str1 = s.substr(0, found);
    size_t old_size = old_str.size();
    size_t str2_index =  found + old_size;
    size_t str2_size = s.size() - (str1.size() + old_str.size());
    string str2 = s.substr(str2_index, str2_size);

    string result = str1 + new_str + str2;
    return result;
}

// 测试函数
void
testReplace() {
    ensure(replace("guagua", "ag", "l") == "gulua", "replace 测试 1");
    ensure(replace("g  ", "  ", "a") == "ga", "replace 测试 2");
    ensure(replace("l", "l", "") == "", "replace 测试 3");
}

void
test() {
    // testZfill();
    // testRjust();
    // testLjust();
    // testCenter();
//     testIsSpace();
//    testIsDigit();
//    testStripLeft();
//    testStripRight();
//    testStrip();
    testReplace();
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}
