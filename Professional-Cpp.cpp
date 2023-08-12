// Professional-Cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <format>
#include <cstddef>
#include <limits>

using namespace std;

namespace MyLibraries::Networking::FTP {} // C++20부터 지원하는 중첩 네임스페이스

int mainMain()
{
    
    namespace MyFTP = MyLibraries::Networking::FTP; // 간결하게 사용하기
    int uninitializedInt;
    int initializedInt{ 7 }; // Uniform Initialization을 권장한다.
    cout << format("{} is a random value.", uninitializedInt) << endl;
    cout << format("{} was assigned an initial value.", initializedInt) << endl;

    std::byte b{ 42 };

    cout << "int:\n";
    cout << format("Max int value: {}\n", numeric_limits<int>::max());
    cout << format("Min int value: {}\n", numeric_limits<int>::min());
    cout << format("Lowest int value: {}\n", numeric_limits<int>::lowest());

    cout << "double:\n";
    cout << format("Max double value: {}\n", numeric_limits<double>::max());
    cout << format("Min double value: {}\n", numeric_limits<double>::min());
    cout << format("Lowest double value: {}\n", numeric_limits<double>::lowest());

    float myFloat{}; // 영 초기화
    int myInt{};
    myFloat = 3.14f;
    
    int i1{ (int)myFloat }; // C 스타일 캐스팅
    int i2{ int(myFloat) }; // 거의 사용되지 않는다.
    int i3{ static_cast<int>(myFloat) }; // 권장되는 방법
    

    return 0;
    
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
