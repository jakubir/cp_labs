/*1. Write a template of a function "smaller" comparing two elements and
returning the smaller one.Test it with different types(see "Lectures->Part 10")

2. Use the vector template from STL to create an array(vector) o integers.Insert a
few elements to the vector.Print all elements to the screeen.

3 Use the list template from STL to create a list o integers.Insert a
few elements to the list.Use an iterator to walk over all elements of the
list and print them to the screen.

4. Use code from previous lab to :
a) Create a singly - linked list with all numbers from the list from task, where single element type is :
struct element {
    int x;
    element* next;
};
c) display all elements from the list.
d) delete the list(free the memory).
*/

//#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
T smaller(T a, T b)
{
    return a < b ? a : b;
}

int main()
{
    char a = 100, b = 97;

    std::cout << "Out of " << a << " and " << b << " smaller is " << smaller(a, b) << "\n";


    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(0);
    vec.push_back(-44);
    vec.push_back(13);
    vec.push_back(56);

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << "\t";

    std::cout << "\n";

    for (int el : vec)
        std::cout << el << "\t";

    std::cout << "\n";


    std::list<int> list;

    list.push_back(100);
    list.push_back(0);
    list.push_back(-440);
    list.push_back(130);
    list.push_back(560);

    for (auto it = list.begin(); it != list.end(); it++)
        std::cout << *it << "\t";

    std::cout << "\n";


    struct element {
        int x;
        element* next;
    };

    element* head = nullptr, * tmp, *last = nullptr;

    int arr[] = {1000, 0, -4400, 1300, 5600};

    for (int i = 0; i < 5; i++)
    {
        tmp = new element;

        tmp->x = arr[i];
        tmp->next = nullptr;

        if (last == nullptr)
            head = last = tmp;
        else
        {
            last->next = tmp;
            last = tmp;
        }
    }

    tmp = head;
    while (tmp) {
        std::cout << tmp->x << "\t";
        tmp = tmp->next;
    }

    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}