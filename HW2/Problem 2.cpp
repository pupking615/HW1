#include <iostream>
#include <cstring> 

using namespace std;

void gp(char** set, int n, int index, char** cs, int setSize) {
    if (index == n) {
        std::cout << "{ ";
        for (int i = 0; i < setSize; i++) {
            std::cout << cs[i];
            if (i < setSize - 1) {
                std::cout << ", "; // 在元素之間添加逗號
            }
        }
        std::cout << " }" << std::endl;
        return;
    }

    // 不包含當前元素的情況
    gp(set, n, index + 1, cs, setSize); 
    // 包含當前元素的情況
    cs[setSize] = set[index];
    gp(set, n, index + 1, cs, setSize + 1);
}

int main() {
    int ms;
    cout << "請輸入集合成員數量: ";
    cin >> ms;

    char** set = new char* [ms]; // 動態分配字串陣列

    // 輸入集合的成員
    cout << "請輸入要產生冪集合的元素(請一個一個輸入):" << endl;
    for (int i = 0; i < ms; i++) {
        set[i] = new char[200]; // 假設每個字串的最大長度為199
        cin >> set[i];
    }

    char** cs = new char* [ms]; // 動態分配當前子集的陣列
    cout << "冪集合為:\n";
    gp(set, ms, 0, cs, 0); // 開始產生冪集合
}