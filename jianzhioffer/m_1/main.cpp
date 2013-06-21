#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class CMyString {
private:
    char* m_pData;

public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator = (const CMyString &str);
};

CMyString& CMyString::operator = (const CMyString &str) {
    if (&str == this) return *this;
    int len = (int)strlen(str.m_pData);
    char *p = new char[len+1];
    delete[] m_pData;
    m_pData = NULL;
    strcpy(p, str.m_pData);
    m_pData = p;
    return *this;
}

int main()
{

    return 0;
}
