#include <stdio.h>

int main (void) {

	int hundred = 0;
	int fifty = 0;
	int twenty = 0;
	int ten = 0;
	int five = 0;
	int one = 0;     

	int userInput; 
	printf("Please enter the amount of money you wish to withdraw: ");
	scanf("%d", &userInput);
	printf("\n");

	while ( userInput != 0) {
		while ( userInput >= 100 )  {
			hundred = userInput / 100; 
			userInput -= 100 * hundred;
		} 
		while (userInput >= 50) { 
			fifty = userInput / 50;
			userInput -= 50 * fifty;
		} 
		while (userInput >= 20) {
			twenty = userInput / 20;
			userInput -= 20 * twenty;
		}
		while (userInput >= 10) {
			ten = userInput / 10;
			userInput -= 10 * ten;
		} 
		while (userInput >= 5) {
			five = userInput / 5;
			userInput -= 5 * five;
		}
		while (userInput >= 1) {
			one = userInput;
			userInput -= one;
		}
	}
	printf("You received %d hundred(s)\n\n", hundred);
	printf("You received %d fifty(s)\n\n", fifty);
	printf("You received %d twenty(s)\n\n", twenty);
	printf("You received %d ten(s)\n\n", ten);
	printf("You received %d five(s)\n\n", five);
	printf("You received %d one(s)\n", one);

	return 0;
}
	 