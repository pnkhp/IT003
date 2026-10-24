#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int M;
    cin >> M;

    vector<string> blacklist(M);

    for (int i = 0; i < M; i++) {
        cin >> blacklist[i];
    }

    int N;
    cin >> N;
    cin.ignore();

    bool found = false;

    for (int i = 1; i <= N; i++) {
        string subject;
        getline(cin, subject);

        string word = "";
        bool spam = false;

        for (int j = 0; j <= subject.length(); j++) {

            if (j == subject.length() || subject[j] == ' ') {

                for (int k = 0; k < M; k++) {
                    if (word == blacklist[k]) {
                        spam = true;
                        break;
                    }
                }

                if (spam)
                    break;

                word = "";
            }
            else {
                word += subject[j];
            }
        }

        if (spam) {
            cout << i << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "No spam found." << '\n';
    }

    return 0;
}
//Được. Mình giải thích **từng phần** theo đúng code của bạn nhé.

// ## 1\. Khai báo thư viện

// ```
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// ```

// - `iostream` → dùng `cin`, `cout`.
// - `vector` → dùng `vector<string>`.
// - `string` → dùng kiểu dữ liệu `string`.

// ---

// ## 2\. Nhập số lượng blacklist

// ```
// int M;
// cin >> M;
// ```

// `M` là số lượng từ bị cấm.

// Ví dụ:

// ```
// 2
// buy
// free
// ```

// thì:

// ```
// M = 2
// ```

// ---

// ## 3\. Lưu blacklist vào vector

// ```
// vector<string> blacklist(M);
// ```

// Tạo một `vector` có `M` phần tử.

// Sau đó:

// ```
// for (int i = 0; i < M; i++) {
//     cin >> blacklist[i];
// }
// ```

// Nếu input:

// ```
// 2
// buy
// free
// ```

// thì:

// ```
// blacklist[0] = "buy"
// blacklist[1] = "free"
// ```

// ---

// ## 4\. Nhập số email

// ```
// int N;
// cin >> N;
// cin.ignore();
// ```

// `N` là số lượng email.

// Ví dụ:

// ```
// 3
// Hello world
// buy now for free
// Good morning
// ```

// thì:

// ```
// N = 3
// ```

// ### Tại sao có `cin.ignore()`?

// Sau:

// ```
// cin >> N;
// ```

// vẫn còn ký tự xuống dòng `\n` trong bộ nhớ nhập.

// Nếu ngay sau đó dùng:

// ```
// getline(cin, subject);
// ```

// thì `getline` có thể đọc ngay ký tự `\n` đó và nhận được chuỗi rỗng.

// Vì vậy:

// ```
// cin.ignore();
// ```

// dùng để bỏ ký tự xuống dòng.

// ---

// # 5\. Biến `found`

// ```
// bool found = false;
// ```

// Biến này dùng để kiểm tra:

// > Có **ít nhất một email spam** hay chưa?

// Ban đầu:

// ```
// found = false
// ```

// Nếu tìm được email spam:

// ```
// found = true;
// ```

// ---

// # 6\. Duyệt từng email

// ```
// for (int i = 1; i <= N; i++) {
// ```

// Ta duyệt email từ `1` đến `N`.

// Tại sao bắt đầu từ `1`?

// Vì đề yêu cầu **in chỉ số email bắt đầu từ 1**.

// Ví dụ:

// ```
// 1 → email thứ nhất
// 2 → email thứ hai
// 3 → email thứ ba
// ```

// ---

// # 7\. Đọc nguyên dòng email

// ```
// string subject;
// getline(cin, subject);
// ```

// Ví dụ:

// ```
// buy now for free
// ```

// thì:

// ```
// subject = "buy now for free";
// ```

// Ta dùng `getline` vì tiêu đề email có **nhiều từ**.

// ---

// # 8\. Tạo biến `word`

// ```
// string word = "";
// bool spam = false;
// ```

// `word` dùng để lưu **từng từ** trong email.

// Ví dụ:

// ```
// buy now for free
// ```

// sẽ lần lượt lấy:

// ```
// buy
// now
// for
// free
// ```

// Còn:

// ```
// spam = false;
// ```

// dùng để kiểm tra **email hiện tại** có spam hay không.

// ---

// # 9\. Duyệt từng ký tự

// Đây là phần quan trọng nhất:

// ```
// for (int j = 0; j <= subject.length(); j++) {
// ```

// Ta duyệt từng ký tự của `subject`.

// Ví dụ:

// ```
// buy now
// ```

// thì các ký tự lần lượt là:

// ```
// b
// u
// y
// (space)
// n
// o
// w
// ```

// ---

// # 10\. Kiểm tra kết thúc một từ

// ```
// if (j == subject.length() || subject[j] == ' ') {
// ```

// Có **2 trường hợp**:

// ### Trường hợp 1: gặp khoảng trắng

// ```
// subject[j] == ' '
// ```

// Ví dụ:

// ```
// buy now
// ```

// khi gặp khoảng trắng sau `buy`, ta biết:

// ```
// word = "buy"
// ```

// Đây là lúc cần kiểm tra `buy` có nằm trong blacklist không.

// ### Trường hợp 2: đến cuối chuỗi

// ```
// j == subject.length()
// ```

// Ví dụ:

// ```
// buy now
// ```

// sau khi đọc đến `w`, không còn khoảng trắng nữa.

// Nếu không kiểm tra trường hợp này thì từ cuối cùng `now` sẽ **không được kiểm tra**.

// Đây là lý do có:

// ```
// j <= subject.length()
// ```

// thay vì chỉ:

// ```
// j < subject.length()
// ```

// ---

// # 11\. Kiểm tra từ có nằm trong blacklist không

// ```
// for (int k = 0; k < M; k++) {
//     if (word == blacklist[k]) {
//         spam = true;
//         break;
//     }
// }
// ```

// Ví dụ:

// ```
// blacklist:
// buy
// free
// ```

// và email:

// ```
// buy now for free
// ```

// Khi:

// ```
// word = "buy";
// ```

// ta kiểm tra:

// ```
// word == blacklist[0]
// ```

// tức là:

// ```
// "buy" == "buy"
// ```

// → đúng.

// Vậy:

// ```
// spam = true;
// ```

// Email này là spam.

// ---

// # 12\. `break` đầu tiên

// ```
// break;
// ```

// ở đây thoát khỏi vòng:

// ```
// for (int k = 0; k < M; k++)
// ```

// Tức là:

// > Đã tìm thấy từ blacklist rồi, không cần kiểm tra các từ blacklist còn lại.

// ---

// # 13\. `if (spam) break`

// ```
// if (spam)
//     break;
// ```

// Cái này nằm trong vòng duyệt các ký tự của email.

// Nếu đã phát hiện email spam thì:

// > Không cần kiểm tra các từ còn lại trong email nữa.

// Ví dụ:

// ```
// buy now for free
// ```

// `buy` đã là từ blacklist → biết chắc email spam → dừng luôn.

// ---

// # 14\. Reset `word`

// ```
// word = "";
// ```

// Nếu từ hiện tại không phải spam, ta xóa `word` để bắt đầu lấy từ tiếp theo.

// Ví dụ:

// ```
// Hello world
// ```

// Đọc:

// ```
// Hello
// ```

// gặp khoảng trắng → kiểm tra xong →

// ```
// word = "";
// ```

// Sau đó đọc tiếp:

// ```
// world
// ```

// ---

// # 15\. Nếu email là spam

// Sau khi kiểm tra xong:

// ```
// if (spam) {
//     cout << i << '\n';
//     found = true;
// }
// ```

// Nếu `spam == true`:

// - In số thứ tự email.
// - Đặt `found = true`.

// Ví dụ email thứ 2:

// ```
// 2
// ```

// được in ra.

// ---

// # 16\. Nếu không có email spam

// Sau khi kiểm tra toàn bộ email:

// ```
// if (!found) {
//     cout << "No spam found." << '\n';
// }
// ```

// `!found` nghĩa là:

// ```
// found == false
// ```

// Tức là không có email nào spam.

// ---

// ## Chạy thử

// Input:

// ```
// 2
// buy
// free
// 3
// Hello world
// buy now for free
// Good morning
// ```

// ### Email 1

// ```
// Hello world
// ```

// - `Hello` → không có trong blacklist.
// - `world` → không có.
// - `spam = false`.

// Không in gì.

// ### Email 2

// ```
// buy now for free
// ```

// - `buy` → có trong blacklist.
// - `spam = true`.
// - In:

// ```
// 2
// ```

// ### Email 3

// ```
// Good morning
// ```

// - `Good` → không có.
// - `morning` → không có.

// Không in.

// Cuối cùng:

// ```
// found = true
// ```

// nên không in `No spam found.`.

// ### Kết quả

// ```
// 2
// ```

// ---

// ### Tóm tắt luồng chương trình

// ```
// Đọc blacklist
//        ↓
// Đọc từng email
//        ↓
// Tách email thành từng từ
//        ↓
// Mỗi từ → tìm trong blacklist
//        ↓
// Có từ trùng?
//    ↙          ↘
//  Có            Không
//  ↓              ↓
// Spam          kiểm tra tiếp
//  ↓
// In vị trí
// ```

// Điểm quan trọng nhất trong bài này là **tự tách từng từ bằng cách duyệt ký tự**, nên bạn không cần dùng `sstream`.