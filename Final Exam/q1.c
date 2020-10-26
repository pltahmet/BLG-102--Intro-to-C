#include <stdio.h>
//You cannot use the string library 

#define MAX_STRING_SIZE 20


void append(char* a, char* b)
{
	int len_a = 0, len_b = 0;
	int i = 0, j = 0, k= 0;

	while(b[j] != '\0'){
		len_b++;
		j++;
	}

	while(a[k] != '\0'){
		len_a++;
		k++;
	}

	if(len_a + len_b >= 19){
		printf("Error");
	}
	else{
		a[len_a] = ' ';
		for(i = 1; i <= len_b; i++){
			a[len_a + i] = b[i - 1];
		}
		a[len_a + i] = '\0';
		printf("%s",a);
	}


  //fill the function body. Do not change the arguments and the return parameter
	return;
}

int main()
{
	char a[MAX_STRING_SIZE];
	char b[MAX_STRING_SIZE];
	scanf("%s",a);
	scanf("%s",b);
	append(a,b);
	return 0;
}
