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

// main 函数的参数是规定，复制粘贴即可
int
main(int argc, const char *argv[]) {

    return 0;
}