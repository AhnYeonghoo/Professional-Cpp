#include <iostream>
#include <string>
#include <vector>
#include <charconv>

using namespace std;
using namespace std::literals;
using namespace std::string_literals;
using namespace std::literals::string_literals;

int mainCppStyleString()
{
	// C Style의 string의 장점만 남기고 메모리 관련 단점을 없앤 
	// basic_string이라는 클래스 탬플릿의 인스턴스이다.
	// std안에 정의되어 있고, 이것을 사용하길 권장함.
	string a{ "12" };
	string b{ "34" };
	string c = a + b;
	cout << c << endl;
	
	// C Style String에서의 문자열 비교
	const char* ca{ "12" };
	char cb[]{ "12" };
	if (ca == cb) {
		cout << "안됨" << endl;
	}
	
	if (strcmp(ca, cb) == 0) {
		cout << "이걸로 비교해야 함" << endl;
	}
	
	// C++ Style String에서의 문자열 다루기
	
	string a2{ "12" };
	string b2{ "34" };
	
	auto result{ a2.compare(b2) };
	if (result < 0) { cout << "less" << endl; }
	if (result > 0) { cout << "greater" << endl; }
	if (result == 0) { cout << "equal" << endl; }

	string a3{ "12" };
	string b3{ "34" };
	auto result2{ a3 <=> b3 };
	if (is_lt(result2)) { cout << "less" << endl; }
	if (is_gt(result2)) { cout << "greater" << endl; }
	if (is_eq(result2)) { cout << "equal" << endl; }

	string myString{ "Hello" };
	myString += ", there";
	string myOtherString{ myString };
	if (myString == myOtherString) {
		myOtherString[0] = 'h';
	}
	cout << myString << endl;
	cout << myOtherString << endl;

	string strHello{ "Hello!!" };
	string strWorld{ "The World..." };
	auto position{ strHello.find("!!") };
	if (position != string::npos) {
		strHello.replace(position, 2, strWorld.substr(3, 6));
	}
	cout << strHello << endl;
	
	auto string1{ "Hello World" }; // string1의 타입은 const char*다.
	auto string2{ "Hello World"s }; // string2의 타입은 std::string이다.

	/*
	* vector는 CTAD를 지원한다. 
	* 그러나 스트링 리터럴 끝에 s를 붙이지 않고 타입을 추론하게 된다면
	* const char* 형으로 추론된다.
	*/
	vector names{ "John", "Sam", "Joe" }; // const char*형으로 추론됨
	vector names2{ "John"s, "Sam"s, "Joe"s }; // std::string으로 추론됨
	
	// 숫자 변환
	long double d{ 3.14L };
	string s{ to_string(d) };
	
	// 문자를 숫자로 변환
	const string toParse{ " 123USD" };
	size_t index{ 0 };
	int value{ stoi(toParse, &index) };
	cout << format("Parsed value: {}", value) << endl;
	cout << format("First non-parsed character: '{}' ", toParse[index]);
	cout << endl;

	// 로우레벨 숫자 변환
	const size_t BufferSize{ 50 };
	std::string out(BufferSize, ' '); // 버퍼사이즈 만큼의 문자로 구성된 스트림
	auto result3{ to_chars(out.data(), out.data() + out.size() , 12345) };
	if (result3.ec == errc{}) { cout << out << endl; }

	// 구조적 바인딩을 적용
	string out2(BufferSize, ' ');
	auto [ptr, error] { to_chars(out2.data(), out2.data() + out2.size(), 12345)};
	if (error == errc{}) { { cout << out << endl; } }

	cout << endl;
	double value2{ 0.314 };
	string out3{ BufferSize, ' ' };
	auto [ptr2, error2] {to_chars(out3.data(), out3.data() + out3.size(), value2)};
	if (error2 == errc{}) { cout << out3 << endl; };

	double value1{ 0.314 };
	auto [ptr1, error1]  { to_chars(out.data(), out.data() + out.size(), value1) };
	if (error1 == errc{}) { cout << out << endl; }
	
	double value3;
	auto [ptr3, error3] { from_chars(out.data(), out.data() + out.size(), value3)};
	if (error3 == errc{}) {
		if (value1 == value3) {
			cout << "Perfect roundtrip" << endl;
		}
		else {
			cout << "No Perfect roundtrip?!?" << endl;
		}
	}
	
	return 0;
}