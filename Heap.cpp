#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    string name;
    int salary;
};

void heapify(Employee arr[], int n, int i)
{
    int high = i;            
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left].salary > arr[high].salary)
    {
        high = left;
    }
    if (right < n && arr[right].salary > arr[high].salary)
    {
        high = right;
    }

    if (high != i)
    {
        swap(arr[i], arr[high]);
        heapify(arr, n, high);
    }
}
void heapsort(Employee arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);  
    }
}

int main()
{
    Employee employees[1000];
    for (int i = 0; i < 1000; i++)
    {
        employees[i].name = "Employee_" + to_string(i + 1);
        employees[i].salary = rand() % 10000 + 1000; 
    }

    int n = sizeof(employees) / sizeof(employees[0]);

    heapsort(employees, n);

    cout << "Salary employees order by desc:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << employees[i].name << ", Salary: " << employees[i].salary << endl;
    }

    return 0;
}