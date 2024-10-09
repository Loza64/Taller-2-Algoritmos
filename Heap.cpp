#include <iostream>  
#include <string>  

using namespace std;  

struct Empleado {  
    int id;  
    string nombre;  
    float salario;  
};  

// Función para intercambiar dos empleados  
void swap(Empleado &a, Empleado &b) {  
    Empleado temp = a;  
    a = b;  
    b = temp;  
}  

// Función para organizar el heap  
void heapify(Empleado arr[], int n, int i) {  
    int largest = i; // Inicializa el mayor como raíz  
    int left = 2 * i + 1; // Izquierdo = 2*i + 1  
    int right = 2 * i + 2; // Derecho = 2*i + 2  

    // Si el hijo izquierdo es mayor que la raíz  
    if (left < n && arr[left].salario > arr[largest].salario) {  
        largest = left;  
    }  

    // Si el hijo derecho es mayor que el mayor hasta ahora  
    if (right < n && arr[right].salario > arr[largest].salario) {  
        largest = right;  
    }  

    // Si el mayor no es la raíz  
    if (largest != i) {  
        swap(arr[i], arr[largest]); // Intercambiar  

        // Recursivamente organizar el sub-árbol afectado  
        heapify(arr, n, largest);  
    }  
}  

// Función para implementar Heap Sort  
void heapSort(Empleado arr[], int n) {  
    // Construir el heap  
    for (int i = n / 2 - 1; i >= 0; i--) {  
        heapify(arr, n, i);  
    }  

    // Extraer elementos del heap uno por uno  
    for (int i = n - 1; i > 0; i--) {  
        swap(arr[0], arr[i]); // Intercambiar la raíz (máximo) con el último elemento  
        heapify(arr, i, 0); // Llamar a heapify en el heap reducido  
    }  
}  

// Función para imprimir la lista de empleados  
void printEmpleados(Empleado arr[], int n) {  
    for (int i = 0; i < n; i++) {  
        cout << "ID: " << arr[i].id << ", Nombre: " << arr[i].nombre << ", Salario: " << arr[i].salario << endl;  
    }  
}  

int main() {  

    Empleado empleados[1000];  

    // Generar 1000 empleados  
    for (int i = 0; i < 1000; ++i) {  
        empleados[i].id = i + 1; // ID único  
        empleados[i].nombre = "Empleado" + std::to_string(i + 1); // Nombre ficticio  
        empleados[i].salario = 40000.0f + static_cast<float>(i % 10) * 5000.0f; // Salario con un rango definido
    }  
    
    int n = sizeof(empleados) / sizeof(empleados[0]);  

    cout << "Lista de empleados antes de ordenar:" << endl;  
    printEmpleados(empleados, n);  

    heapSort(empleados, n);  

    cout << "\nLista de empleados después de ordenar por salario:" << endl;  
    printEmpleados(empleados, n);  

    return 0;  
}