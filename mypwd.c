#include <stdlib.h> 	// 完整的代码中使用了exit,因此需要stdlib.h
#include <string.h>		// 使用了strdup来拷贝字符串
#include <dirent.h>		// 使用了DIR结构体
#include <sys/stat.h>	// 使用了stat结构体和与之相关的函数
#include "mypwd.h"		// 自定义的头文件，声明了MAX_LAYER和两个函数

/* 通过文件的文件名得到他的ino_t */
ino_t Get_ino(char *name){
	struct stat filestat;

	/* int stat(const char * file_name, struct stat *buf); */
	/* stat()用来将参数file_name 所指的文件状态, 复制到参数buf 所指的结构中,返回值为0时表示执行失败 */
	if(0 != stat(name,&filestat)){
		exit (-1);
	}
	return filestat.st_ino;
}

/* 通过文件的ino_t得到他的name */
char* Get_name(ino_t ino){

	DIR *pdir            = NULL;		/* DIR结构体类似于FILE，是一个内部结构，以下几个函数用这个内部结构保存当前正在被读取的目录的有关信息。*/
	struct dirent *pdent = NULL;		/* dirent不仅仅指向目录，还指向目录中的具体文件，readdir函数同样也读取目录下的文件。 */
	char *filename       = NULL;

	//打开文件失败
	if(NULL == (pdir = opendir("."))){	/* 如果打开失败函数说明：opendir()用来打开参数name 指定的目录, 并返回DIR*形态的目录流, 接下来对目录的读取和搜索都要使用此返回值. */
		exit(-1);
	}
	else{
		while (NULL != (pdent = readdir(pdir))) {/* readdir()返回参数dir 目录流的下个目录进入点。返回值：成功则返回下个目录进入点. 有错误发生或读取到目录文件尾则返回NULL. */
			if(pdent->d_ino == ino){
				filename = strdup(pdent->d_name);
				break;
			}
		}	

		/* closedir(DIR *dir)关闭参数dir 所指的目录流。返回值：关闭成功则返回0,，失败返回-1, */
		closedir(pdir);					
	}
	return filename;
}
