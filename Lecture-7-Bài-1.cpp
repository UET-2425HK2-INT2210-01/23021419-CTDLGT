#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> numbers;
    double num;

    // Nhập các số từ người dùng (dừng khi nhập ký tự không phải số)
    while (cin >> num) {
        numbers.push_back(num);
    }
 // Sắp xếp dãy số bằng thuật toán chọn (Selection Sort)
    for (size_t i = 0; i < numbers.size(); i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử hiện tại
        swap(numbers[i], numbers[minIndex]);
    }

    // In kết quả ra màn hình
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) cout << " ";
        cout << numbers[i];
    }
    cout << endl;

    return 0;
}
