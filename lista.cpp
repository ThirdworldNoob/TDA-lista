#include "Lista.h"
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
Lista<T>::Lista()
{
    principio= NULL;
}

template <typename T>
Lista<T>::~Lista()
{
    Nodo* aux;
    while (principio!=NULL){
        aux= principio->siguiente;
        delete principio;
        principio= aux;
    }
    principio=NULL;
}

template <typename T>
int Lista<T>::cantElementos() const
{
    int nodos=0;
    Nodo* aux=principio;
    while (aux != NULL){
        nodos+=1;
        aux=aux->siguiente;
    }
    return nodos;
}

template <typename T>
void Lista<T>::agregarPos(const T & elemento, unsigned int pos) //asumo que se respeta la precondicion que previene una posicion invalida
{
    Nodo* nuevo= new Nodo;
    nuevo->elemento=elemento;
    if (pos==1){
        principio=nuevo;
        principio->siguiente=NULL;

    }
    else if (pos <= cantElementos()+1){
        Nodo* cursor=principio;
        int i=1;
        while((cursor-> siguiente != NULL) or (i < pos-1) ){      //asumo que el principio de la lista, el primer elemento, es la posicion 1
            cursor=cursor->siguiente;
            i+=1;
        }
        nuevo->siguiente=cursor->siguiente;
        cursor->siguiente=nuevo;
    }
}


template <typename T>
void Lista<T>::agregarPrimero(const T & elemento)
{
    agregarPos(elemento,1);
}

template <typename T>
void Lista<T>::agregarUltimo(const T & elemento)
{
    int i=cantElementos();
    agregarPos(elemento,i+1);
}

template <typename T>
bool Lista<T>::pertenece(const T & elemento) const
{
    if (principio==NULL){
        return false;
    }
    else{
        Nodo* aux= principio;
        if (aux->elemento != elemento){
            aux=aux->siguiente;
        }
        if (aux==NULL){
            return false;
        } else {
            return true;
        }
    }
}

template <typename T>
bool Lista<T>::vaciaLista() const
{
    return (principio==NULL);
}

template <typename T>
void Lista<T>::eliminarElemento(const T & elemento) //solo elimina la primer ocurrencia del elemento
{
    if (!vaciaLista()){
        if (principio->elemento==elemento){
            Nodo* aux= principio;
            principio=principio->siguiente;
            delete aux;
        } else {
            Nodo* cursor=principio;
            while (cursor->siguiente->elemento != elemento){
                cursor=cursor->siguiente;
            }
            if (cursor->siguiente==NULL){
                cout << "El elemento " << elemento << " no pertenece a la lista." << endl;
            } else {
                Nodo* aux= cursor->siguiente;
                cursor->siguiente=aux->siguiente;
                delete aux;
            }
    }
  }
}

template <typename T>
const T& Lista<T>::obtenerElemento(unsigned int pos) const
{
  if (pos <= cantElementos()){ 
    Nodo* cursor=principio;
    int i=1;

    if(pos == 1){
        return cursor->elemento; 
    }

    while((cursor-> siguiente != NULL) or (i < pos) ){      //asumo que el principio de la lista, el primer elemento, es la posicion 1
        cursor=cursor->siguiente;
        i+=1;
    }
    return cursor->elemento;
   }
  else{
     cout<<"La posicion ingresada no es valida"<<endl;
   }


template class Lista<int>;
template class Lista<float>;
template class Lista<bool>;
