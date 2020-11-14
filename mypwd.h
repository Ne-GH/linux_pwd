/*
 * time:	2020.11.14
 * author:	Ne-GH
*/
#ifndef _MY_PWD_
#include <sys/types.h>

//目录的最大层数
#define MAX_LAYER 254

//通过文件名称得到他的ino_t
ino_t Get_ino(char *name);

//通过文件的ino_t得到他的filename
char* Get_name(ino_t ino);

#define _MY_PWD_
#endif
