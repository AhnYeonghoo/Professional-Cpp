#include <string>
#include <iostream>
#include <string_view>

using namespace std;


string_view extractExtension(string_view filename)
{
	return filename.substr(filename.rfind('.'));
}

class KeyValue
{
public:
	KeyValue(string_view key, int value) : m_key{key}, m_value{value}{}
	const string& getKey() const { return m_key; }
	int getValue() const { return m_value; }
private:
	int m_value;
	string m_key;
};

template<>
class formatter<KeyValue>
{
public:
	constexpr auto parse(auto& context)
	{
		auto iter{ context.begin() };
		const auto end{ context.end() };
		if (iter == end || *iter == '}') {
			m_outputType = OutputType::KeyAndValue;
			return iter;
		}
		
		switch (*iter) {
		case 'a':
			m_outputType = OutputType::KeyOnly;
			break;
		case 'b':
			m_outputType = OutputType::ValueOnly;
			break;
		case 'c':
			m_outputType = OutputType::KeyAndValue;
			break;
		default:
			throw format_error{ "Invalid KeyValue format specifier" };
		}
		return iter;
	}
	
	auto format(const KeyValue& kv, auto& context)
	{
		switch (m_outputType) {
			using enum OutputType;
			
		case KeyOnly:
			return format_to(context.out(), "{}", kv.getKey());
		case ValueOnly:
			return format_to(context.out(), "{}", kv.getValue());
		default:
			return format_to(context.out(), "{} - {}", kv.getKey(), kv.getValue());
		}
	}

private:
	enum class OutputType
	{
		KeyOnly,
		ValueOnly,
		KeyAndValue
	};
	OutputType m_outputType{ OutputType::KeyAndValue };
};

int mainStringView()
{
	string filename{ R"(C:/temp/my_file.ext)" };
	cout << format("C++ string: {}", extractExtension(filename)) << endl;
	
	const char* cString{ R"(C:/temp/my_file.ext)" };
	cout << format("C string: {}", extractExtension(filename)) << endl;
	
	cout << format("Literal: {}", extractExtension(R"(C:/temp/my_file.ext)")) << endl;

	// string과 string_view는 서로 결합할 수 없다.
	string str{ "Hello" };
	string_view sv{ " World" };
	auto result{ str + sv.data() }; // 이런식으로 data()로 추출

	// 혹은 append 사용
	auto result2{ str };
	result2.append(sv.data(), sv.size());
	cout << result2 << endl;
	cout << result << endl;

	// string_view Literal
	auto stringL{ "My String_view"sv };

	// format은 C의 printf와 C++의 I/O 스트림의 장점을 모두 합친 것이다.
	int n = 5;
	auto s1{ format("Read {} bytes from {}", n, "file1.txt") };
	auto s2{ format("Read {0} bytes from {1}", n, "file2.txt") };

	// 포맷 지정자
	int i{ 42 };
	cout << format("|{:5}|", i) << endl;
	cout << format("|{:{}}|", i, 7) << endl;
	cout << format("|{:7}|", i) << endl;
	cout << format("|{:<7}|", i) << endl;
	cout << format("|{:_>7}|", i) << endl;
	cout << format("|{:_^7}|", i) << endl;

	double d{ 3.1415 / 2.3 };
	cout << format("|{:12g}|", d) << endl;
	cout << format("|{:12.2}|", d) << endl;
	cout << format("|{:12e}|", d) << endl;

	int width{ 12 };
	int precision{ 3 };
	cout << format("|{2:{0}.{1}f}|", width, precision, d) << endl;

	cout << format("|{:06d}|", i) << endl;
	cout << format("|{:+06d}|", i) << endl;
	cout << format("|{:06X}|", i) << endl;
	cout << format("|{:#06X}|", i) << endl;

	// 에러 처리
	try {
		cout << format("An Integer: {:.}", 5);
	}
	catch (const format_error& caught_exception) {
		cout << caught_exception.what() << endl;
	}

	// 포매터 테스트
	KeyValue keyValue{ "Key1", 11 };
	cout << format("{}", keyValue) << endl;
	cout << format("{:a}", keyValue) << endl;
	cout << format("{:b}", keyValue) << endl;
	cout << format("{:c}", keyValue) << endl;
	try { cout << format("{:cd}", keyValue) << endl; }
	catch (const format_error& caught_exception) { cout << caught_exception.what() << endl; }
	
	return 0;

}


