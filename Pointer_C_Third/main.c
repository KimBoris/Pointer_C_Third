#include <stdio.h>
#include <stdlib.h> //malloc()함수를 사용하기 위한 헤더
#include <string.h>
#include <malloc.h>
int main(void)
{
	//////<동적 할당>
	//////void *malloc(size_t size);
	//////반환시 free(void *memblock);
	////int* pList = NULL, i = 0;

	//////12바이트 (sizeof*3) 메모리 동적할당
	//////시작주소 = pList포인터 변수에 저장
	////pList = (int*)malloc(sizeof(int) * 3);

	//////동적 할당한 대상 메모리 배열 연산자로 접근
	////pList[0] = 10;
	////pList[1] = 20;
	////pList[2] = 30;

	////for (int i = 0; i < 3; i++)
	////{
	////	printf("%d\n", pList[i]);
	////}

	////free(pList);
	//////free()로 반환했기 때문에
	//////printf("%d", pList); = 쓰레기값이 나온다. 

	////운영체제가 동적할당을 하는 방법
	//int* pList = NULL;

	//pList = malloc(sizeof(int) * 3); //12byte

	//pList[0] = 10;
	//pList[1] = 20;
	//pList[2] = 30;

	////*(((char*)pList) + 12) = 'A';
	////이 코드를 추가하면 fd영역에 41('A')로 바뀐다.
	////그럼 힙영역이 깨졌다는 에러를 띄운다.
	////즉, 버퍼 오버플로우
	////fd부분을 침범.
	////포인터 쓸때 가장 문제 > 메모리 오버플로우

	////(((char*)pList)+16) > 하게되면 fd를 넘어가게 되는데 그래도 탐지를 한다.

	//free(pList);
	
	
	
	/////////////////////////////////////////////////////////////////
	//int * pList = NULL, * pNewList = NULL;

	////A. int형 3개 배열 선언 및 정의(0 초기화)
	//int aList[3] = { 0 };

	////B. int형 3개를 담을 수 있는 크기의 메모리를 동적으로 할당 후
	////메모리를 모두 0으로 초기화
	//pList = (int*)malloc(sizeof(int) * 3);
	//memset(pList, 0, sizeof(int) * 3);

	////C. int형 3개를 담을 수 있는 메모리를 0으로 초기화한 후 할당받음
	//pNewList = (int*)calloc(3, sizeof(int));
	////동적할당 메모리들을 해제
	//free(pList);
	//free(pNewList);
	//
	/// ////////////////////////////////////////////////////////////////

	//선언할 배열 요소의 크기를 기술하지 않았지만 초깃값을 기준으로
	//자동으로 크기가 결정된다(NULL문자 저장될 크기 포함).
	char szBuffer[] = { "Hello" };

	//"Hello"문자열이 저장된 메모리의 주소로 초기화되는 포인터 변수
	char* pszBuffer = "Hello";

	//동적 할당한 메모리의 주소가 저장될 포인터 선언 및 정의
	char* pszData = NULL;
	//메모리를 동적으로 할당하고 "Hello"문자열로 초기화
	pszData = (char*)malloc(sizeof(char) * 6); //Hello + NULL문자
	pszData[0] = 'H';
	pszData[1] = 'e';
	pszData[2] = 'l';
	pszData[3] = 'l';
	pszData[4] = 'o';
	pszData[5] = '\0'; //문자열 끝

	puts(szBuffer);
	puts(pszBuffer);
	puts(pszData);

	//동적할당한 메모리 해제
	free(pszData);



	//동적 할당된 메모리 크기 확인 : _msize()함수
	/*동적 할당된 메모리 크기는 당시에 확실히 명시해야 하므로, 할당받는 입장에서는 그 크기를 모를 수가 없습니다.
	그러나 간혹 함수 단위로 코드가 분할되면서 포인터로 주소를 받긴 하지만 크기를 받지 못해 할당된 메모리 크기를 모를 때도 있습니다.
	이때,
	Window = _msize()함수
	Linix, UNIX = malloc_usable_size()    를 이용하면 크기를 알아낼 수 있다.
	*/
	//_msize()함수 활용 방법
	//#include <malloc.h> 
	char* pszData2 = NULL;

	pszData2 = (char*)malloc(sizeof(char) * 6);
	printf("%d\n", _msize(pszData));
	free(pszData);

	return 0;
}