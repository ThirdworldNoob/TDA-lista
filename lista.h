#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregarPos(const T & elemento, unsigned int pos);
        void agregarPrimero(const T & elemento);
        void agregarUltimo(const T & elemento);
        int cantElementos() const;
        bool pertenece(const T & elemento) const;
        bool vaciaLista() const;
        void eliminarElemento(const T & elemento);
        const T& obtenerElemento(unsigned int pos) const;

    private:
        struct Nodo{
            T elemento;
            Nodo* siguiente;
        };

        Nodo* principio;
};

#endif // LISTA_H
