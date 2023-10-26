// 读字符串 char buf[100] =“xxxx:yyyy:zzzz:aaaa:bbb”.按:进行分解到，string 数组中去。

#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    char buf[100] = "xxxx:yyyy:zzzz:aaaa:bbb";
    int firstIndex = 0;
    int lastIndex;
    vector<string> words;
    for (int i = 0; i < strlen(buf); i++) {
        char temp = buf[i];
        if (to_string(temp).empty())
            break;
        else {
            if (temp == ':') {
                lastIndex = i;
                words.emplace_back((buf + firstIndex, buf + lastIndex));
                firstIndex = lastIndex + 1;
            }
        }
    }
    for (const auto& current: words)
        std::cout << current << std::endl;
}