#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    string name;
    float salary;
    Employee *left;
    Employee *right;

    Employee(string name = "", float salary = 0.0f) : name(name), salary(salary), left(nullptr), right(nullptr) {}
};

// Función para intercambiar los valores de dos Employees
void swap(Employee *a, Employee *b)
{
    string tempname = a->name;    // Intercambiar names
    float tempsalary = a->salary; // Intercambiar salarys
    a->name = b->name;
    a->salary = b->salary;
    b->name = tempname;
    b->salary = tempsalary;
}

// Función heapify
void heapify(Employee *root)
{
    if (!root)
        return;

    Employee *largest = root;
    if (root->left && root->left->salary > largest->salary)
    {
        largest = root->left;
    }
    if (root->right && root->right->salary > largest->salary)
    {
        largest = root->right;
    }

    // Si el mayor no es la raíz
    if (largest != root)
    {
        swap(root, largest);
        heapify(largest);
    }
}

void buildHeap(Employee *root)
{
    if (!root)
        return;

    buildHeap(root->left);
    buildHeap(root->right);

    heapify(root);
}

void heapSort(Employee *root)
{
    if (!root)
        return;

    buildHeap(root);
}

void printEmployees(Employee *root)
{
    if (!root)
        return;

    printEmployees(root->left);
    cout << "{" << endl
         << "   'name': '" << root->name << "'," << endl
         << "   'salary': " << root->salary << endl
         << "}," << endl;
    printEmployees(root->right);
}

void freeMemory(Employee *root)
{
    if (!root)
        return;

    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}

int main()
{
    Employee *root = new Employee("Employee0", 40000.0f);
    Employee *current = root;

    for (int i = 1; i < 1000; ++i)
    {
        string name = "Employee_" + to_string(i);
        float salary = 40000.0f + i;
        Employee *nuevoEmployee = new Employee(name, salary);

        if (i % 2 == 1)
        { // Hijo izquierdo
            current->left = nuevoEmployee;
        }
        else
        {
            current->right = nuevoEmployee;
            current = current->left ? current->left : current;
        }
    }

    // cout << "Lista de Employees antes de ordenar:" << endl;
    //  printEmployees(root);

    heapSort(root);
    cout << "\nEmployees ordenados por salary:" << endl;
    printEmployees(root);

    freeMemory(root);

    return 0;
}