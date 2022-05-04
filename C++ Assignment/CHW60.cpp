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
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
			"0003154194917", "801203#201122", "7804155328845", "7804150328840",
			"9612241068382", "9902292194322", "0230174326176", "8811391042219",
			"8100122042213", "8112002042213", "9210101069415", "0802294012345",
			"8806311069417","8807311069418" };
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i < count; i++) {
		if (availabilityCheck(resident_number[i]) == TRUE) {
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else {
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}

/*----------------------------------------------------------------
  availabilityCheck()함수 : 주민등록번호 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효하면 TRUE, 유효하지 않으면 FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)
{
	if (checkLengthCharacter(resident_number)) /* 주민등록번호 길이 및 숫자문자 유효성 검사 */
	{
		if (checkDate(resident_number))  /* 날짜 검사 */
		{
			if (checkGender(resident_number)) /* 주민등록번호중 성별 식별번호(7번째 숫자) 유효성 검사 */
			{
				if (checkIdentification(resident_number))  /* 인식자 오류체크*/
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*-------------------------------------------------------------------------
  checkLengthCharacter()함수 : 주민등록번호 길이 및 문자 유효성 검사 함수
  전달인자 : 검사할 주민등록번호 (문자열)
  리턴값 : 주민등록번호의 길이가 맞고 숫자문자로만 구성되어있으면 TRUE,
		   길이가 짧거나 길고, 숫자문자가 아닌 문자가 섞여있으면 FALSE 리턴
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
  checkDate()함수 : 첫 6자리(연,월,일)의 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
------------------------------------------------------------------*/

int checkDate(char* resident_number) {

	
}

/*----------------------------------------------------------------------
  checkGender()함수 : 7번째 자리의 성별 식별번호 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 성별 식별번호가 '1'~'4'이면 TRUE, 그외 숫자문자이면 FALSE 리턴
-----------------------------------------------------------------------*/

int checkIdentification(char* resident_number) {

	
}

/*------------------------------------------------------------------------
  checkIdentification()함수 : 주민등록번호 끝자리(인식자) 유효성 검사 함수
  전달인자 : 유효성 검사할 주민등록번호 (문자열)
  리턴값 : 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
-------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------
  checkYear()함수 : 년도의 윤,평년 여부 검사
  전달인자 : 윤,평년 검사할 년도
  리턴값 : 윤년이면 1, 평년이면 0 리턴
------------------------------------------------------------------*/

//TODO