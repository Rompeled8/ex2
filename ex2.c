/******************
Name:Rom Peled
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice;
	do {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1: { //Happy Face
				char eyes, nose, mouth;
				int size;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				scanf("%*[^\n]");
				printf("Enter face size:\n");
				while (1) { //Repeat until valid number is entered
					scanf("%d", &size);
					if (size > 0 && size % 2 != 0) { //Check face size to be odd and positive
						break;
					} else {
						printf("The face's size must be an odd and positive number, please try again:\n");
					}
				}
				int nosespace = (size + 1) / 2;
				printf("%c", eyes);
				for (int i = 0; i < size; i++) {
					printf(" ");
				}
				printf("%c\n", eyes);
				for (int i = 0; i < nosespace; i++) {
					printf(" ");
				}
				printf("%c", nose);
				for (int i = 0; i < nosespace - 1; i++) {
					printf(" ");
				}
				printf("\n\\");
				for (int i = 0; i < size; i++) {
					printf("%c", mouth);
				}
				printf("/\n");

				break;
			}


			case 2: { //Balanced Number
				int num;
				printf("Enter a number:\n");
				while(1) {
					scanf("%d" , &num);
					if (num > 0) {
						break;
					}
					else {
						printf("Only positive number is allowed, please try again:\n");
					}
				}
				int digits[10];
				int temp= num;
				int numdigits = 0;
				while(temp > 0) {
					digits[numdigits] = temp % 10; //extract the last digit and stores in array
					temp = temp/10; //removes the last digit
					numdigits++;
				}
				int sumr=0, suml=0;
				int mid = numdigits / 2; //index to split the number
				for (int i = 0; i < mid ; i++) {
					suml += digits[i];  //sum the left part of the number
				}
				for(int i = numdigits -1; i >= mid + (numdigits % 2); i--) {
					sumr += digits[i];
				}
				if(suml == sumr) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}




			case 3: {  //Generous Number
				int number;
				printf("Enter a number:\n");
				while(1) {
					scanf("%d" , &number);
					if (number > 0) {
						break;
					} else {
						printf("Only positive number is allowed, please try again:\n");
					}
				}
				int sumofdiv = 0;
				for(int i = 1; i <= number/2; i++) {
					if(number % i == 0) {
						sumofdiv += i;
					}
				}
				if(sumofdiv > number) {
					printf("This number is generous!\n");
				}
				else {
					printf("This number does not share.\n");
				}
				break;
			}


			case 4: {   //Circle Of Joy
				int Num;
				printf("Enter a number:\n");
				while(1) {
					scanf("%d" , &Num);
					if (Num > 0) {
						break;
					} else {
						printf("Only positive number is allowed, please try again:\n");
					}
				}
				if (Num == 1) {
					printf("The circle remains incomplete.\n");
					break;  // Exit early as 1 is not prime
				}
				int prime=1;
				for(int i = 2; i < Num; i++) {
					if(Num % i == 0) {
						prime = 0;
						break;
					}
				}
				int remainder, reversed=0;
				while(Num != 0) {
					remainder = Num % 10; //extract the last digit
					reversed = reversed * 10 + remainder;  // Build the reversed number
					Num = Num / 10;  //remove the last digit
				}
				for(int i = 2; i < reversed; i++) {
					if(reversed % i == 0) {
						prime = 0;
						break;
					}
				}
				if(prime == 1) {
					printf("This number completes the circle of joy!\n");
				} else {
					printf("The circle remains incomplete.\n");
				}

				break;
			}


			case 5: { //Happy numbers
				int NUM;
				printf("Enter a number:\n");
				while(1) {
					scanf("%d" , &NUM);
					if (NUM > 0) {
						break;
					} else {
						printf("Only positive number is allowed, please try again:\n");
					}
				}
				printf("Between 1 and %d only these numbers bring happiness: ", NUM);

				for (int i = 1; i <= NUM; i++) {
					int num = i;
					int seen[1000] = {0}; // Array to track numbers we've seen
					while (num != 1) {
						int sum = 0;
						int temp = num;
						while (temp > 0) { // Calculate the sum of squares of digits
							int digit = temp % 10;  // Get the last digit
							sum += digit * digit;  // Add the square of the digit
							temp /= 10;  // Remove the last digit
						}

						num = sum;   // Update the number to the sum of squares

						if (seen[num]) {
							break;  // Seen number detected, not a happy number
						}
						seen[num] = 1;  // Mark this number as seen
					}

					//
					if (num == 1) {
						printf("%d ", i);
					}
				}
				printf("\n");
				break;
			}

			case 6: {  // Festival of Laughter:
				int smileNumber, cheerNumber, n;
				printf("Enter a smile and cheer number:\n");
				while (1) {
					int check = scanf(" smile: %d, cheer: %d", &smileNumber, &cheerNumber);

					if (check == 2) { // Both numbers read successfully
						if (smileNumber > 0 && cheerNumber > 0 && smileNumber != cheerNumber) {
							break; // Valid input - exit the loop
					} else {
						printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					}
				} else {
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					scanf("%*[^\n]");
					scanf("%*c");
				}
			}
				printf("Enter maximum number for the festival:\n");
				while (1) {
					if (scanf("%d", &n) == 1 && n > 0) {
						break;
					} else {
						printf("Only positive maximum number is allowed, please try again:\n");
						scanf("%*[^ \n]");
        }
    }
				for (int i = 1; i <= n; i++) {
					if (i % smileNumber == 0 && i % cheerNumber == 0) {
						printf("Festival!\n");
				} else if (i % smileNumber == 0) {
					printf("Smile!\n");
				} else if (i % cheerNumber == 0) {
					printf("Cheer!\n");
				} else {
					printf("%d\n", i);
        }
    }

					break;
}
			case 7: { //Exit
				printf("Thank you for your journey through Numeria!\n");
				break;
			}
			default: {
				// Handle invalid choices
				printf("This option is not available, please try again.\n");
				break;
			}
		}
	} while (choice != 7); //Keep presenting menu until exit
}

