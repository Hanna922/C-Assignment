#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13

int availabilityCheck(char* resident_number);
int checkLengthCharacter(char* resident_number);
int checkDate(char* resident_number);
int checkIdentification(char* resident_number);
int checkGender(char* resident_number);
int checkYear(int year);

int main()
{
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
			"0003154194917", "801203#201122", "7804155328845", "7804150328840",
			"9612241068382", "9902292194322", "0230174326176", "8811391042219",
			"8100122042213", "8112002042213", "9210101069415", "0802294012345",
			"8806311069417","8807311069418" };
	int i, count;
	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i < count; i++) {
		if (availabilityCheck(resident_number[i]) == TRUE) {
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else {
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}

/*----------------------------------------------------------------
  availabilityCheck()�Լ� : �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�ϸ� TRUE, ��ȿ���� ������ FALSE ����
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)
{
	if (checkLengthCharacter(resident_number)) /* �ֹε�Ϲ�ȣ ���� �� ���ڹ��� ��ȿ�� �˻� */
	{
		if (checkDate(resident_number))  /* ��¥ �˻� */
		{
			if (checkGender(resident_number)) /* �ֹε�Ϲ�ȣ�� ���� �ĺ���ȣ(7��° ����) ��ȿ�� �˻� */
			{
				if (checkIdentification(resident_number))  /* �ν��� ����üũ*/
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*-------------------------------------------------------------------------
  checkLengthCharacter()�Լ� : �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ�� �˻� �Լ�
  �������� : �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ������� TRUE,
		   ���̰� ª�ų� ���, ���ڹ��ڰ� �ƴ� ���ڰ� ���������� FALSE ����
--------------------------------------------------------------------------*/

int checkLengthCharacter(char* resident_number) {
	if (strlen(resident_number) == 13) {
		for (int i = 0; i < strlen(resident_number); i++) {
			if (getchar() != '\n') {
				return FALSE;
				break;
			}
		}
		return TRUE;
	}
	else {
		return FALSE;
	}	
}

/*----------------------------------------------------------------
  checkDate()�Լ� : ù 6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�� ��¥�̸� TRUE, ��ȿ���� ���� ��¥�̸� FALSE ����
------------------------------------------------------------------*/

int checkDate(char* resident_number) {

	
}

/*----------------------------------------------------------------------
  checkGender()�Լ� : 7��° �ڸ��� ���� �ĺ���ȣ ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ���� �ĺ���ȣ�� '1'~'4'�̸� TRUE, �׿� ���ڹ����̸� FALSE ����
-----------------------------------------------------------------------*/

int checkIdentification(char* resident_number) {

	
}

/*------------------------------------------------------------------------
  checkIdentification()�Լ� : �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
  �������� : ��ȿ�� �˻��� �ֹε�Ϲ�ȣ (���ڿ�)
  ���ϰ� : ��ȿ�� ��¥�̸� TRUE, ��ȿ���� ���� ��¥�̸� FALSE ����
-------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkYear()�Լ� : �⵵�� ��,��� ���� �˻�
  �������� : ��,��� �˻��� �⵵
  ���ϰ� : �����̸� 1, ����̸� 0 ����
------------------------------------------------------------------*/

//TODO