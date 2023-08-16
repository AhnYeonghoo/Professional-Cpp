#include <iostream>

using namespace std;

/*
* 바람직한 스타일의 기준
* 1. 문서화(주석)
* 2. 코드분해
* 3. 명명 규칙
* 4. 언어 사용
* 5. 코드서식(포매팅)
*/

// 문서화
// 함수에 대한 문서화 잘 해놓기
// Example

// 주어진 레코드를 데이터베이스에 저장한다.
//
// 매개변수:
//		record: 주어진 레코드에 데이터베이스 ID가 없다면
//		데이터베이스로부터 할당된 ID를 저장하도록 레코드 객체를 수정한다.
// 리턴: int
//		 저장된 레코드의 ID를 표현하는 정수
// 익셉션 발생:
//		openDatabase()를 먼저 호출하지 않은 상태에서
//		이 메서드를 호출하면 DatabaseNotOpenedException이 발생한다.
int saveRecord(int record)
{
	/*dd*/
	return 0;
}

// 복잡한 코드를 설명하는 주석의 예
/*
* 삽입 정렬 알고리즘을 구현한다. 이 알고리즘은 주어진 배열을 두 부분으로 나눈다.
* 하나는 정렬된 부분이고, 다른 하나는 정렬되지 않은 부분이다. 각 원소의 위치는
* 1부터 시작하며, 모든 원소를 차례대로 검사한다. 이 배열의 앞부분은 모두 정렬된
* 부분이므로 현재 원소를 삽입할 정확한 지점을 찾을 떄 까지 각 원소를 하나씩 검사한다.
* 마지막 원소까지 알고리즘을 수행하고 나면 전체 배열이 정렬된다.
*/
void sort(int data[], size_t size)
{
	// 위치 1부터 시작해서 모든 원소를 하나씩 검사한다.
	for (int i{ 1 }; i < size; i++) {
		// 불변 속성:
		//		0부터 i-1 사이에 있는 원소는 모두 정렬된 상태이다.

		int element{ data[i] };

		// j는 정렬된 부분의 마지막 지점을 가리키며, 그 뒤에 원소를 추가한다.
		int j{ i };

		// 정렬된 배열에서 현재 위치가 이원소보다 높다면 오른쪽 자리에 원소를 삽입할
		// 자리를 확보하도록 값을 오른쪽으로 이동한다.
		// (그러므로 삽입 정렬이라고 부른다)
		while (j > 0 && data[j - 1] > element) {
			data[j] = data[j - 1];
			j--;
		}
		data[j] = element;
	}
}

// 메타 정보를 제공하는 주석
/*
* 작성자: Ahn
* 작성일: 2023/08/15
* 기능: PRD 버전3, 기능 5.10
*/

void saveRecordVoid()
{
	return;
}
