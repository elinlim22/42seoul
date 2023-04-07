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
  void print_string();
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
	std::cout << "~ deleted " << str << std::endl;
	if (str != NULL) delete []str;
};

void string::add_string(const string &s) {
	char *str_n = new char[len + s.len + 1];
	int i = 0;
	for (; i < len; i++) str_n[i] = str[i];
	for (; i < len + s.len; i++) str_n[i] = s.str[i - len];
	str_n[i] = '\0';
	delete []str;
	str = str_n;
	len += s.len;
};

void string::copy_string(const string &s) {
	char *str_n = new char[s.len + 1];
	for (int i = 0; i < s.len; i++) str_n[i] = s.str[i];
	str_n[s.len] = '\0';
	len = s.len;
	delete []str;
	str = str_n;
}

int string::strlen() {
	return len;
};

void string::print_string() {
	std::cout << str << std::endl;
}

int main() {
	const char *s = "Hello World";
	string str(s);
	string nww('!', 4);

	std::cout << "add_string : ";
	str.add_string(nww);
	str.print_string();

	std::cout << "copy_string : ";
	str.copy_string(nww);
	str.print_string();

	std::cout << "strlen : " << str.strlen() << std::endl;

	string gen('A', 5);
	string cpy(gen);

	gen.print_string();
	cpy.print_string();

	return 0;
}
