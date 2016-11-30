#include <stdio.h>

#define MAX_EGG 1000000
#define MAX_STORY 1000000

int trial[MAX_EGG][MAX_STORY] = { 0, };

int drop_egg (int egg, int story);
int max (int n1, int n2);

int main(int argc, char* argv[]) {

	printf("%d \n", trial[0][1]);
	printf ("%d \n", drop_egg(10,10001));

	return 0;
}

int drop_egg (int egg, int story) {

	if (story < 1)
		return 0;

	if (egg == 1)
		return story;

	if (egg > 1) {
		if (trial[egg][story] == 0) {

			//case1. egg is broken at (story/2)
			int doesBreak = drop_egg(egg-1, (int)(story/2.0)-1);

			//case2. egg is NOT broken at (story/2)
			int doesNotBreak = drop_egg(egg, (int)(story/2.0));

			trial[egg][story] = 1 + max(doesBreak, doesNotBreak);
			printf("update trial[%d][%d] = %d \n", egg, story, trial[egg][story]);
	
		} else {
			printf("use existed trial[%d][%d] = %d \n", egg, story, trial[egg][story]);
		}

		return trial[egg][story];
	}

	return 0;
}

int max (int n1, int n2) {
	return (n1>n2)? n1 : n2;
}
