#include <string>
#include <utility>

class TextHolder
{
public:
	TextHolder(std::string text) : m_text{ std::move(text)} {}
	const std::string& getText() const { return m_text; }
	std::string&& getText() { return std::move(m_text); }
private:
	std::string m_text;
};