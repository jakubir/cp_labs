#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Task 4.
//Write a definition of a function copyFile that creates an exact copy of a source file.The names of the source and destination files are function parameters.The function should return true if the operation was successful, and false otherwise.Example function prototype :

//bool copyFile(const char* source, const char* dest);

//Call this function for some existing file(e.g.a JPG image) with the name of the destination file different, but with the same extension.Check the copied file e.g.by opening it in a browser.
#define BUFFER_SIZE 1024

bool copyFile(const char* source, const char* dest)
{
	size_t count;
	char buffer[BUFFER_SIZE];

	FILE* src_file = fopen(source, "rb");

	if (!src_file)
	{
		printf("Error");

		return 0;
	}

	FILE* out_file = fopen(dest, "wb");

	if (!out_file)
	{
		printf("Error");

		return 0;
	}

	while ((count = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0)
		fwrite(buffer, 1, count, out_file);

	fclose(src_file);
	fclose(out_file);

	return 1;
}

int main(int argc, char* argv[])
{
	//Task 1.
	//Display all command - line arguments of the program.Run the program with different arguments from the command line.

	for (int i = 0; i < argc; i++)
		printf("%d. %s\n", i+1, argv[i]);

	//Task 2.
	//Open(create) a text file named "numbers.txt".Write 10, 000 random integers in the range[0, 1000] to the file.Then close the file.

	FILE *file = fopen("numbers.txt", "w");

	if (!file)
	{
		printf("Error");

		return 0;
	}

	srand(time(NULL));

	for (int i = 0; i < 10000; i++)
		fprintf(file, "%d\n", rand() % 1000);


	//Task 3.
	//The program should be run with three file names as command - line arguments, for example:
	//numbers.txt result.txt result.bin

	//Open an existing text file with numbers(its name is the first command - line argument) and :
	//a) print all numbers to the screen,
	//b) calculate mean and minimum of all read numbers,
	//c) store the calculated values(mean and minimum) in two ways :
	//-as a text in a new file(its name : second command - line argument),
	//-as a memory block in a new file(its name : third command - line argument),
	//d) calculate and display the sizes of files created in c), hint: use ftell,
	//e) close all files.

	if (argc < 4)
	{
		printf("Too few arguments");

		return 0;
	}

	const char* numbers_file_name = argv[1];
	const char* result_text_file_name = argv[2];
	const char* result_bin_file_name = argv[3];

	FILE* file = fopen(numbers_file_name, "r");

	if (!file)
	{
		printf("File opening error");

		return 0;
	}

	int num = 0, count = 0, min = INT_MAX, sum = 0, mean;

	while (fscanf(file, "%d", &num) != EOF)
	{
		printf("%d\t", num);
		count++;
		sum += num;
		
		if (num < min)
			min = num;
	}

	fclose(file);

	mean = sum / count;

	file = fopen(result_text_file_name, "w");

	if (!file)
	{
		printf("File opening error");

		return 0;
	}

	fprintf(file, "Mininum: %d Mean: %d", min, mean);

	fclose(file);

	file = fopen(result_bin_file_name, "wb");

	if (!file)
	{
		printf("File opening error");

		return 0;
	}

	fwrite(&min, sizeof(int), 1, file);
	fwrite(&mean, sizeof(int), 1, file);

	fclose(file);

	return 0;

}
