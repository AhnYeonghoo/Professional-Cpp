#include <iostream>
#include <format>
using namespace std;

class MilesEstimator
{
public:
	virtual ~MilesEstimator() = default;
	int getMilesLeft() const { return getMilesPerGallon() * getGallonsLeft(); }
	virtual void setGallonsLeft(int gallons) { m_gallonsLeft = gallons; }
	virtual int getGallonsLeft() const { return m_gallonsLeft; }
private:
	int m_gallonsLeft{ 0 };
	virtual int getMilesPerGallon() const { return 20; }
};

class EfficientCarMilesEstimator : public MilesEstimator
{
private:
	int getMilesPerGallon() const override { return 35; }
};

class Gregarious
{
public:
	virtual void talk() { cout << "Gregarious says hi!" << endl; }
};

class Shy : public Gregarious
{
protected:
	void talk() override { cout << "Shy reluctantly says hello." << endl; }
};

class Secret
{
protected:
	virtual void dontTell() { cout << "I`ll never tell" << endl; }
};

class Blabber : public Secret
{
public:
	virtual void tell() { dontTell(); }
};

int mainMilesEstimator()
{
	MilesEstimator myMilesEstimator;
	myMilesEstimator.setGallonsLeft(2);
	cout << format("Normal estimator can go {} more miles", myMilesEstimator.getMilesLeft()) << endl;

	// 개선된 차량
	EfficientCarMilesEstimator myEstimator;
	myEstimator.setGallonsLeft(2);
	cout << format("Efficient estimator can go {} more miles", myEstimator.getMilesLeft()) << endl;

	// 접근권한 변경시 메서드 호출법
	Shy myShy;
	Gregarious& ref{ myShy };
	ref.talk();
	return 0;
}