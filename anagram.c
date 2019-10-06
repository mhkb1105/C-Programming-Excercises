/*
Checks if two strings contain the same exact letters
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char input;
	int i,flag = 0;
	int text[26] = {0};

	printf("Please enter your first word: ");


	for (i = 0; (input = getchar()) != '\n'; i++) {
		input = toupper(input); //make every character upper
		if (isalpha(input) != 0){ // make sure it is a letter
			text[input - 'a']++;
		}
}
	printf("Please enter your second word: ");

	
	for (i = 0; (input = getchar()) != '\n'; i++)
	{
		input = toupper(input);
		if (isalpha(input) != 0)
		text[input - 'a']--;
	}

	for (i = 0; i < 6; i++)
	{
		if (text[i] != 0) 
		{
			flag = 1;
			break;
			
		}
	}
	if (flag == 1) {
		printf("The words are not anagrams.\n");
	} else {
			printf("The words are anagrams.\n");
	}
	return 0;
}

