#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cfloat>

int main(void) {
	char pass;
	char openfile[10][10] = { "file1", "file2", "file3", "file4", "file5", "file6", "file7", "file8", "file9", "file10"};

	int system(const char* command);

	system("scp username@ip:/path/to/file1 .");
	system("scp username@ip:/path/to/file2 .");
	system("scp username@ip:/path/to/file3 .");
	system("scp username@ip:/path/to/file4 .");
	system("scp username@ip:/path/to/file5 .");
	system("scp username@ip:/path/to/file6 .");
	system("scp username@ip:/path/to/file7 .");
	system("scp username@ip:/path/to/file8 .");
	system("scp username@ip:/path/to/file9 .");
	system("scp username@ip:/path/to/file10 .");

	for (int a = 0; a < 10; a++) {
		int j = 0;
		double max = DBL_MIN;
		double compare = 0.0;

		FILE* data = NULL;

		data = fopen(openfile[a], "r");
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

		printf("Total current for %s = %1.14e", openfile[a], max);
		fclose(data);
	}
}
