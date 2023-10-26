#include "String.h"

String::String(const String &str) {
    int size = strlen(str.m_data);
    this->m_data = new char[size + 1];  // +1是为了结尾的\0
    strcpy(this->m_data, str.m_data);
}

String::String(const char *ch) {
    if (ch == 0) {
        this->m_data = new char[1];
        strcpy(this->m_data, "\0");
    } else {
        int size = strlen(ch);
        this->m_data = new char[size + 1];
        strcpy(this->m_data, ch);
    }
}

String::~String() {
    delete[] m_data;
}

String &String::operator=(const String &str) {
    if (this == &str)
        return *this;
    delete[] this->m_data;
    int size = strlen(str.m_data);
    this->m_data = new char[size + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
}