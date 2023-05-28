#include <stdio.h>

int FA(int input);

int main() {
	int input;
	scanf_s("%d", &input);

	for (int i = 0; i < 10; i++) {
		if(FA(input) == (FA(input)%10)) {
			printf("FA");
			return 0;
		}
		else if(FA(input)%1 > 0){
			printf("NFA");
			return 0;
		}
	}
}

int FA(int input) {
	int count = 0;
	while (input != 0) {
		input = input / 10;
		++count;
	}
	return (input * count);
}