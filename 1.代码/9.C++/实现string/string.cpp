/*************************************************************************
	> File Name: string.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月30日 星期四 12时42分51秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

namespace haizei {

class istream {
public:
    istream &operator>>(string &s) {
        std::cin >> s;
        return *this;
    }
private:

};
class ostream {
public: 
    ostream &operator<<(string &s) {
        std::cout << s;
        return *this;
    }
private:
};

class string {
public:
    string operator+(string &s) {
        strcat(my_data, s.my_data);
        return *this;
        //cout << this << endl;
    }

    string operator+=(string &s) {
        my_data = new char[sizeof(my_data) + 1];
        strcat(my_data, s.my_data);
        return *this;
    }

    char operator[](int index) {
        return my_data[index];
    }

    bool operator==(string &s){
        if(this->my_len != s.my_len) return 0;
        else {
            for(int i = 0; i < my_len; i++) {
                if(this->my_data[i] != s.my_data[i]) {
                    return 0;
                }
                return 1;
            }
        }
    }
    bool operator!=(string &s) {
        if(strcmp(my_data, s.my_data) != 0) {
            return 1;
        }else {
            return 0;
        }
    }
    
    bool operator>(string &s) {
        if(strcmp(this->my_data, s.my_data) > 0) {
            return 1;
        }else {
            return 0;
        }
    }
    bool operator<(string &s) {
        if(strcmp(this->my_data, s.my_data) < 0) {
            return 1;
        }else {
            return 0;
        }
    }
private:
    int my_len;
    char *my_data;
};
istream cin;
ostream cout;
int my_len;
char *my_data;
};

int main() {
    string n, m;
    haizei::cin >> n >> m;
    haizei::cout << n << m;
    cout << endl;
    if(n == m) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if(n > m) {
        cout << "n > m" << endl;
    } else {
        cout << "n < m" << endl;
    }
    if(n < m) {
        cout << "n < m" << endl;
    } else {
        cout << "n > m" << endl;
    }
    string c = n + m;
    cout << c << endl;
    n += m;
    haizei::cout << n;
    cout << endl;
    cout << n[0];
    return 0;
}
