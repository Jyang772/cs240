/*
 *  stubs for functions to study
 *  integer-hex conversions
 *
 */

#include <stdio.h>
#include "xbits.h"
#include <string.h>
#include <math.h>

/* function represents the int n as a hexstring which it places in the
hexstring array */

void itox( char hexstring[], int n) {
 	printf("in itox, processing %d\n",n);
	int remainder, i = 0;
	
	while(n > 0)
	{
		remainder = n % 16;
		n /= 16;
			switch(remainder)
			{
				case 10: hexstring[i] = 'A';
					 break;
				case 11: hexstring[i] = 'B';
					 break;
				case 12: hexstring[i] = 'C';
					 break;
				case 13: hexstring[i] = 'D';
					 break;
				case 14: hexstring[i] = 'E';
					 break;
				case 15: hexstring[i] = 'F';
					 break;
				default: hexstring[i] = remainder + '0';
				
			}	
		i++;	
	}
	
	hexstring[i] = '\0';
	int j;
	char temp;
	int len = strlen(hexstring) - 1;
	for(j = 0; j <= len/2; j++){
		temp = hexstring[j];
		hexstring[j] = hexstring[len-j];
		hexstring[len - j] = temp;		
	}

}

/* function converts hexstring array to equivalent integer value  */

int xtoi( char hexstring[]) {
  printf("in xtoi, processing %s\n", hexstring);
	
	int i, k, length;
	int sum = 0;
	length = strlen(hexstring);
	for(i=length-1,k=0;i>=0;i--,k++)
	{
		switch(hexstring[i]) {
			case 'A': sum += 10 * pow(16,k); break;
			case 'B': sum += 11 * pow(16,k); break;
			case 'C': sum += 12 * pow(16,k); break;
			case 'D': sum += 13 * pow(16,k); break;
			case 'E': sum += 14 * pow(16,k); break;
			case 'F': sum += 15 * pow(16,k); break;
			default : sum += (hexstring[i] - '0') * pow(16,k);
		}
	}
	return sum; 
}
/* Testing purposes
int main()
{
	char hexstring[2*sizeof(int)+1];
	int c;
	scanf("%d",&c);
	itox(hexstring,c);
	printf("%s\n",hexstring);
	
	c = xtoi(hexstring);
	printf("%d\n",c);
	return 0;
}
*/
