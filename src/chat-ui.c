/*
时间: 2018.09.26
环境: ubuntu
描述: Linux 字符菜单设计
参考链接: https://blog.csdn.net/aiwangtingyun/article/details/79654242
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
		
	system("clear");
	printf("\033[?25l");	//隐藏光标
	system("stty -icanon");	//关闭缓冲
	system("stty -echo");	//关闭回显
	
	printf("欢迎！\n");		//1
	printf("****1 \n");	//2
	printf("    2 \n");	//3
	printf("    3 \n");	//4
	printf("    4 \n");	//5
	printf("    5 \n");	//6
	
	

	
	int line = 2;		//记录行数，默认起始行
	char ch = 0;
	
	while ((ch = getchar()) != 27)
	{
		printf("\033[10;20H");	//指定位置显示按键值
		printf("ch = %c\n",ch);
		
		switch (ch)
		{
			case 'w': line--;	printf("\033[%d;1H", line + 1);
									printf("    \n");
									if (line == 1) line = 6;
									printf("\033[%d;1H", line);
									printf("***\n"); 			break;
									
			case 's': line++;	printf("\033[%d;1H", line - 1);
									printf("    \n");
									if (line == 7) line = 2;
									printf("\033[%d;1H", line);
									printf("***\n"); 			break;

			
			default: break;
		}
		
		
	}

	return 0;
}
