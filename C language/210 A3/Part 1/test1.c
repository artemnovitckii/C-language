#include <studio.h>

int main(int argc, char **argv){
	FILE *file;
	char lines[45];
	file = fopen(argv[1],"r");
	while (fgets (lines, 4, file) != NULL){
		
		printf("Line is %d", lines);
	}
	
	fclose(file);
	return 0;
}
	