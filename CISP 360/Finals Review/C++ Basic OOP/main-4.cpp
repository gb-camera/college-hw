#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        char* s;
        int length;
    public:
        String(const char*);
        void print();
};

String::String(const char* cstr) {
    length = strlen(cstr);
    s = new char[length];
    for(int i = 0; i < length; i++)
    {
        s[i] = cstr[i];
    }
}

void String::print() {
    for(int i = 0; i < length; i++) cout << s[i];
}

int main() {
    String* str = new String("Hello World!");
    str->print();
    cout << endl;
    return 0;
}
