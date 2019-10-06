#include <stdio.h>
#include <stdlib.h>
/*
Simple encryption program that encrypts a given message by moving each character in the message by a given shift amount
*/

#define max 80 // maximum input

int main(void)
{
	char text[max] = {}; //message converted to array
	char input; //to store every character in array

	int i, shift;
 
	printf("Enter your message: ");

	for (i = 0; (input = getchar()) != '\n'; i++)
	{
	
		if (i >= max) { // message size checker
			printf("Maximum Text input is 80");
			exit(0);
		} else {
				text[i] = input; // put char in array text
		}

	}

	printf("Enter your desired shift amount (1-25):");
	scanf("%d", &shift);

	if (shift <= 0 || shift >= 26) { // make sure to have a correct shift amount
		printf("Incorrect shift amount.");
		exit(0);
	}

	for (i = 0; i < max; i++)
	{

		if (text[i] >= 'a' && text[i] <= 'z') //shift small letters
		{
			text[i] = (text[i] - 'a') + shift;
			text[i] = text[i] % 26 + 'a';
		}

		if (text[i] >= 'A' && text[i] <= 'Z') //shift capital letters
		{
			text[i] = (text[i] - 'A') + shift;
			text[i]= text[i]% 26 + 'A';
		}

		if (text[i] == 0){ //message is finished
			break;
		}
		
	}

	printf("Your encrypted message: ");

	for (i = 0; i < max; i++) // print result
	{
		if (text[i] == 0){
			break;
		}
		putchar(text[i]);
	}
	printf("\n");

	return 0;

}
