#include <stdio.h>


//int nmc(char *, char *);
int nmc(void*,void*);
int (*pNMC)(void*,void*);

void sort(int(*comp)(void *,void *))
{
	if((*comp)("c","c"))
		printf("true!\n");
	else
		printf("false!\n");
}

int nmc(void *c, void *d)
{
	if(*(char*)c == *(char*)d)
		return 1;
	else
		return 0;
}

struct Penguin
{
	int (*pNMC)(void*,void*);
};


struct Penguin test = {
	.pNMC = nmc
};

int main()
{
	//casting function pointer arguments	
	//sort((int (*)(void*,void*))nmc);
	pNMC = &nmc;
	void* p2 = (void*)pNMC; //Could fail! Language does not require functions and data to be in the same address space.
	
	//sort((int (*)(void*,void*))p2);

	sort(test.pNMC);
	return 0;
}
