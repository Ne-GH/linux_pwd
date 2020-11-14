#include <stdio.h>
#include <stdlib.h> 	// 完整的代码中使用了exit,因此需要stdlib.h
#include <stdbool.h>	//使用了true
#include <sys/types.h>	//使用了ino_t这一名称
#include <unistd.h>		//使用了chdir，用来改变工作路径
#include "mypwd.h"		//自定义的头文件，声明了MAX_LAYER和两个函数
int main(){

	//字符指针数组用来存储目录信息
	char *file_name[MAX_LAYER] = {0};
	//times用来存储目前位置查找了多少次
	unsigned int times = 0;

	while(true){
		/*  定义了两个ino_t类型的变量分别记录当前文件夹的ino_t和上一层目录的ino_t */
		ino_t current_ino = Get_ino(".");
		ino_t father_ino  = Get_ino("..");

		/* 相等时说明到达根 */
		if(current_ino == father_ino)
			break;

		/* 进入上一层目录 */
		chdir("..");

		/* 记录文件夹的名称 */
		file_name[times++] = Get_name(current_ino);

		/* 查找的次数过多了 */
		if(times >= MAX_LAYER){
			fprintf(stderr,"路径太深.\n");
			exit(-1);
		}
	}

	//完整地打印出路径
	for( int i = times - 1;i >= 0; --i){
		fprintf(stdout,"/%s",file_name[i]);
	}
	putchar(10);
	return 0;
}
