#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_EGG 1000000
#define MAX_STORY 1000000

int test[MAX_EGG][MAX_STORY] = { 0, };

int drop_egg_main (int egg, int story);
int drop_egg (int egg, int story, int depth);
int max (int n1, int n2);

int main(int argc, char* argv[]) {

	if (argc < 3) {
		//printf("%s {egg} {story}\n", argv[0]);
		return -1;
	}

	int egg = atoi(argv[1]);
	int story = atoi(argv[2]);

	time_t tStart, tFinish;

	tStart = clock();
	printf ("        ... Drop Eggs (%d, %d) = %d \n", egg, story, drop_egg_main(egg, story));
	tFinish = clock();

	printf ("        ... duration: %lf (ms) \n", (float)(tFinish - tStart)/CLOCKS_PER_SEC*1000);
	return 0;
}

int drop_egg_main (int egg, int story) {
	return drop_egg(egg, story, 0);
}

int drop_egg (int egg, int story, int depth) {

	if (story == 1 || story == 0) {
		return story;
	}

	if (egg == 1) {
		//printf("      - Only one egg remains. Return story %d \n", story);
		return story;
	}

	if (egg > 1) {

		// calculate it if this case has not been calculated previously
		if (test[egg][story] == 0) {
			//printf("(%d) Trying %d-egg, %d-story -> drop at %d \n", depth, egg, story, (int)(story/2.0));

			//case1. egg is broken at (story/2)
			int doesBreak = drop_egg(egg-1, (int)(story/2.0)-1, depth+1);

			//case2. egg is NOT broken at (story/2)
			int doesNotBreak = drop_egg(egg, (int)(story/2.0), depth+1);

			test[egg][story] = 1 + max(doesBreak, doesNotBreak);
			//printf("    > update test[%d][%d] = %d \n", egg, story, test[egg][story]);
	
		} else {
			//printf("    > reuse test[%d][%d] = %d \n", egg, story, test[egg][story]);
		}

		return test[egg][story];
	}

	return 0;
}

int max (int n1, int n2) {
	return (n1>n2)? n1 : n2;
}
