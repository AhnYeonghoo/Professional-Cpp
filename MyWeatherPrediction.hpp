#include "WeatherPrediction.hpp"
#include <format>
#include <iostream>

class MyWeatherPrediction : public WeatherPrediction
{
public:
	virtual void setCurrentTempCelsius(int temp);
	virtual int getTomorrowTempCelsius() const;
	virtual void showResult() const override;
	virtual std::string getTemperature() const override;

private:
	static int convertCelsiusToFahrenheit(int celsius) 
	{
		return 1;
	}

	static int convertFahrenheitToCelsius(int fahrenheit) 
	{
		return 1;
	}
};