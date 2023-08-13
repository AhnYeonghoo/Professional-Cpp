#pragma once

#include <string>
#include <format>
#include <iostream>

class AirlineTicket
{
public:
	AirlineTicket();
	~AirlineTicket();
	
	double calculatePriceInDollars();
	
	std::string& getPassengerName();
	void setPassengerName(const std::string& name);

	int getNumberOfMiles();
	void setNumberOfMiles(int miles);

	bool hasEliteSuperRewardsStatus();
	void sethasEliteSuperRewardsStatus(bool status);

private:
	std::string m_passengerName;
	int m_numberOfMiles;
	bool m_hasEliteSuperRewardsStatus;
};