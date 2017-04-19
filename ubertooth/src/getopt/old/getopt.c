/**************************************************************************
*                                                                         *
*     �������  "getopt"  ��������������� ��� ������ ������������ �������  *
*  GCC "getopt".                                                          *
*     ������    �������    �������   "getopt"    ��������    �����������  *
*  �������������,  �� ����, � ������ ���� "getopt" �� ����� ��� "getopt"  *
*  �� ���������� GCC.                                                     *
*     ������  �������  "getopt"  ����������� ���������  ��������  ������  *
*  ������  "getopt" ��  ����������  GCC, ��  ����������� ����  ���������  *
*  ��������:                                                              *
*                                                                         *
*  1) ��������� �� �������, ������ ������ "stderr" ��������� � �����      *
*     "stdout".                                                           *
*                                                                         *
*  2) ������� �� ��������� �� ������� ���������� ��������� -              *
*     "POSIXLY_CORRECT"                                                   *
*                                                                         *
*                                                                         *
*  int getopt (int argc, char* const* argv, const char* optString)        *
*                                                                         *
*  ����: argc      - ���������� ���������� ��������� ������ (������       *
*                    ������� "argv").                                     *
*                                                                         *
*        argv      - ������ ���������� �� ��������� ��������� ������.     *
*                                                                         *
*        optString - ������ �� ������� �������� ����� � ���������         *
*                    ������������ ������� getopt_long.                    *
*                                                                         *
*  �����:    ����  �������  �������� �����,  �� ������� ���������� ASCII  *
*         ��� ������� ���� �����.                                         *
*            ����   ��������  �����  �����  ��������,  ��  ���������  ��  *
*         �������� ���������� � ���������� ���������� "optarg".           *
*            ���    �����������   ��������   �����,   ��������   �������  *
*         �����������   �  "optString",  �������  ����������  '?',  �  �  *
*         ���������� optopt - ���������� ASCII ��� ������������ �����.    *
*            ����  � ��������  �����  �����������  ��������, ��  �������  *
*         ���������� ���� '?', ���� ':', � ����������� �� ������ ������,  *
*         �������������   �������  ���������  ������  "optString",  �  �  *
*         ���������� optopt - ���������� ASCII ��� ������������ �����.    *
*            ��� ����������� ��������� ��������� ������, ������������� �  *
*         "--"  ����� ����� ������������, ������� ���������� -1. �������  *
*         �����  ���������� -1,  ����  ��� ������  ����� ��������  �����  *
*         �������  "argv", �  ����  ������  �������� ������  "optString"  *
*         ��������  '+', ��  ������� ����������  -1 ���  ������ ��������  *
*         ������ �������� ��������� ������, �� ���������� ������.         *
*                                                                         *
*                               ����������                                *
*                                                                         *
*     �����  ����,  ��� ������� "getopt"   ���������� -1 ��� ��������� �  *
*  ���������  "������� ��������", ��� ��������� ��������, ��� ��� ������  *
*  "getopt"   -  ���  ������  ����� ����������  -1,  � �������������  ��  *
*  ��������   ����������   ����������  "optind".  ���  ������  ���������  *
*  "������� ��������", ����� ���������� ���������� ���������� "optreset"  *
*  �  ��������,  ��������  ��  0,  �����  ���  ������  �������  "getopt"  *
*  ���������  "�������  ��������"  ����� ��������,  �������  �������  �  *
*  �������� ��������� � ��������� ���� ������.                            *
*     ���� ������ �������� � ������ "optString" �������� ':', ��"getopt"  *
*  �� ������� ��������� �� �������, � � ������ ���� � �����, ��� �������  *
*  �����������  ���������  �����������, �����������  ��������,  "getopt"  *
*  ���������� ':' ������ '?'.                                             *
*     ����  ������ �������� � ������ "optString" �������� '+' ��� '-', �  *
*  ������  ':' �������� ������ ��������, �� ':' ����� �� ������ �� �����  *
*  ���������   ��  �������,  �  �  ������  ����  �  �����,  ���  �������  *
*  �����������  ���������  �����������, �����������  ��������,  "getopt"  *
*  ���������� ':' ������ '?'.                                             *
*     ���� ������ �������� � ������ "optString" �������� '+', �� �������  *
*  �������  � ���������  "�������  ��������" ����  ��� ������  ��������  *
*  ������  �������� ���������  ������,  �� ����������  ������, ����  ���  *
*  ������  �������� �������� ��������� ������, ������������ � "--", ����  *
*  ���� ��������� ����� ������� "argv".                                   *
*     ���� ������ �������� � ������ "optString" �������� '-', �� �������  *
*  �����  ���������  ����� �����  ����  ��  ���  ���, ����  ��  ��������  *
*  �������� ��������� ������, ������������ � "--", ���� �� ��� ���, ����  *
*  ��  ��������� ����� ������� "argv". ������, � �������� ������ �������  *
*  ��  ����� ����������� ������ "argv", ��������� ����� � �� ��������� �  *
*  ������ �������, � �� ����� � ����� �������.                            *
*     ����  ������ ��������  ������ "optString" �� �������� '+' ��� '-',  *
*  �� ������� ��������� ����� ���� �� ��� ���, ���� �� �������� ��������  *
*  ���������  ������, ������������  � "--",  ����  �� ���  ���, ����  ��  *
*  ���������  �����  ������� "argv". ���  ���� � �������� ������ �������  *
*  �����  ����������� ������  "argv" ���������  ����� �  �� ���������  �  *
*  ������ �������, � �� ����� � ����� �������.                            *
*     ����   �  ����������   ����������  "opterr"   ��������  ����,   ��  *
*  �������"getopt" �� ����� �������� ��������� �� �������.                *
*     ���������  �� �������������  �������  "getopt"  ����� ��������  ��  *
*  ������: http://www.firststeps.ru/linux/r.php?10                        *
*                                                                         *
*                         ������������ ����������                         *
*                                                                         *
*     ������ ��������� ���������������� ��� ����. �� ������ ������������  *
*  ���������  �� ����  ����. ����� ��������� �� ���� ��������������� ��  *
*  �����   �����  �����  ���  ��������  ����������  ������  ����������.  *
*  ��������� ������ ���������, �� ������������ � ������ �����������.      *
*                                                                         *
*                                         Copyright (c) ������� ��������  *
*                                               eugen-soloviov@yandex.ru  *
*                                                                         *
***************************************************************************/

#include "getopt.h"
#include <stdio.h>

#define bool int
#define true 1
#define false 0

extern const char getopt_argument_error[];
extern const char getopt_option_error[];
extern const char getopt_printf_option[];

extern char* _cdecl _find_app_name (char*);

int getopt (int argc, char* const* argv, const char* optString)
 {
   static bool Parsing_Done = false; // ������� ��������
   
   static unsigned int first_nonopt = 0;     
   static unsigned int last_opt = 0;
   static unsigned int j = 1;
   
   static char* app_name = 0;    // ��������� �� ��� ����������

/*--------------------- ����� ������ ������ getopt ----------------------*/
   
   bool Stop_At_Fist_Non_Option;   /* ������������� ������� ��� ��������� 
                                      ������� ��������� ������� */
   
   bool Permute_Premission;        // ���������� ����������� � argv
   
   bool Mark_Argument_Error;       /* ������ �������� ����� �������� ������ 
                                      � ����������� ��������� */
   
   bool Error_Messages_Premission; // ���������� ������ ��������� �� �������
                                       
/*-----------------------------------------------------------------------*/   
   
   int current_value, next_value;
   unsigned int i;

   if (optreset)
    {
      // ����� getopt � �������� ���������
      
      first_nonopt = 0;
      last_opt = 0;
      optreset = 0;
      j = 1;
      Parsing_Done = false;
    }
   
   if (Parsing_Done)
    return -1;
   
   
   /* ������ ��������� ������ ������ "optString" � ��������� ������ ������ ������
      getopt */
   
   if (optString[0] == '-') 
    {
      Stop_At_Fist_Non_Option = false;
      Permute_Premission = false;
      optString++;
    }
   else
    if (optString[0] == '+') 
     {
       Stop_At_Fist_Non_Option = true;
       Permute_Premission = false;
       optString++;
     }
    else
     {
       Stop_At_Fist_Non_Option = false;
       Permute_Premission = true;
     }

   if (optString[0] == ':')
    {
      Mark_Argument_Error = true;
      optString++;
    }
   else
    Mark_Argument_Error = false;
  
   Error_Messages_Premission = opterr && ( !Mark_Argument_Error
                                           ||
                                           !Permute_Premission );
   
   optarg = 0;
   
   if (!app_name)
    app_name = _find_app_name(argv[0]); // ������������� ���������� app_name
   

   if (Permute_Premission && first_nonopt && (j == 1))
    _asm call _argv_permute;  // ���������� ������������ � argv
      
  
   if (j > 1) 
    goto _short_option_parsing;

   
   // ���� ������ ����� � ���������� ��������� ������
      
   for (;; optind++)
    {
      if ( (unsigned int)optind >= (unsigned int)argc )
       {
         // ������� � ��������� "������� ��������"

_parsing_complete:      

         if (Permute_Premission && first_nonopt)
           optind = first_nonopt;
 
         Parsing_Done = true;
         return -1;
       }

      
      current_value = *argv[optind];
      next_value = *(argv[optind]+1);
      
      if (current_value == '-' && next_value != '\0')
       break;
      
      if (Stop_At_Fist_Non_Option)
       goto _parsing_complete;
      
      if (!first_nonopt)
       first_nonopt = optind;
     
    }

      
   last_opt = optind;
   
   if (next_value != '-')
    {
      // ��������� �������� �����  
      
_short_option_parsing:       
      
      current_value = *(argv[optind]+j);
      
      
      // ���� ������ �������� �����
      
      for (i = 0 ; ; i++)
       {
         char cc;
         cc = optString[i];
         
         if (cc == '\0')
          {
            // ������ - ������������� �������� �����
           
            if (Error_Messages_Premission)
             printf (getopt_printf_option, app_name, getopt_option_error, &current_value);
            
            optopt = current_value;
            j++;
            if (*(argv[optind]+j) == '\0')
             {
               j = 1;
               optind++;
             }
            
            return '?';
          }
         
         if (cc == ':' || cc == ';')
          continue;
         
         if (current_value == cc)
          break;
            
       }
      
       
       if (optString[i+1] == ':')
        {
          if (optString[i+2] != ':')
           {
             // �������� ����� ����� ������������ ��������
           
             j++;
             if (*(argv[optind]+j) != 0)
              optarg = argv[optind]+j;
             else
              if ( (unsigned int)optind <= (unsigned int)(argc - 2) )
               {
                 optarg = argv[optind+1];
                 optind++;
               }
              else
               {
                 // ������ - ����������� �������� �������� �����
               
                 if (Error_Messages_Premission)
                  printf (getopt_printf_option, app_name, getopt_argument_error, &current_value);
            
                 optopt = current_value;
                 
                 if (Mark_Argument_Error) 
                  current_value = ':';
                 else
                  current_value = '?';
               }
             
             goto _short_option_parsing_end;
           }
          else
           {
             // �������� ����� ����� �������������� ��������
             
             j++;
             if (*(argv[optind]+j) != 0)
              optarg = argv[optind]+j;
              
             goto _short_option_parsing_end;
           }
        }
      
      
      // �������� ����� �� ����� ����������
      
      if (current_value != 'W' && optString[i+1] != ';') /* ���� �������� ����� 'W' � �
                                                           "optString" ���������� "W;", 
                                                           �� �������������� "-W.." , 
                                                           ��� ������� �����    */
       {
         // ����������� ��������� �������� ����� ��� ����������
         
         j++;
      
         if (*(argv[optind]+j) != '\0')
          return current_value;
         else 
          {
_short_option_parsing_end:             

            optind++;
            j = 1;
           
            return current_value;
          }
       }
    }

   
   /* ���������� �������� � ������ ���� argv[optind] �������� ������� ������ 
      ��� ASCIIZ-�������  "--" */
      
   optind++;
   
   if (Permute_Premission && first_nonopt)
    _asm call _argv_permute; // ���������� ������������ � argv

   goto _parsing_complete;


/**************************************************************************
*                                                                         *
*     ������������  "_argv_permute"  - ��������� ������������ ����������  *
*  ���������  ������,  ���������� ���������  ��� ������������ ����� � ��  *
*  ���������  �  ������ ������� "argv", � ��� ��������� �� ����� � �����  *
*  ������� "argv".                                                        *
*                                                                         *
**************************************************************************/

_argv_permute:
   {
     char* aa;
     char* cc;
      
     while (last_opt < (unsigned int) optind)
      {
        aa = argv[last_opt];
        for (i = last_opt; i > first_nonopt; i--)
         {
           cc = argv[i-1];
           *(char**)&argv[i] = cc;
         }
        *(char**)&argv[first_nonopt] = aa;
        last_opt++;
        first_nonopt++;
      }
   }
  _asm  ret;
  
 }
