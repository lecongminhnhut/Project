#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cctype>
#include <vector>
using namespace std;
// Đảo ngược chuỗi
void reverse(int a[], int n)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}
// Cộng 2 số nguyên lớn
string Addition(string a, string b)
{
    string result = "";// tạo chuỗi kết quả rỗng
    int n1 = a.size();
    int n2 = b.size();
    int n = 0;
    // TH a nhiều chữ số hơn
    if (n1 > n2)
    {
        int x[n1];
        int y[n1];
        int z[n1+1];
        // Duyệt 2 chuỗi string thành mảng số nguyên với mỗi phần tử của mảng là 1 chữ số của số nguyên lớn
        for (int i = 0; i < n1; i++)
        {
            x[i] = a[i] - '0';
        }
        for (int i = 0; i < n2; i++)
        {
            y[i] = b[i] - '0';
        }
        // Đảo ngược mảng để thuận tiện cộng
        reverse(x, n1);
        reverse(y, n2);
        for (int i = n2; i < n1; i++)
        {
            y[i] = 0;
        }
        int nho = 0;
        // cộng từng chữ số
        for (int i = 0; i < n1; i++)
        {
            int temp = x[i] + y[i] + nho;
            z[n++] = temp % 10;
            nho = temp / 10;
        }
        // TH cộng ra số mới có thêm 1 chữ số nữa
        if (nho) z[n++] = nho;
        //chuyển về kiểu string
        for (int i = n-1; i >= 0; i--)
        {
            result += (z[i] + '0');
        }
    }
    // TH b có nhiều chữ số hơn
    else
    {
        int x[n2];
        int y[n2];
        int z[n2+1];
        for (int i = 0; i < n1; i++)
        {
            x[i] = a[i] - '0';
        }
        for (int i = 0; i < n2; i++)
        {
            y[i] = b[i] - '0';
        }
        reverse(x, n1);
        reverse(y, n2);
        for (int i = n1; i < n2; i++)
        {
            x[i] = 0;
        }
        int nho = 0;
        for (int i = 0; i < n2; i++)
        {
            int temp = x[i] + y[i] + nho;
            z[n++] = temp % 10;
            nho = temp / 10;
        }
        if (nho) z[n++] = nho; 
        for (int i = n-1; i >= 0; i--)
        {
            result += (z[i] + '0');
        }
    }
    return result;
}
// hàm so sánh 2 số bằng số chữ số
bool Sosanh(int a[], int b[], int n)
{
    for (int i = 0 ;  i < n; i++)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}
// Trừ 2 số nguyên lớn
string Subtraction(string a, string b)
{
    // Xử lý các trường hợp đặc biệt
    // VD: -2 - 2
    if (a[0] == '-' && b[0] != '-') 
    {
        a = a.substr(1);
        return '-' + Addition(a,b);
    }
    // VD: -2 - -2
    if (a[0] == '-' && b[0] == '-')
    {   
        a = a.substr(1);
        b = b.substr(1);
        return Subtraction(b,a);
    }
    // VD: 2 - -2
    if (a[0] != '-' && b[0] == '-') 
    {
        b = b.substr(1);
        return Addition(a,b);
    }
    string result = "";
    int n1 = a.size();
    int n2 = b.size();
    int n = 0;
    if (n1 > n2)
    {
        int x[n1];
        int y[n1];
        int z[n1+1];
        for (int i = 0; i < n1; i++)
        {
            x[i] = a[i] - '0';
        }
        for (int i = 0; i < n2; i++)
        {
            y[i] = b[i] - '0';
        }
        reverse(x, n1);
        reverse(y, n2);
        for (int i = n2; i < n1; i++)
        {
            y[i] = 0;
        }
        int nho = 0;
        for (int i = 0; i < n1; i++)
        {
            int temp = x[i] - (y[i] + nho);
            if (temp >= 0)
            {
                z[n++] = temp;
                nho = 0;
            }
            else 
            {
                z[n++] = 10 + temp;
                nho = 1;
            }
        }
        // loại 0 ở đầu kết quả
        int thu = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (thu == 0 && z[i])
            {
                thu = 1;
            }
            if (thu)
            {
            result += (z[i] + '0');
            }
        }
        if (thu == 0) result += '0';
    }
    else if (n2 > n1)
    {
        int x[n2];
        int y[n2];
        int z[n2+1];
        for (int i = 0; i < n1; i++)
        {
            x[i] = a[i] - '0';
        }
        for (int i = 0; i < n2; i++)
        {
            y[i] = b[i] - '0';
        }
        reverse(x, n1);
        reverse(y, n2);
        for (int i = n1; i < n2; i++)
        {
            x[i] = 0;
        }
        int nho = 0;
        for (int i = 0; i < n2; i++)
        {
            int temp = y[i] - (x[i] + nho);
            if (temp >= 0)
            {
                z[n++] = temp;
                nho = 0;
            }
            else 
            {
                z[n++] = 10 + temp;
                nho = 1;
            }
        }
        // thêm dấu trừ vì số bé trừ số lớn
        result += '-';
        int thu = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (thu == 0 && z[i])
            {
                thu = 1;
            }
            if (thu)
            {
            result += (z[i] + '0');
            }
        }
        if (thu == 0) result += '0';
    }
    else
    {
        int x[n1];
        int y[n1];
        int z[n1];
        for (int i = 0; i < n1; i++)
        {
            x[i] = a[i] - '0';
            y[i] = b[i] - '0';
        }
        if (Sosanh(x, y, n1))
        {
        reverse(x, n1);
        reverse(y, n2);
        int nho = 0;
        for (int i = 0; i < n1; i++)
        {
            int temp = x[i] - (y[i] + nho);
            if (temp >= 0)
            {
                z[n++] = temp;
                nho = 0;
            }
            else 
            {
                z[n++] = 10 + temp;
                nho = 1;
            }
        }
        int thu = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (thu == 0 && z[i])
            {
                thu = 1;
            }
            if (thu)
            {
                result += (z[i] + '0');
            }
        }
            if (thu == 0) result += '0';
        }
        else
        {
            reverse(x, n1);
            reverse(y, n2);
            int nho = 0;
            for (int i = 0; i < n1; i++)
            {
                int temp = y[i] - (x[i] + nho);
                if (temp >= 0)
                {
                    z[n++] = temp;
                    nho = 0;
                }
                else 
                {
                    z[n++] = 10 + temp;
                    nho = 1;
                }
            }
            // thêm dấu trừ vì số bé trừ số lớn
            result += '-';
            int thu = 0;
            for (int i = n-1; i >= 0; i--)
            {
                if (thu == 0 && z[i])
                {
                    thu = 1;
                }
                if (thu)
                {
                    result += (z[i] + '0');
                }
            }
        }
    }
    return result;
}
string Mul_1_Digit (string a, int x)
{
    int n = a.size();
    int arr[n];
    int res[n+1] = {0};
    int n_res = 0;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i] - '0';
    }
    reverse(arr,n);
    int nho = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = x * arr[i] + nho;
        res[n_res++] = temp % 10;
        nho = temp / 10;
    }
    if (nho > 0) {
        res[n_res++] = nho;
    }
    // Bỏ các số 0 vô nghĩa ở đầu
    while (n_res > 1 && res[n_res-1] == 0) {
        n_res--;
    }

    for (int i = n_res-1; i >= 0; i--) {
        result += (res[i] + '0');
    }
    return result;
}
string Multiplication(string a, string b)
{
    //Xử lý dấu
    int dem_dau = 0;
    if (a[0] == '-')
    {
        dem_dau++;
        a = a.substr(1);
    }
    if (b[0] == '-')
    {
        dem_dau++;
        b = b.substr(1);
    }
    int n1 = a.size();
    int x[n1];
    string result ="0";
    for (int i = 0; i < n1; i++)
    {
        x[i] = a[i] - '0';
    }
    reverse(x, n1);
    int chuso = 0;
    for (int i = 0; i < n1; i++)
    {
        string temp = Mul_1_Digit(b, x[i]);//nhân từng chữ số của a cho b
        for (int j = 0; j < chuso; j++)
        {
            temp += '0'; //thêm 0 phía sau cho từng hàng ...,nghìn, trăm, chục,...
        }
        chuso++;
        result = Addition(result, temp);// Cộng kết quả lại
    }
    // Xử lý số 0 ở đầu
    int n = result.size() - 1;
    int zero = 0;
    while (zero <= n && result[zero] == '0')
    {
        zero++;
    }
    result = result.substr(zero);
    // Xử lý dấu
    if (dem_dau % 2 != 0 && result != "0") result = '-' + result;
    if (result == "") result = "0";
    return result;
}
// Hàm kiểu tra bằng 0
bool test_zero (string a)
{
    // Xử lý dấu
    if (a[0] == '-') a = a.substr(1);
    int n = a.size();
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        
        if (a[i] == '0') zero++;
    }
    if (zero == n)//tất cả phần tử chuỗi bằng 0
        return true;
    return false;
}
// Hàm so sánh hai chuỗi số nguyên lớn
bool isSmaller(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
string Division(string a, string b)
{
    // Lỗi chia 0
    if (test_zero(b)) 
    {
        return "ERROR";
    }
    // Xử lý dấu
    int dau = 0;
    if (a[0] == '-')
    {
        dau++;
        a = a.substr(1);
    }
    if (b[0] == '-')
    {
        dau++;
        b = b.substr(1);
    }
// xử lý 0 ở đầu hai chuỗi
    unsigned int  pos_a = 0;
    unsigned int pos_b = 0;
    while (pos_a < a.size() - 1 && a[pos_a] == '0') pos_a++;
    a = a.substr(pos_a);
    while (pos_b < b.size() - 1 && b[pos_b] == '0') pos_b++;
    b = b.substr(pos_b);
// a < b thì trả về 0
    if (isSmaller(a, b)) return "0";
    string result = "";
    string current = "";
    
    for (unsigned int i = 0; i < a.size(); i++) {
        current += a[i];
        // Loại bỏ 0 đầu
        unsigned int pos = 0;
        while (pos < current.size() - 1 && current[pos] == '0') pos++;
        current = current.substr(pos);
        int count = 0; // biến đếm số lần đã trừ
        while (!isSmaller(current, b)) 
            {
                current = Subtraction(current, b);
                count++;
            }
            result += (count + '0');
        }

    // Loại bỏ 0 đầu của kết quả
    unsigned int pos = 0;
    while (pos < result.size() - 1 && result[pos] == '0') pos++;
    result = result.substr(pos);
    // Xử lý dấu
    if (dau % 2 != 0) result = '-' + result;
    return result; 
}

// Hàm ưu tiên toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 10;
    return 0;
}

// Hàm thực hiện phép toán với 2 toán hạng dạng string
string applyOp(const string& a, const string& b, char op) {
    if (op == '+') return Addition(a, b);
    else if (op == '-') return Subtraction(a, b);
    else if (op == '*') return Multiplication(a, b);
    else if (op == '/') return Division(a, b);
    return "ERROR";
}

// Loại bỏ dấu ngoặc và khoảng trắng, chuẩn hóa
string removeOuterSpaces(const string &s) {
    string res = "";
    for (unsigned int i = 0; i < s.size(); i++) {
        if (!isspace(s[i])) {
            res += s[i];
        }
    }
    return res;
}


string parseNumber(const string& a, unsigned int& pos) {
    string num;

    if (a[pos] == '(') {
        pos++; // bỏ '('
        if (a[pos] == '-') {
            num += '-';
            pos++;
        }
        while (pos < a.size() && isdigit(a[pos])) {
            num += a[pos++];
        }
        if (a[pos] == ')') pos++; // bỏ ')'
    }
    else {
        if (a[pos] == '-') {
            num += '-';
            pos++;
        }
        while (pos < a.size() && isdigit(a[pos])) {
            num += a[pos++];
        }
    }
    return num;
}

// Chuyển biểu thức trung tố sang hậu tố (shunting-yard algorithm)
vector<string> infix_Postfix(const string& a) {
    vector<string> output;
    stack<char> ops;
    unsigned int  i = 0;
    while (i < a.size()) {
        if (isdigit(a[i]) || (a[i] == '-' && (i == 0 || a[i-1] == '(' || precedence(a[i-1])))) {
            string num = parseNumber(a, i);
            output.push_back(num);
        }
        else if (a[i] == '(') {
            ops.push(a[i++]);
        }
        else if (a[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); // pop '('
            i++;
        }
        else if (strchr("+-*/", a[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(a[i])) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(a[i++]);
        }
        else {
            i++; // bỏ qua ký tự không hợp lệ
        }
    }
    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }
    return output;
}

// Hàm tính giá trị của biểu thức hậu tố
string XuLy_Postfix(vector<string> postfix) {
    stack<string> st;
    for (unsigned int i = 0; i < postfix.size(); i++) {
        string token = postfix[i];
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) return "ERROR";
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string res = applyOp(a, b, token[0]);
            if (res == "ERROR") return "ERROR";
            st.push(res);
        } else {
            st.push(token);
        }
    }
    if (st.size() != 1) return "ERROR";
    return st.top();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " input_file output_file\n";
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if (!fin) {
        cerr << "Không thể mở file đầu vào.\n";
        return 1;
    }
    if (!fout) {
        cerr << "Không thể mở file đầu ra.\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        string a = removeOuterSpaces(line);
        vector<string> b = infix_Postfix(a);
        string result = XuLy_Postfix(b);
        cout << result << endl;
        fout << result << endl;
    }

    fin.close();
    fout.close();
    return 0;
}