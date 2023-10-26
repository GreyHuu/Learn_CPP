#ifndef C_STRING_H
#define C_STRING_H

#include <cstring>

class String {
public:
    String(const char *ch = 0);

    String(const String &str);

    ~String();

    String &operator=(const String &str);

    char *get_c_str() const { return m_data; }


private:
    char *m_data;
};


#endif //C_STRING_H
