#include <iostream>
using namespace std;

// Kích thước tối đa của ma trận
const int MAX_M = 100;
const int MAX_N = 100;

int main() {
    int m, n;
    cin >> m >> n;

    int a[MAX_M][MAX_N];

    // Đọc ma trận từ đầu vào
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    // Tổng lớn nhất và vị trí hình chữ nhật tương ứng
    int maxSum = a[0][0];
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    // Duyệt qua tất cả các cặp hàng bắt đầu từ hàng i đến hàng j
    for (int top = 0; top < m; ++top) {
        // Mảng lưu tổng theo cột cho các hàng từ top đến bottom
        int temp[MAX_N] = {0};

        for (int bottom = top; bottom < m; ++bottom) {
            // Cập nhật tổng theo cột
            for (int col = 0; col < n; ++col)
                temp[col] += a[bottom][col];

            // Áp dụng Kadane 1 chiều cho mảng temp
            int sum = temp[0];
            int maxSubSum = temp[0];
            int startCol = 0, tempStart = 0;
            int endCol = 0;

            for (int col = 1; col < n; ++col) {
                if (sum < 0) {
                    sum = temp[col];
                    tempStart = col;
                } else {
                    sum += temp[col];
                }

                if (sum > maxSubSum) {
                    maxSubSum = sum;
                    startCol = tempStart;
                    endCol = col;
                }
            }

            // Cập nhật nếu tìm được hình chữ nhật có tổng lớn hơn
            if (maxSubSum > maxSum) {
                maxSum = maxSubSum;
                r1 = top;
                c1 = startCol;
                r2 = bottom;
                c2 = endCol;
            }
        }
    }

    // Ghi kết quả ra màn hình (hoặc bạn có thể thay bằng ghi file)
    // Đổi từ chỉ số 0-based sang 1-based như yêu cầu
    cout << (r1 + 1) << " " << (c1 + 1) << " " << (r2 + 1) << " " << (c2 + 1) << " " << maxSum << endl;

    return 0;
}
