#include <stdio.h>
#include <stdlib.h> //malloc()�Լ��� ����ϱ� ���� ���
#include <string.h>
#include <malloc.h>
int main(void)
{
	//////<���� �Ҵ�>
	//////void *malloc(size_t size);
	//////��ȯ�� free(void *memblock);
	////int* pList = NULL, i = 0;

	//////12����Ʈ (sizeof*3) �޸� �����Ҵ�
	//////�����ּ� = pList������ ������ ����
	////pList = (int*)malloc(sizeof(int) * 3);

	//////���� �Ҵ��� ��� �޸� �迭 �����ڷ� ����
	////pList[0] = 10;
	////pList[1] = 20;
	////pList[2] = 30;

	////for (int i = 0; i < 3; i++)
	////{
	////	printf("%d\n", pList[i]);
	////}

	////free(pList);
	//////free()�� ��ȯ�߱� ������
	//////printf("%d", pList); = �����Ⱚ�� ���´�. 

	////�ü���� �����Ҵ��� �ϴ� ���
	//int* pList = NULL;

	//pList = malloc(sizeof(int) * 3); //12byte

	//pList[0] = 10;
	//pList[1] = 20;
	//pList[2] = 30;

	////*(((char*)pList) + 12) = 'A';
	////�� �ڵ带 �߰��ϸ� fd������ 41('A')�� �ٲ��.
	////�׷� �������� �����ٴ� ������ ����.
	////��, ���� �����÷ο�
	////fd�κ��� ħ��.
	////������ ���� ���� ���� > �޸� �����÷ο�

	////(((char*)pList)+16) > �ϰԵǸ� fd�� �Ѿ�� �Ǵµ� �׷��� Ž���� �Ѵ�.

	//free(pList);
	
	
	
	/////////////////////////////////////////////////////////////////
	//int * pList = NULL, * pNewList = NULL;

	////A. int�� 3�� �迭 ���� �� ����(0 �ʱ�ȭ)
	//int aList[3] = { 0 };

	////B. int�� 3���� ���� �� �ִ� ũ���� �޸𸮸� �������� �Ҵ� ��
	////�޸𸮸� ��� 0���� �ʱ�ȭ
	//pList = (int*)malloc(sizeof(int) * 3);
	//memset(pList, 0, sizeof(int) * 3);

	////C. int�� 3���� ���� �� �ִ� �޸𸮸� 0���� �ʱ�ȭ�� �� �Ҵ����
	//pNewList = (int*)calloc(3, sizeof(int));
	////�����Ҵ� �޸𸮵��� ����
	//free(pList);
	//free(pNewList);
	//
	/// ////////////////////////////////////////////////////////////////

	//������ �迭 ����� ũ�⸦ ������� �ʾ����� �ʱ갪�� ��������
	//�ڵ����� ũ�Ⱑ �����ȴ�(NULL���� ����� ũ�� ����).
	char szBuffer[] = { "Hello" };

	//"Hello"���ڿ��� ����� �޸��� �ּҷ� �ʱ�ȭ�Ǵ� ������ ����
	char* pszBuffer = "Hello";

	//���� �Ҵ��� �޸��� �ּҰ� ����� ������ ���� �� ����
	char* pszData = NULL;
	//�޸𸮸� �������� �Ҵ��ϰ� "Hello"���ڿ��� �ʱ�ȭ
	pszData = (char*)malloc(sizeof(char) * 6); //Hello + NULL����
	pszData[0] = 'H';
	pszData[1] = 'e';
	pszData[2] = 'l';
	pszData[3] = 'l';
	pszData[4] = 'o';
	pszData[5] = '\0'; //���ڿ� ��

	puts(szBuffer);
	puts(pszBuffer);
	puts(pszData);

	//�����Ҵ��� �޸� ����
	free(pszData);



	//���� �Ҵ�� �޸� ũ�� Ȯ�� : _msize()�Լ�
	/*���� �Ҵ�� �޸� ũ��� ��ÿ� Ȯ���� ����ؾ� �ϹǷ�, �Ҵ�޴� ���忡���� �� ũ�⸦ �� ���� �����ϴ�.
	�׷��� ��Ȥ �Լ� ������ �ڵ尡 ���ҵǸ鼭 �����ͷ� �ּҸ� �ޱ� ������ ũ�⸦ ���� ���� �Ҵ�� �޸� ũ�⸦ �� ���� �ֽ��ϴ�.
	�̶�,
	Window = _msize()�Լ�
	Linix, UNIX = malloc_usable_size()    �� �̿��ϸ� ũ�⸦ �˾Ƴ� �� �ִ�.
	*/
	//_msize()�Լ� Ȱ�� ���
	//#include <malloc.h> 
	char* pszData2 = NULL;

	pszData2 = (char*)malloc(sizeof(char) * 6);
	printf("%d\n", _msize(pszData));
	free(pszData);

	return 0;
}