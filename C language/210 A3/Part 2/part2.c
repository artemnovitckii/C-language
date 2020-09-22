#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *file;
	file = fopen(argv[1], "r");
	char arr[100][50];
	int i = 0;
	while (1){
		char r = (char)fgetc(file);
		int k = 0;
		while(!feof(file)){
			arr[i][k++] = r;
			r = (char)fgetc(file)
		}
		arr[i][k]=0;
		if(feof(file)){
			break;
		}
		i++;
	}
	int j;
	for(j=0; j<=i,j++){
		printf("%s\n",arr[j]);
		
	}
	return 0;
}


	