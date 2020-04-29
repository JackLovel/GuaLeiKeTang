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

void
test() {
    // testZfill();
    // testRjust();
    // testLjust();
    testCenter(); 
    // 剩下的测试函数调用需要你自行补足
}

int
main(int argc, const char *argv[]) {
    test();

    return 0;
}