#include "MyWeatherPrediction.hpp"
using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
	int fahrenheitTemp{ convertCelsiusToFahrenheit(temp) };
	setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp{ getTomorrowTempFahrenheit() };
	return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
	cout << format("Tomorrow will be {} degrees Celsius ({} degrees Fahrenheit)",
		getTomorrowTempCelsius(), getTomorrowTempFahrenheit()) << endl;
	cout << format("Chance of rain is {}%", getChanceOfRain() * 100) << endl;
	if (getChanceOfRain() > 0.5) { cout << "Bring an umbrella!" << endl; }
}

string MyWeatherPrediction::getTemperature() const
{
	// 혹은 __super::getTemperature()도 가능
	return __super::getTemperature() + "\u00B0F";
}





