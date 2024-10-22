#include <iostream>

using namespace std;

struct sf {
    int m;
    int n;
    bool next; 
};

unsigned long ackermann(int m, int n) {
    sf stack[1000]; // 定義堆疊的大小
    int top = -1; // 堆疊的指標
    unsigned long result = 0;

    stack[++top] = { m, n, true }; // 定義初始狀態

    while (top >= 0) 
    {
        sf frame = stack[top--];

        m = frame.m;
        n = frame.n;

        if (m == 0) 
        {
            result = n + 1;
        }
        else if (m == 1) 
        {
            result = n + 2; 
        }
        else if (m == 2) 
        {
            result = 2 * n + 3; 
        }
        else if (m >= 3) 
        {
            if (n == 0) 
            {
                stack[++top] = { m - 1, 1, true }; 
            }
            else {
                stack[++top] = { m - 1, -1, true }; // 記錄需要計算 A(m-1, A(m, n-1))
                stack[++top] = { m, n - 1, true }; // 記錄 A(m, n - 1)
                continue; 
            }
        }
        if (frame.next) 
        {
            if (top >= 0) 
            {
                sf prevFrame = stack[top];
                if (prevFrame.n == -1) 
                {
                    stack[top].n = result; // 設置結果為之前計算的結果
                }
            }
        }
    }

    return result;
S}

int main() {
    unsigned int m, n;
    cout << "輸入 m 和 n：";
    cin >> m >> n;

    unsigned long result = ackermann(m, n); // 計算阿克曼函數
    cout << "結果 = " << result << endl; // 輸出結果
    return 0;
}



 