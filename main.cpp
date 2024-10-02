#include <iostream>
#include "Cola.h"

int main()
{
    Cola MiCola;
    persona x;
    for(int i=1;i<=3; i++){
        std::cin>>x;
        MiCola.enqueue(x);
    }
    //for(int i=1;i<=5; i++)
        //std::cout<<MiCola.dequeue();


    std::cout << "\nIngrese la persona a buscar" << std::endl;
    std::cin >> x;
    MiCola.buscarSolicitud(x); // Utilizar la función buscarSolicitud

    return 0;
}

