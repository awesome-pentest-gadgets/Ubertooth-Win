#define MAP_FAILED NULL
//#define MAP_FAILED      ((void *)-1)

#define MAP_SHARED 	 1 //��������� ���������� ������ ���������
#define MAP_PRIVATE  2	//��������� �� ���������� ������ ��������� � �� ������ �� ������������ ������
#define MAP_FIXED 	 4  //�������� addr ���������������� ��� ����� ������
#define PROT_READ    1
#define PROT_WRITE   2


/* getpagesize for windows */
long getpagesize (void);
long getregionsize (void); 
/* mmap for windows */
void *mmap (void *ptr, long size, long prot, long type, long handle, long arg);
long munmap (void *ptr, long size);
