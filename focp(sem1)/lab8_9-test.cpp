/* GROUP B
Write a C program that truncates a file called "this.bin" to 1024 bytes.
- Open the file, check if it was opened.
- Use a buffer in memory to store the initial 1024 bytes of the file (or whole file, if it is less than 1024 bytes).
- Read data using fread.
- Close the file and recreate it (open for writing) using the same name and writing only 1024
bytes or less, if the original file was shorter.
- Do not enlarge short files.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE* file = fopen("this.bin", "rb");

	if (!file)
	{
		printf("File opening error");
		return 1;
	}

	char buffer[1024] = {""};
	size_t count;

	count = fread(buffer, 1, 1024, file);

	fclose(file);

	file = fopen("this.bin", "wb");

	fwrite(buffer, 1, count, file);

	fclose(file);

	return 0;
}

/* GROUP B
 Complete the code below. Use fstream and iostream libraries (C++) to:
 - create text file result.txt,
 - create binary file result.bin,
 - check if the files were opened correctly,
 - write sum of integers c and d to "result.txt" (text format),
 - write sum of integers c and d to "result.bin" (binary format),
 - close the files.


#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int c = 55532;
    int d = 1124;
    int sum = c + d;

    ofstream file_t("result.txt");
    ofstream file_b("result.bin", ios::binary);

    if (!file_t.is_open() || !file_b.is_open())
    {
        cout << "File opening error" << endl;
        return 1;
    }

    file_t << sum;
    file_b.write((const char*)&sum, sizeof(int));

    file_t.close();
    file_b.close();
    
    return 0;
}
 */
