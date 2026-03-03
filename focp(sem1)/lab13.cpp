/*
1. Write a function counting the number of words in a text passed as the argument to the function (the type of the argument should be char *). Assume, that a word is a sequence of characters without spaces, separated by one or more spaces. For example, the text "The quick    brown  fox  " contains four words.

2. Write a function checking, whether one text is an anagram of another. For example, "silent" and "listen" are anagrams.

3. There is a sentence: "Please bring me some tea and coffee". Create a copy of it with the word "and" replaced with "or". Use the following functions: strlen, strstr, strcpy (strncpy), strcat.

4. There is a sentence: "Panda. Large black-and-white bear-like mammal, native to China. Eats, shoots and leaves.". Create a copy of it with the last comma removed. Use the following functions: strlen, strrchr, strcpy (strncpy).

5. Write a program reading three words (up to 99 characters) and printing them in lexicographical order. Use function strcmp.

6. Re-write the solutions of C-style strings tasks (tasks 1-5) to use C++ strings.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

int word_counter(char* txt)
{
	char ch;
	int count = 0;
	bool last_space = true;

	while ((ch = *txt) != '\0')
	{
		if (ch == ' ')
		{
			if (!last_space)
				count++;

			last_space = true;
		}
		else
			last_space = false;

		txt++;
	}

	return count;
}

bool is_anagram(char* txt, char* txt2)
{
	if (strlen(txt) != strlen(txt2))
		return false;

	txt2 += strlen(txt2) - 1;

	while (*txt != '\0')
	{
		if (*txt != *txt2)
			return false;

		txt++;
		txt2--;
	}

	return true;
}

int main()
{
	char txt[] = "  The quick    brown  fox  ";
	std::cout << "Sentence: " << txt << " has " << word_counter(txt) << "\n";

	char text[] = { 'd', 'o', 'g', '\0'};
	char text2[] = "god";

	std::cout << text2 << " and " << text << (is_anagram(text2, text) ? " are anagrams" :  " aren't anagrams") << "\n";

	//3. There is a sentence: "Please bring me some tea and coffee". Create a copy of it with the word "and" replaced with "or". Use the following functions: strlen, strstr, strcpy (strncpy), strcat.

	const char* sentence = "Please bring me some tea and coffee";
	const char* last_part = strstr(sentence, "and");
	char* result = new char[strlen(sentence) - 1];
	int length = strlen(sentence) - strlen(last_part);
	strncpy(result, sentence, length);
	result[length] = '\0';
	strcat(result, "or");
	strcat(result, (last_part + 3));

	//4. There is a sentence: "Panda. Large black-and-white bear-like mammal, native to China. Eats, shoots and leaves.". Create a copy of it with the last comma removed. Use the following functions: strlen, strrchr, strcpy (strncpy).

	const char* sentence2 = "Panda. Large black-and-white bear-like mammal, native to China. Eats, shoots and leaves.";
	const char* last_part2 = strrchr(sentence2, ',');
	char* result2 = new char[strlen(sentence2) - 1];
	int length2 = strlen(sentence2) - strlen(last_part2);
	strncpy(result2, sentence2, length2);
	result2[length2] = '\0';
	strcat(result2, (last_part2 + 1));

	return 0;
}