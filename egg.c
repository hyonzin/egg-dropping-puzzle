#include <stdio.h>

int drop_egg (int egg, int story);
int max (int n1, int n2);

int main(int argc, char* argv[]) {

	printf ("%d \n", drop_egg(3,2));

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
				drop_egg(egg-1, (int)(story/2.0+0.5)-1),
				//case2. egg is NOT broken at (story/2)
				drop_egg(egg, (int)(story/2.0))
				);
	}

	return 0;
}

int max (int n1, int n2) {
	return (n1>n2)? n1 : n2;
}
