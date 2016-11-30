#include <stdio.h>
#include <time.h>

int drop_egg (int egg, int story);
int max (int n1, int n2);

int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("%s {egg} {story}\n", argv[0]);
		return -1;
	}

	int egg = atoi(argv[1]);
	int story = atoi(argv[2]);

	time_t tStart, tFinish;

	tStart = clock();
	printf ("        ... Drop Eggs (%d, %d) = %d \n", egg, story, drop_egg(egg, story));
	tFinish = clock();

	printf ("        ... duration: %lf (ms) \n", (float)(tFinish - tStart)/CLOCKS_PER_SEC*1000);
	return 0;
}

int drop_egg (int egg, int story) {

	if (story < 1)
		return 0;

	if (egg == 1)
		return story;

	if (egg > 1) {
		return 1 + max(
				//case1. egg is broken at (story/2)
				drop_egg(egg-1, (int)(story/2.0)-1),
				//case2. egg is NOT broken at (story/2)
				drop_egg(egg, (int)(story/2.0))
				);
	}

	return 0;
}

int max (int n1, int n2) {
	return (n1>n2)? n1 : n2;
}
