#include <iostream>
#include <queue>
#include <list>

#include "PriorityQueue.h"
#include "Student.h"

Student test[] = {  Student(10,90),
                    Student(7,85),
                    Student(12,65),
                    Student(6,100),
                    Student(20,95),
                    Student(4,80),
                    Student(1, 97),
                    Student(15,75)};


struct IntCompare
{
    bool operator ()(int x, int y) const { return x < y; }
};

int main(int argc, const char * argv[])
{
    int a[] = {1,9,3,7,0,10,20,5};
    MySort(a, a + sizeof(a)/sizeof(a[0]), IntCompare());

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		cout << a[i] << " ";

	cout << endl;
    
    // Create a priority queue of Students and keep it ordered using the Functor class CompareByAge
    PriorityQueue<Student, CompareByAge> q1;
    
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); ++i)
		q1.enqueue(test[i]);
    
    while (!q1.isEmpty())
    {
        const Student& s1 = q1.top();
		std::cout << s1 << std::endl;
        q1.dequeue();
    }
    
    // Create a priority queue of Students and keep it ordered using the Functor class CompareByAvg
    PriorityQueue<Student, CompareByAvg> q2;
    
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); ++i)
		q2.enqueue(test[i]);
    
    while (!q2.isEmpty())
    {
        const Student& s1 = q2.top();
		std::cout << s1 << std::endl;
        q2.dequeue();
    }

	/*Iterator Example*/
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); ++i)
		q2.enqueue(test[i]);

	PriorityQueue<Student, CompareByAvg>::Iterator it = q2.begin();
	while (it != q2.end())
	{
		cout << *(it) << endl;
		++it;
	}

	cin.get();
}
