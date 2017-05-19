#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
  char *ptr;
public:
  String();
  String(char *s);
  String(const String &src);
  ~String();

  String& operator=(const String &src) {cpy(src.ptr); return *this; }

  String& operator=(char *s) {cpy(s); return *this; }

  String operator+(char *);
  operator char*() {return ptr;}
  int operator==(const String &other);

  void cat(char *s);
  void cpy(char *s);
};

int main() {
    String a, b, c;
    a = "I ";
    b = "am ";
    c = "so ";
    String d = a + b + c + "verry happy!\n";
    cout << d;
    return 0;
}

// ----------------
// STRING CLASS FUNCTIONS

String::String() {
    ptr = new char[1];
    ptr[0] = '\0';
}

String::String(char *s) {
    int n = strlen(s);
    ptr = new char[n + 1];
    strcpy(ptr, s);
}

String::String(const String &src) {
    int n = strlen(src.ptr);
    ptr = new char[n + 1];
    strcpy(ptr, src.ptr);
}

String::~String() {
    delete[] ptr;
}

int String::operator==(const String &other) {
    return (strcmp(ptr, other.ptr) == 0);
}

String String::operator+(char *s) {
    String new_str(ptr);
    new_str.cat(s);
    return new_str;
}

// cpy -- Copy string function
//
void String::cpy(char *s) {
    delete[] ptr;
    int n = strlen(s);
    ptr = new char[n + 1];
    strcpy(ptr, s);
}

// cat -- concatenate string function
//
void String::cat(char *s) {

    // Allocate sufficient room for new string data.

    int n = strlen(ptr) + strlen(s);
    char *p1 = new char[n + 1];

    // Copy data to this new memory block.

    strcpy(p1, ptr);
    strcat(p1, s);

    // Release old memory block and update ptr

    delete[] ptr;
    ptr = p1;
}