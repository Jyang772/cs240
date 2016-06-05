#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STOP 0x00
#define ML_UP 0x01
#define ML_DOWN 0x02


struct f{
	unsigned int d : 8;
	unsigned int c : 24;
	struct f* s;
	struct f* g;
	int (*speak)(int, int);
} penguin;

int speak1(int a, int b) {

	printf("This is speak1\n");
	return 0;
}

int speak2(int a, int b) { 
	printf("This is speak2\n");
	return 0;
}


int main()
{
	//printf("%lu\n",sizeof(struct f));
	struct f penguin = {
		.speak = speak2
	};

	struct data {
		int a;
		char s[10];
	};
	
	struct data data[2] = {{10,"hello"}, {11,"penguin"}};

	int output_fd;
	ssize_t ret_out;
	
	output_fd = open("t.dat", O_WRONLY | O_CREAT, 0644);
	
	ret_out = write(output_fd,&data[0],sizeof(data));
	
	close(output_fd);
	
	output_fd = open("t.dat", O_RDONLY,0644);
	
	struct data test;
	while((ret_out = read(output_fd,&test,sizeof(data[0]))) > 0);
	
	printf("test_s: %s\n",test.s);
	printf("size of data: %d\n",sizeof(data[0]));
	return 0;
}
