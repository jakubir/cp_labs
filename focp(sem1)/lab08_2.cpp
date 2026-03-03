#include <time.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


//7. Use C++ ifstream / ofstream(the fstream library) :
	//Write a definition of a function copyFile that creates an exact copy of a source file.The names of the source and destination files are function parameters.The function should return true if the operation was successful, and false otherwise.Example function prototype :

bool copyFile(const char* source, const char* dest)
{
    const int BUFFER_SIZE = 1024;
    size_t count;
    char buffer[BUFFER_SIZE];

    ifstream src_file(source, ios::binary);
    if (!src_file.is_open())
    {
        cout << "Error" << endl;
        return false;
    }
    ofstream out_file(dest, ios::binary);
    if (!out_file.is_open())
    {
        cout << "Error" << endl;
        return false;
    }

    while (src_file.read(buffer, BUFFER_SIZE))
        out_file.write(buffer, src_file.gcount());
    
    out_file.write(buffer, src_file.gcount());

    src_file.close();
    out_file.close();

    return true;
}

//Call this function for some existing file(e.g.a JPG image) with the name of the destination file different, but with the same extension.Check the copied file e.g.by opening it in a browser.

int main(int argc, char *argv[])
{
	//5. Use C++ ifstream / ofstream(the fstream library) :
	//	Open(create) a text file called �numbers.txt�.Write 100 random integers to that file.Close the file.

	srand(time(NULL));

    fstream file("numbers.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++)
    {
        file << (rand()%100) << endl;
    }

    file.close();

    //	6. Use C++ ifstream / ofstream(the fstream library) :
    //	This program should be run with the following command - line arguments :
    //numbers.txt result.txt result.bin
    //Open an existing text file with numbers(its name : first command - line argument) and :
    //	a) print all numbers to the screen,
    //	b) calculate mean and minimum of all read numbers,
    //	c) calculated values(mean and minimum) should be stored :
    //      -as a text in a new file(its name : second command - line argument),
    //      -as a memory block in a new file(its name : third command - line argument),
    //  d) calculate and display the sizes of files created in c), hint: use ftell,
    //  e) close all files.

    ifstream num_file(argv[1]);

    if (!num_file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    int num, count = 0, sum = 0, min = __INT_MAX__, mean;

    while (num_file >> num)
    {
        count ++;
        sum += num;
        if (num < min)
            min = num;

        cout << num << endl;
    }

    mean = sum / count;

    num_file.close();

    ofstream res_file(argv[2]);

    if (!res_file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    res_file << "Mean: " << mean << " min: " << min; 

    cout << "Text file size: " << res_file.tellp() << " bytes" << endl;

    res_file.close();

    ofstream bin_file(argv[3], ios::binary);

    if (!bin_file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    bin_file.write((const char*)&mean, sizeof(int));
    bin_file.write((const char*)&min, sizeof(int));

    cout << "Binary file size: " << bin_file.tellp() << " bytes" << endl;

    bin_file.close();

    copyFile("focp-Lab08-tasks.txt", "copy_of_focp-Lab08-tasks.txt");

	return 0;
}