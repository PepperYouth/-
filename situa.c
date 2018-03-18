#include <stdio.h>
#include <string.h>
#include "1.h"
extern situa all_situa[NUM_SITUA];
int load_situa() {
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp, "situa.txt", "r");
	for (int i = 0; i < NUM_SITUA; ++i) {
		fscanf(fp, "%s %d", all_situa[i].name,&all_situa[i].score);
	}
	fclose(fp);
	return 0;
}