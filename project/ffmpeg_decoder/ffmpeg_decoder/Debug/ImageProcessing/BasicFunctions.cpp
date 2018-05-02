/*	C�y���v���B�z�禡�w
	Develop by Jimmy HU <s103360021@gmail.com>
	This program is licensed under GNU General Public License v3.
	BasicFunctions.cpp�Ω��@��¦�Ƶ{��
*/
#include "BasicFunctions.h"

unsigned char BmpFillingByteCalc(const unsigned int xsize)				//	BmpFillingByteCalc(BMP���ɶ�ɦ줸�p��)�Ƶ{��
{																		//	�i�JBmpFillingByteCalc�Ƶ{��
	unsigned char FillingByte;											//	�ŧiFillingByte�O����ɦ줸�խp�⵲�G
	FillingByte = ( xsize % 4);											//	�p���ɦ줸�ռƶq
	return FillingByte;													//	�Ǧ^�p�⵲�G
}																		//	����BmpFillingByteCalc�Ƶ{��
bool FileExistCheck(char *file_name)									//	FileExistCheck(�ɮצs�b�ˬd)�Ƶ{��
{																		//	�i�JFileExistCheck(�ɮצs�b�ˬd)�Ƶ{��
	if( access( file_name, F_OK ) != -1 )								//	�Y�ɮצs�b
	{																	//	�i�Jif�ԭz
    	return True;													//	�Ǧ^True
	} 																	//	����if�ԭz
	else 																//	�Y�ɮפ��s�b
	{																	//	�i�Jelse�ԭz
	    return False;													//	�^��false
	}																	//	����else�ԭz
} 																		//	����FileExistCheck(�ɮצs�b�ˬd)�Ƶ{��
bool FileReadPermissionCheck(const char *file_name)						//	FileReadPermissionCheck(�ɮ�Ū���v���ˬd)�Ƶ{��
{																		//	�i�JFileReadPermissionCheck(�ɮ�Ū���v���ˬd)�Ƶ{��
	if( access( file_name, R_OK ) != -1 )								//	�Y�ɮץiŪ��
	{																	//	�i�Jif�ԭz
    	return True;													//	�Ǧ^True
	} 																	//	����if�ԭz
	else 																//	�Y�ɮפ��iŪ��
	{																	//	�i�Jelse�ԭz
	    return False;													//	�^��false
	}																	//	����else�ԭz
} 																		//	����FileReadPermissionCheck(�ɮ�Ū���v���ˬd)�Ƶ{��
bool FileWritePermissionCheck(const char *file_name)					//	FileWritePermissionCheck(�ɮ׼g�J�v���ˬd)�Ƶ{��
{																		//	�i�JFileWritePermissionCheck(�ɮ׼g�J�v���ˬd)�Ƶ{��
	if( access( file_name, W_OK ) != -1 )								//	�Y�ɮץiŪ��
	{																	//	�i�Jif�ԭz
    	return True;													//	�Ǧ^True
	} 																	//	����if�ԭz
	else 																//	�Y�ɮפ��iŪ��
	{																	//	�i�Jelse�ԭz
	    return False;													//	�^��false
	}																	//	����else�ԭz
} 																		//	����FileWritePermissionCheck(�ɮ׼g�J�v���ˬd)�Ƶ{��

bool FileWrite(const char *file_name,const char *input_str,const char *mode)
//	FileWrite(�ɮ׼g�J)�Ƶ{���A�����r�ɮ׼g�J
//	file_name�����g�J�ɮ��ɦW
// 	input_str�����g�J�ɮפ����ЧΦ��r����
//	mode���g�J�ɮ׼Ҧ��]�w�A�i�ǤJ"w"��"a"�A"w"���s�W/�л\�Ҧ��A"a"���X�R�Ҧ�
//	�^�ǵ��G�G�Y�ɮ׼g�J���\�^��True�A�Y�g�J���Ѧ^��False
{																		//	�i�JFileWrite(�ɮ׼g�J)�Ƶ{��
	FILE *file_point;													//	�ŧi�@file_point���СA�����ɮ�Ū�g
	if (strcmp(mode, "w") != 0 && strcmp(mode, "a") != 0 && strcmp(mode, "w+") != 0 && strcmp(mode, "a+") != 0)
	//	�Ymode�ѼƤ���"w"�礣��"a"�礣��"w+"�礣��"a+"
	{																	//	�i�Jif�ԭz
		printf("FileWrite:mode ERROR!\n");								//	���"FileWrite:mode ERROR!"�ô���
		return False;													//	�^��False�õ����Ƶ{����^
	}																	//	����if�ԭz
	if( strcmp(mode, "a") == 0 || strcmp(mode, "a+") == 0 )				//	�Ymode�ѼƬ�"a"��"a+"(�X�R�Ҧ�)
	{																	//	�i�Jif�ԭz
		if (FileWritePermissionCheck(file_name) == False)				//	�Y�ɮ׵L�k�g�J
		{																//	�i�Jif�ԭz
			printf("FileWrite:permission ERROR!\n");					//	���"FileWrite:permission ERROR!"�ô���
			return False;												//	�^��False�õ����Ƶ{����^
		}																//	����if�ԭz
	}																	//	����if�ԭz
	file_point = fopen(file_name, mode);								//	�Hmode�Ҧ����}�ɮ�
	//	fprintf��fputs�y�k�G�ܤ@�ϥ�
	fprintf(file_point, input_str);										//	�Hfprintf�y�k�g�J�ɮ�
	//fputs(input_str, file_point);										//	�Hfputs�y�k�g�J�ɮ�
	fclose(file_point); 												//	�����ɮ�
	return True;														//	�^��True�õ����Ƶ{����^
}																		//	����FileWrite(�ɮ׼g�J)�Ƶ{��

unsigned char *UCharBubbleSort(	const unsigned char *InputData,
								const unsigned long long int InputDataNum,
								const bool Mode)
//	UCharBubbleSort�Ƶ{��
{																		//	�i�JUCharBubbleSort�Ƶ{��
	unsigned char *OutputData;											//	�ŧiOutputData�O����X���
	OutputData = (unsigned char*)malloc( InputDataNum * sizeof(unsigned char) );
	//	�t�mOutputData��X��ƫ��аO����Ŷ�
	unsigned long long int LoopNumber1,LoopNumber2;						//	�ŧiLoopNumber1�PLoopNumber2�A�Ω�j����榸�ƭp��
	for(LoopNumber1=0;LoopNumber1 < InputDataNum;LoopNumber1++)			//	�H�j��̧�
	{																	//	�i�Jfor�j��
		OutputData[LoopNumber1] = InputData[LoopNumber1];				//	�ƻs��Ʀܿ�X���аO����Ŷ�
	}																	//	����for�j��
	for(LoopNumber2 = 1;LoopNumber2 < InputDataNum;LoopNumber2++)		//	�H�j��̧Ǥ���ƭ�
	{																	//	�i�Jfor�j��
		for(LoopNumber1=0;LoopNumber1 < InputDataNum - LoopNumber2;LoopNumber1++)
		//	�H�j��̧Ǥ���ƭ�
		{																//	�i�Jfor�j��
			if( Mode == 0 )												//	�Y�Ҧ����Ѥp�Ʀܤj
			{															//	�i�Jif�ԭz
				if(OutputData[LoopNumber1] > OutputData[LoopNumber1 + 1])
				//	�Y���j���ƭȦb�e
				{														//	�i�Jif�ԭz
					unsigned char TempNumber;							//	�ŧiTempNumber�Ȧs�ܼ�(�Ω�ƭȥ洫)
					TempNumber = OutputData[LoopNumber1];				//	�ƭȥ洫
					OutputData[LoopNumber1] = OutputData[LoopNumber1 + 1];
					//	�ƭȥ洫
					OutputData[LoopNumber1 + 1] = TempNumber;			//	�ƭȥ洫
				}														//	����if�ԭz
			}															//	����if�ԭz
			else if( Mode == 1 )										//	�Y�Ҧ����Ѥj�Ʀܤp
			{															//	�i�Jelse if�ԭz
				if(OutputData[LoopNumber1] < OutputData[LoopNumber1 + 1])
				//	�Y���p���ƭȦb�e
				{														//	�i�Jif�ԭz
					unsigned char TempNumber;							//	�ŧiTempNumber�Ȧs�ܼ�(�Ω�ƭȥ洫)
					TempNumber = OutputData[LoopNumber1];				//	�ƭȥ洫
					OutputData[LoopNumber1] = OutputData[LoopNumber1 + 1];
					//	�ƭȥ洫
					OutputData[LoopNumber1 + 1] = TempNumber;			//	�ƭȥ洫
				}														//	����if�ԭz
			}															//	����else if�ԭz
		}																//	����for�j��
	}																	//	����for�j��
	return OutputData;													//	�^�ǿ�X���
}																		//	����UCharBubbleSort�Ƶ{��

int Compare(const void *data1,const void *data2)						//	Compare�Ƶ{��
{																		//	�i�JCompare�Ƶ{��
	int *ptr1 = (int*)data1;											//	�ŧi*ptr1��ƫ����ܼ�
	int *ptr2 = (int*)data2;											//	�ŧi*ptr2��ƫ����ܼ�
	if(*ptr1 < *ptr2)													//	�Y*ptr1�ƭȸ��p
	{																	//	�i�Jif�ԭz
		return -1;														//	�Ǧ^-1�A�õ����Ƶ{��
	}																	//	����if�ԭz
	else if(*ptr1 > *ptr2)												//	�Y*ptr1�ƭȸ��j
	{																	//	�i�Jelse if�ԭz
		return 1;														//	�Ǧ^1�A�õ����Ƶ{��
	}																	//	����else if�ԭz
	else																//	�Y*ptr1�P*ptr2�ƭȬ۵�
	{																	//	�i�Jelse�ԭz
		return 0;														//	�Ǧ^0�A�õ����Ƶ{��
	}																	//	����else�ԭz	
}																		//	����Compare�Ƶ{��
unsigned long long int CountCharPointStr(const char *Input_string, const bool Detail)	
//	CountCharPointStr(�p��r�����Ъ���)�Ƶ{���A�p��r������(�r��)����
{																		//	�i�JCountCharPointStr�Ƶ{��
	unsigned long long int count_num = 0;								//	�ŧicount_num�ϰ��ܼơA�ó]�w��l�Ȭ�0
	while (Input_string[count_num] != '\0')								//	�Y�D�r�굲��
	{																	//	�i�Jwhile�ԭz
		if(Detail == True)												//	�YDetail�ѼƬ�True
		{																//	�i�Jif�ԭz
			printf("��%d�Ӧr�����G%c\n",count_num + 1,Input_string[count_num]);
			//	��ܭp�ƲӸ`
		}																//	����if�ԭz
		count_num++;													//	�֥[count_num�ܼ�
    }																	//	����while�ԭz
    return count_num;													//	�^��count_num(�r�����Ъ���)�ܼ�
}																		//	����CountCharPointStr�Ƶ{��
void Show_char_point_str(const char *Input_string)						//	Show_char_point_str(��ܦr������)�Ƶ{��
/*	��ܦr�ꤺ�e
	�ޥΰƵ{���G
		CountCharPointStr(�p��r�����Ъ���)�Ƶ{��
*/
{																		//	�i�JShow_char_point_str�Ƶ{��
	unsigned long long int loop_num = 0;								//	�ŧiloop_num�ϰ��ܼƨѰj��ϥΡA�ó]�w��l�Ȭ�0
	for(loop_num = 0; loop_num < CountCharPointStr(Input_string, False); loop_num++)
	{																	//	�i�Jfor�j��
		printf("%c",Input_string[loop_num]);							//	�̧���ܦr��
	}																	//	����for�j��
}																		//	����Show_char_point_str�Ƶ{��
void ShowUCharPointStr(const unsigned char *InputData,unsigned long long int InputDataLen)
//	ShowUCharPointStr(��ܵL���r������)�Ƶ{��
{																		//	�i�JShowUCharPointStr�Ƶ{��
	unsigned long long int LoopNumber = 0;								//	�ŧiLoopNumber�ܼơA�Ω�j��p��
	for(LoopNumber=0;LoopNumber<InputDataLen;LoopNumber++)				//	�Hfor�j��̧���ܨC������
	{																	//	�i�Jfor�j��
		printf("%u,",InputData[LoopNumber]);							//	��ܵL���r�����Ф��e
	}																	//	����for�j��
}																		//	����ShowUCharPointStr�Ƶ{��
void ShowLongDouble(const long double InputNumber)						//	ShowLongDouble�Ƶ{��
{																		//	�i�JShowLongDouble�Ƶ{��
	int TimesNumber = 308;												//	�ŧiTimesNumber�����(int)�ܼơA�ê�l�Ƭ�308
	long double DisplayNumber;											//	�ŧiDisplayNumber�ܼơA�Ω�O����ܼƭ�
	//***�B�z���t��***
	if(InputNumber < 0)													//	�YInputNumber��J�ƭȬ��t��
	{																	//	�i�Jif�ԭz
		DisplayNumber = (long double)0.0 - InputNumber;					//	��JDisplayNumber�ƭ�
		printf("-");													//	��ܭt��"-"
	}																	//	����if�ԭz
	else																//	�YInputNumber��J�ƭȤ����t��
	{																	//	�i�Jelse�ԭz
		DisplayNumber = InputNumber;									//	��JDisplayNumber�ƭ�
	}																	//	����else�ԭz
	//***�h���e��0***
	char DisplayChar='\0';												//	�ŧiDisplayChar���r��(char)���A�A�ê�l�Ƭ��Ŧr��
	DisplayChar = floor(DisplayNumber/(long double)pow(10,TimesNumber)) - pow(10,1) * floor(DisplayNumber/(long double)pow(10,(TimesNumber + 1)));
	//	���X��ܼƭ�
	while((DisplayChar == 0) && (TimesNumber > 0))						//	�Y�ƭȬ�0�BTimesNumber(����)�j��0(�����Ӧ��)
	{																	//	�i�Jwhile�ԭz
		TimesNumber = TimesNumber - 1;									//	����TimesNumber�ܼ�
		DisplayChar = floor(DisplayNumber/(long double)pow(10,TimesNumber)) - pow(10,1) * floor(DisplayNumber/(long double)pow(10,(TimesNumber + 1)));
		//	���X��ܼƭ�
	}																	//	����while�ԭz
	//***��ܼƭ�***
	int DisplayStartTimes = TimesNumber;								//	�ŧiDisplayStartTimes�����(int)�ܼơA�ΥH�O���_�l��ܼƦr����
	int DisplayDigit;													//	�ŧiDisplayDigit�����(int)�ܼơA�ΥH�O����ܦ��
	if(DisplayStartTimes > 14)											//	�YDisplayStartTimes(�_�l��ܼƦr����)�j��14(�Y����ܼƭ�InputNumber�j��10^14)
	{																	//	�i�Jif�ԭz
		DisplayDigit = DisplayStartTimes;								//	���wDisplayDigit��ܦ�Ƭ��_�l��ܼƦr�����
	}																	//	����if�ԭz
	else																//	�Y����ܼƭ�InputNumber���j��10^14
	{																	//	�i�Jelse�ԭz
		DisplayDigit = 14;												//	���wDisplayDigit��ܦ�Ƭ�14��(���Ħ��)
	}																	//	����else�ԭz
	while(TimesNumber >= DisplayStartTimes - DisplayDigit)				//	
	{																	//	�i�Jwhile�ԭz
		if(TimesNumber == -1)											//	�YTimesNumber(����)��-1��
		{																//	�i�Jif�ԭz
			printf(".");												//	��ܤp���I
		}																//	����if�ԭz
		DisplayChar = floor(DisplayNumber/(long double)pow(10,TimesNumber)) - pow(10,1) * floor(DisplayNumber/(long double)pow(10,(TimesNumber + 1)));
		//	���X��ܼƭ�
		if( (DisplayChar >= 0) && (DisplayChar <= 9) )					//	�Y���X���ƭȤ���0~9����
		{																//	�i�Jif�ԭz
			printf("%d",DisplayChar);									//	��ܼƭ�
		}																//	����if�ԭz
		else															//	�Y���X�ƭȿ��~
		{																//	�i�Jelse�ԭz
			break;														//	����while�j��
		}																//	����else�ԭz
		TimesNumber = TimesNumber - 1;									//	����TimesNumber�ܼ�
	}																	//	����while�ԭz
}																		//	����ShowLongDouble�Ƶ{��