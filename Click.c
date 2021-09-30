#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <math.h>
#include <iostream>
#include<cfloat>

int main(void) {
	char pass;
	int j = 0;
	double max = DBL_MIN;
	double compare = 0.0;
	char openfile[] = "n12_0.01_des.plt";
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
					fscanf(data, "%*f");
				}

				fscanf(data, "%lf", &compare);
				if (max < compare) {
					max = compare;
				}
			}
			fscanf(data, "%*f");
			if ((pass = fgetc(data)) == '}') {
				break;
			}
		}

	printf("%1.14e", max);
	fclose(data);
}
