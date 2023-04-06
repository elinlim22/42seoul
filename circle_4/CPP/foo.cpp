#include <iostream>
// #include <string>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string &s);  // str 에 s 를 복사한다.
  int strlen();                       // 문자열 길이 리턴
};

string::string(char c, int n) {
	str = new char[n + 1];
	for (len = 0; len < n; len++) str[len] = c;
	str[len] = '\0';
};

string::string(const char *s) {
	for (len = 0; s[len] != '\0'; len++) ;
	str = new char[len + 1];
	for (int i = 0; i < len; i++) str[i] = s[i];
};

string::string(const string &s) {
	str = new char[s.len + 1];
	for (len = 0; len < s.len; len++) str[len] = s.str[len];
	str[len] = '\0';
};

string::~string() {
	if (str != NULL) delete []str;
};

void string::add_string(const string &s) {

}
