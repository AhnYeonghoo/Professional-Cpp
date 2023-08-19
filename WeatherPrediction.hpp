#include <string>

class WeatherPrediction
{
public:
	// virtual �Ҹ���
	virtual ~WeatherPrediction();
	// ���� �µ��� ȭ�� ������ �����Ѵ�.
	virtual void setCurrentTempFahrenheit(int temp);
	// �񼺰� ȭ�� ������ ���� �Ÿ��� �����Ѵ�.
	virtual void setPositionOfJupiter(int distanceFromMars);
	// ���� �µ��� ���� �������� �����´�.
	virtual int getTomorrowTempFahrenheit() const;
	// ���� �� �� Ȯ���� �����´�. ���� 1�̸� Ȯ���� �� ����,
	// 0�̸� �� ���� �ʴ´ٴ� ���� �ǹ��Ѵ�.
	virtual double getChanceOfRain() const;
	// ����ڿ��� ������ ���� �������� ����� ����Ѵ�.
	// Result: x.xx chance, Temp. xx
	virtual void showResult() const;
	// ���� �µ��� ��Ʈ�������� �����Ѵ�.
	virtual std::string getTemperature() const
	{
		return "00";
	}

private:
	int m_currentTempFahrenheit{ 0 };
	int m_distanceFromMars{ 0 };
};