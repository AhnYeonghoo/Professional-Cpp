#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

int mainManipulator()
{
	// �οﰪ
	bool myBool{ true };
	cout << "This is the default: " << myBool << endl;
	cout << "This should be true: " << boolalpha << myBool << endl;
	cout << "This should be 1: " << noboolalpha << myBool << endl;

	// "%6d"�� ���� ȿ���� ��Ʈ���� �����ϴ� ���
	int i{ 123 };
	printf("This should be  '     123':, %6d\n", i);
	cout << "This should be '    123':  " << setw(6) << i << endl;

	// %06d�� ���� ȿ���� ��Ʈ���� �����ϴ� ���
	printf("This should be '000123': %06d\n", i);
	cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;
	
	// *�� ä���
	cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;
	// ��ĭ ä��� ���� ����
	cout << setfill(' ');

	// �ε��Ҽ�����
	double dbl { 1.452 };
	double dbl2{ 5 };
	cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;
	// ��ĭ ä��� ����
	cout << setfill(' ');

	// cout���� ���� ������ ������ �°� �����Ѵ�.
	// imbue() �޼���� locale ��ü�� 19��
	cout.imbue(locale(""));

	// ���� ������ �°� ���ڸ� ǥ���Ѵ�.
	cout << "This is 1234567 formatted according to uour location: " << 1234567 << endl;

	// ȭ�� �ݾ��� ǥ���Ѵ�. ��Ȯ�� �׼��� ���� ������ �°� ǥ���Ѵ�.
	cout << "This should be a monetary value of 120000, "
		<< "formatted according to your location: "
		<< put_money("120000") << endl;

	// ��¥�� �ð�
	time_t t_t{ time(nullptr) };
	tm* t{ localtime(&t_t) };
	cout << "This should be the current date and time "
		<< "formatted according to your location: "
		<< put_time(t, "%c") << endl;

	// �ο� ��ȣ�� ���� ��Ʈ��
	cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
		<< quoted("Quoted string with \"embedded quotes\".") << endl;
	return 0;
}