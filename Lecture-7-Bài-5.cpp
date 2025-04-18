#include <iostream>
#include <vector>

/**
 * Hàm in ra một hoán vị
 * @param permutation Hoán vị cần in
 */
void printPermutation(const std::vector<int>& permutation) {
    for (int num : permutation) {
        std::cout << num;
    }
    std::cout << std::endl;
}

/**
 * Hàm đảo ngược đoạn từ chỉ số start đến end trong vector
 */
void reverse(std::vector<int>& arr, int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

/**
 * Hàm sinh hoán vị kế tiếp (tương đương std::next_permutation)
 * Trả về true nếu tồn tại hoán vị kế tiếp, false nếu không
 */
bool nextPermutation(std::vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    // Bước 1: tìm phần tử đầu tiên từ cuối mảng sao cho arr[i] < arr[i + 1]
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // Nếu không tìm thấy thì đây là hoán vị cuối cùng
    if (i < 0) return false;

    // Bước 2: tìm phần tử nhỏ nhất bên phải i nhưng lớn hơn arr[i]
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    // Bước 3: hoán đổi chúng
    std::swap(arr[i], arr[j]);

    // Bước 4: đảo ngược đoạn sau vị trí i
    reverse(arr, i + 1, n - 1);

    return true;
}

/**
 * Hàm tạo tất cả các hoán vị có độ dài n
 */
void generatePermutations(int n) {
    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    // In hoán vị đầu tiên
    printPermutation(permutation);

    // Sinh và in các hoán vị tiếp theo
    while (nextPermutation(permutation)) {
        printPermutation(permutation);
    }
}

int main() {
    int n;

    std::cout << "Nhap do dai cua hoan vi: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Do dai phai la so nguyen duong." << std::endl;
        return 1;
    }

    generatePermutations(n);

    return 0;
}
