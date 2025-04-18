#include <iostream>
#include <string>

using namespace std;

/**
 * Hàm đệ quy tạo ra tất cả các số nhị phân có độ dài n
 * @param n Số chữ số còn lại cần thêm vào
 * @param prefix Chuỗi nhị phân đã tạo được đến thời điểm hiện tại
 */
void generateBinaryNumbers(int n, string prefix = "") {
    // Trường hợp cơ sở: nếu đã tạo đủ số nhị phân có độ dài yêu cầu, in nó ra
    if (n == 0) {
        cout << prefix << endl;
        return;
    }

    // Trường hợp đệ quy: thêm chữ số 0 và gọi đệ quy
    generateBinaryNumbers(n - 1, prefix + "0");

    // Trường hợp đệ quy: thêm chữ số 1 và gọi đệ quy
    generateBinaryNumbers(n - 1, prefix + "1");
}

int main() {
    int n; // Khai báo biến để lưu độ dài của số nhị phân

    // Nhận giá trị đầu vào từ bàn phím
    cout << "Nhap do dai cua so nhi phan: ";
    cin >> n;

    // Tạo và in tất cả các số nhị phân có độ dài n
    generateBinaryNumbers(n);

    return 0;
}
