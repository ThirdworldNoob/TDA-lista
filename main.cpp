#include <iostream>
#include "Lista.cpp"

using namespace std;

int main()
{
    Lista<int> p;
    p.agregarPrimero(1);
    p.agregarUltimo(4);
    p.agregarPos(3,2);
    cout << "La cantidad de elementos en la lista es de " << p.cantElementos() << "." << endl;
    p.agregarUltimo(70);
    cout << "La cantidad de elementos en la lista es de " << p.cantElementos() << "." << endl;
    if (p.vaciaLista()){
        cout << "La lista estA vacia." << endl;
    } else {
        cout << "La lista no esta vacia." << endl;
    }
    cout << "Ingresar un elemento para buscar en la lista " << endl;
    int i;
    cin >> i;

    if (p.pertenece(i)){
        cout << "El elemento " << i << " pertenece a la lista." << endl;
    } else {
        cout << "El elemento " << i << " no pertenece a la lista." << endl;
    }
    return 0;

    cout<<"ingrese una posicion desde la que quiera eliminar un elemento"<<endl;
    int pos;
    p.eliminarElemento(pos);
    cout << "La cantidad de elementos en la lista es de " << p.cantElementos() << "." << endl;


}
