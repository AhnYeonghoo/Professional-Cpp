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
	// C Style�� string�� ������ ����� �޸� ���� ������ ���� 
	// basic_string�̶�� Ŭ���� ���ø��� �ν��Ͻ��̴�.
	// std�ȿ� ���ǵǾ� �ְ�, �̰��� ����ϱ� ������.
	string a{ "12" };
	string b{ "34" };
	string c = a + b;
	cout << c << endl;
	
	// C Style String������ ���ڿ� ��
	const char* ca{ "12" };
	char cb[]{ "12" };
	if (ca == cb) {
		cout << "�ȵ�" << endl;
	}
	
	if (strcmp(ca, cb) == 0) {
		cout << "�̰ɷ� ���ؾ� ��" << endl;
	}
	
	// C++ Style String������ ���ڿ� �ٷ��
	
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
	
	auto string1{ "Hello World" }; // string1�� Ÿ���� const char*��.
	auto string2{ "Hello World"s }; // string2�� Ÿ���� std::string�̴�.

	/*
	* vector�� CTAD�� �����Ѵ�. 
	* �׷��� ��Ʈ�� ���ͷ� ���� s�� ������ �ʰ� Ÿ���� �߷��ϰ� �ȴٸ�
	* const char* ������ �߷еȴ�.
	*/
	vector names{ "John", "Sam", "Joe" }; // const char*������ �߷е�
	vector names2{ "John"s, "Sam"s, "Joe"s }; // std::string���� �߷е�
	
	// ���� ��ȯ
	long double d{ 3.14L };
	string s{ to_string(d) };
	
	// ���ڸ� ���ڷ� ��ȯ
	const string toParse{ " 123USD" };
	size_t index{ 0 };
	int value{ stoi(toParse, &index) };
	cout << format("Parsed value: {}", value) << endl;
	cout << format("First non-parsed character: '{}' ", toParse[index]);
	cout << endl;

	// �ο췹�� ���� ��ȯ
	const size_t BufferSize{ 50 };
	std::string out(BufferSize, ' '); // ���ۻ����� ��ŭ�� ���ڷ� ������ ��Ʈ��
	auto result3{ to_chars(out.data(), out.data() + out.size() , 12345) };
	if (result3.ec == errc{}) { cout << out << endl; }

	// ������ ���ε��� ����
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