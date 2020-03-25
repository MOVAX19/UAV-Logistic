#include <iostream>

class drone
{
public:
    int ID;//Número de identificación del drone
    int state;
    /*Estado del drone
    0->Disponible
    1->Transporte
    2->Inspección*/
    int battery //Porcentaje de batería del drone
};

class package
{
public:
    int weight;//Peso del paquete
    char address;// Direccion del paquete: A,B,C,D
    bool priority;
    /*Tipo de envío
    0 -> envio normal
    1 -> envío express
    */
};

class conveyor_belt
{
public:
    int length;//longitud de la banda
    int speed;//velocidad de movmiento de la banda

};


int main(void){
  std::cout("Hey there, nibbro!");
}
