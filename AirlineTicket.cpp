#include "AirlineTicket.hpp"

using namespace std;

AirlineTicket::AirlineTicket()
	: m_passengerName { "Unknown Passenger"}
	, m_numberOfMiles{ 0 }
	, m_hasEliteSuperRewardsStatus {false}
{
}

AirlineTicket::~AirlineTicket()
{}

double AirlineTicket::calculatePriceInDollars()
{
	if (hasEliteSuperRewardsStatus()) {
		return 0;
	}

	return getNumberOfMiles() * 0.1;
}

std::string& AirlineTicket::getPassengerName() { return m_passengerName; }
void AirlineTicket::setPassengerName(const std::string& name) { m_passengerName = name; }

int AirlineTicket::getNumberOfMiles() { return m_numberOfMiles; }
void AirlineTicket::setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

bool AirlineTicket::hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
void AirlineTicket::sethasEliteSuperRewardsStatus(bool status)
{
	m_hasEliteSuperRewardsStatus = status;
}

int mainAirlineticket()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost{ myTicket.calculatePriceInDollars() };
	cout << format("This Ticket will cost ${}", cost) << endl;

	return 0;

}

