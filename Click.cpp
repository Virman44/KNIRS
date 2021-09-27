#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <math.h>
#include <iostream>

int main(void) {
	char pass;
	int j = 0;
	long double max = LDBL_MIN;
	long double compare = 0.0;
	char openfile[255];
	char supportopen[] = "n12_0.01_des.plt";
	strncpy(openfile, supportopen, 17);
	FILE* data = NULL;

	data = fopen(openfile, "r");
    if (data == NULL) {
        printf("Error opening file");
        exit(0);
    }
	
		while (j != 1) {
			do {
				if (((pass = fgetc(data)) != '{') && (j == 0)) {
					j++;
					continue;
				}
			} while ((pass = fgetc(data)) != '{');
		}

		while (!feof(data)) {
			for (int i = 0; i < 2; i++) {
				for (int i1 = 0; i1 < 7; i1++) {
					fscanf(data, "%*lf");
				}

				fscanf(data, "%lf", &compare);
				if (max < compare) {
					max = compare;
				}
			}
			fscanf(data, "%*lf");
			if ((pass = fgetc(data)) == '}') {
				break;
			}
		}

	printf("%1.14e", max);
	fclose(data);
}