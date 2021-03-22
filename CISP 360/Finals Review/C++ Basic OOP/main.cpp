#include <iostream>
#include <cstring>
using namespace std;

class String
{
    public:
        String(const char* a);
        void print();
    private:
        char* s;
        int length;
};

String::String(const char* a) {
    length = strlen(a);
    s = new char[length];
    for(size_t i = 0; i < length; i++) {
            s[i] = a[i];
    }
}
void String::print() {
    for(size_t i = 0; i < length; i++) {
        cout << s[i];
    }
}

int main() {
    String* a = new String("Eat dick");
    a->print();
    return 0;
}