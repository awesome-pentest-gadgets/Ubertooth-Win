#define bool int
#define true 1
#define false 0

int	opterr = 1;   // ���������� ������ ��������� �� �������
int	optind = 1;   // ������ ��������� ��������� ������ ����������� ���������
int	optopt = '?';
int	optreset = 0; // ����� getopt
char    *optarg = 0;  // ��������� �� �������� �����

const char getopt_argument_error[] = ": option requires an argument --";
const char getopt_option_error[] = ": unknown option --";
const char getopt_printf_option[] = "%s%s %s\n";


/**************************************************************************
*                                                                         *
*     �������  _find_app_name -  ���� ��� ����� � ������ ����: "����\���  *
*  �����" � ���������� ��������� �� ��� �����.                            *
*                                                                         *
**************************************************************************/

char* _find_app_name (char* argv_0)
 {
   char * pointer = argv_0;
   char * i;

   for (i = argv_0; *i != 0; i++)
    {
      if (*i == '\\')
       pointer = i;
    }

   return pointer+1;
 }
