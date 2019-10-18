#include <iostream>
#include <cstring>
using namespace std;


class CString {
private:
    char* m_pdata;
public:
    CString(const char* ptr = nullptr) {
        if (ptr == nullptr)  m_pdata = nullptr;
        m_pdata = new char[strlen(ptr) + 1];
        strcpy(m_pdata, ptr);
    }
    CString(const CString& a) {
        if (a.m_pdata == nullptr) this->m_pdata = nullptr;
        this->m_pdata = new char[strlen(a.m_pdata) + 1];
        strcpy(this->m_pdata, a.m_pdata);
    }

    CString(CString&& a){
        this->m_pdata = a.m_pdata;
        a.m_pdata = nullptr;
    }

    ~CString() {
        if (this->m_pdata){
             delete[] this->m_pdata;
        }
    }

    CString& operator=(const CString& a) {
        if (this == &a)
            return *this;

        if (this->m_pdata)
            delete[] this->m_pdata;
        this->m_pdata = new char[strlen(a.m_pdata) + 1];
        strcpy(this->m_pdata, a.m_pdata);
        return *this;
    }

    CString operator+=(const CString& a) {
        if (a.m_pdata == nullptr) {
            return *this;
        } else if (this->m_pdata == nullptr) {
            return a;
        } else {
            char* tmp = this->m_pdata;
            this->m_pdata = new char[strlen(this->m_pdata) + strlen(a.m_pdata)
                    + 1];
            strcpy(this->m_pdata, tmp);
            strcat(this->m_pdata, a.m_pdata);
            delete[] tmp;
            return *this;
        }
    }

    friend CString operator+(const CString& a, const CString& b) {
        char* res = new char[strlen(a.m_pdata) + strlen(b.m_pdata) + 1];
        strcpy(res, a.m_pdata);
        strcat(res, b.m_pdata);
        CString cs(res);
        delete[] res;
        return cs;
    }

    friend ostream& operator<<(ostream& os, const CString& a) {
        os << a.m_pdata;
        return os;
    }
};

int main() {

    CString a("abc");
    CString b(a);
    a = b;
    a += b;
    CString c = a + b;
    std::cout << c << std::endl;
    std::cout << a << std::endl;

    return 0;
}