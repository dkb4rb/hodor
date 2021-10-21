#include "hash.h"
#define LIMIT "|   "
#define LIMIT_2 "   |"

int Table(void){
	int size = 4, i = 0;
	char *Datos[4];

	Datos[0] = "ID";
	Datos[1] = "USR";
	Datos[2] = "PASSWD";
	Datos[3] = "HASH";

	for(i = 0;i < size;i++){
	printf(LIMIT);
	printf("%s",Datos[i]);
	printf(LIMIT_2);
	}
	return(0);
}



int main(int argc, char **argv){

	unsigned long int index = 0;

	int rslt = 0, rslt2 = 0, rslt3 = 0, result = 0, size;
	
	if(argc < 2){
		printf("Usage: %s <HASH> <SIZE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while(argv[1][index] != '\0' ){
	rslt += argv[1][index];
	printf("%i",argv[1][index++]);
	rslt3 = argv[1][index - 1];
	putchar('\n');
	}

	size = strlen(argv[1]);
	rslt2 = argv[1][0];
	result = rslt2 + rslt3;


	printf("\nSize Text: %i", size);
	printf("\nResult Sum All Strin in Char: %i", rslt);
	printf("\nResult Total: %i", result);

	putchar('\n');
	putchar('\n');
	Table();
	putchar('\n');

	return(EXIT_SUCCESS);
}


