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

bool
floatEqual(float a, float b) {
    // 这里的 delta 变量的类型我们用了 auto
    // 这是一个 C++ 11 的新特性
    // 它的作用是根据变量的值自动推导变量的类型
    // delta 的值是 0.00001 所以它会是 float 类型
    // 仅作介绍
    auto delta = 0.00001;
    // 如《〖快编程〗的免费编程入门课》 所述
    // 计算机对浮点数的比较要用这样的方式
    return a - b < delta || b - a < delta;
}

float
sum(vector<float> &array) {
    // 先设置一个变量 s 用来存数组的和
    float s = 0;
    // .size() 函数的返回值是 size_t
    // 所以这里的变量 i 也是 size_t（你可以当作 int）
    size_t i = 0;
    // array.size() 求得 vector 的大小
    while (i < array.size()) {
        float n = array[i];
        s = s + n;
        i = i + 1;
    }
    return s;
}

void
testSum(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum(v1);
    // 判断浮点数相等，建议使用 floatEqual 函数
    ensure(floatEqual(s1, 10), "sum test error 1");
    //
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = sum(v2);
    ensure(floatEqual(s2, 21), "sum test error 2");
}

// 作业一
float
product(vector<float> &array) {
    float s = 1;
    size_t i = 0;
    while (i < array.size()) {
        float n = array[i];
        s = s * n;
        i = i + 1;
    }
    return s;
}

void
testProduct(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = product(v1);
    // 判断浮点数相等，建议使用 floatEqual 函数
    ensure(floatEqual(s1, 24), "sum test error 1");
    //
    vector<float> v2 = {1, 2, 3, 4, 5};
    float s2 = sum(v2);
    ensure(floatEqual(s2, 120), "sum test error 2");
}

// 作业二
float
abs1(float n) {
    if (n < 0) {
        n = -n;  
    }

    return n;
}

void
testAbs(void) {
    float v1 = -1;
    float s1 = abs1(v1);

    ensure(floatEqual(s1, 1), "sum test error 1");
}

// 作业三
float
average(vector<float> &array) {
    float s = sum(array);
    size_t n = array.size(); 

    float result = s / n; 
    return result;  
}

// 作业四
float
min1(vector<float> &array) {
    float s = array[0];
    for (size_t i = 0; i < array.size(); i++) {
        if (s > array[i]) {
            s = array[i];
        }
    }
    return s; 
}

// 作业五
int
sum2(int n) {
    float s = 1;
    size_t i = 1;
    
    for (size_t i = 2; i < n + 1; i++) {
        if (i % 2 == 0) {
            s = s + i;
        } else {
            s = s - i;
        }
    }
    return s;
}

// 作业七
int
fac1(int n) {
    size_t s = 1;

    for (size_t i = 1; i < n + 1; i++) {
        s = s * i; 
    } 

    return s; 
}

// int main()
// {
//     vector<float> array = {1.3, 1.2}; 
    
//     // cout << product(array) << endl; 
//     // cout << abs1(-21) << endl; 
//     // cout << average(array) << endl; 
//     // cout << min1(array) << endl; 
//     // cout << sum2(4) << endl; 
//     cout << fac1(3) << endl; 
   
//     return 0;
// }

void
test() {
    testSum();
    testProduct();
    testAbs();
}

// main 函数的参数是规定，复制粘贴即可
int
main(int argc, const char *argv[]) {
    test();

    return 0;
}