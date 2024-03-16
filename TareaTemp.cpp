#include <iostream>

using namespace std;

struct Temperatura {
    char fecha[20];
    float manana;
    float tarde;
    float noche;
    float promedio;
    Temperatura* sig;
};

Temperatura* primero = NULL;
Temperatura* ultimo = NULL;
int Ndias = 0;

void registro() {
    Temperatura* NuevoRe = new Temperatura; 
    cout << "Ingrese la fecha D/M/A: ";
    cin >> NuevoRe->fecha;
    cout << "Ingrese la temperatura de la manana: ";
    cin >> NuevoRe->manana;
    cout << "Ingrese la temperatura de la tarde: ";
    cin >> NuevoRe->tarde;
    cout << "Ingrese la temperatura de la noche: ";
    cin >> NuevoRe->noche;

    NuevoRe->promedio = (NuevoRe->manana + NuevoRe->tarde + NuevoRe->noche) / 3.0;

    if (primero == NULL) {
        primero = NuevoRe;
        ultimo = NuevoRe;
    } else {
        ultimo->sig = NuevoRe;
        ultimo = NuevoRe;
    }
    NuevoRe->sig = NULL;
    Ndias++;
}

void mostrar() {
    if (primero == NULL) {
        cout << "No hay registros disponibles." <<endl;
    } else {
        cout << endl << "Registros de temperatura: " <<endl;
        Temperatura* auxi = primero;
        int dia = 1;
        while (auxi != NULL) {
            cout << "Dia " << dia << ": " << auxi->fecha <<endl;
            cout << "manana: " << auxi->manana << " grados" <<endl;
            cout << "tarde: " << auxi->tarde << " grados" <<endl;
            cout << "noche: " << auxi->noche << " grados" <<endl;
            cout << "promedio: " << auxi->promedio << " grados" <<endl;
            auxi = auxi->sig;
            dia++;
        }
    }
}

void promedioTotal() {
    if (primero == NULL) {
        cout << "No hay registros disponibles." <<endl;
    } else {
        float sumaTotal = 0;
        int totalRegistros = 0;
        Temperatura* auxi = primero;
        while (auxi != NULL) {
            sumaTotal += auxi->manana + auxi->tarde + auxi->noche;
            totalRegistros += 3; 
            auxi = auxi->sig;
        }
        float promedio = sumaTotal / totalRegistros;
        cout << endl << "Promedio de todas las temperaturas registradas: " << promedio << " grados" <<endl;
    }
}

int main() {
    int opc;
    do {
        cout << endl << "Menu:" <<endl;
        cout << "1. Registrar temperatura" <<endl;
        cout << "2. Mostrar registros" <<endl;
        cout << "3. Calcular promedio de todas las temperaturas registradas" <<endl;
        cout << "4. Salir" <<endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        cout << endl;

        switch (opc) {
            case 1:
                registro();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                promedioTotal();
                break;
        }
    } while (opc != 4);

    Temperatura* temp = primero;
    while (temp != NULL) {
        Temperatura* siguiente = temp->sig;
        free(temp) ;
        temp = siguiente;
    }

    return 0;
}