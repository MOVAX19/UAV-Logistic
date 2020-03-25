/**********************************
      Sistema de inventario con UAVs

      Martinez Valle, Braulio Emmanuel
      Ramirez Linarez, Axel
      Vazquez Tapia, Francisco

      Sistemas Operativos en Tiempo Real
              IECSA-05A
                2020
***********************************/


#include <iostream>

class drone
{
public:
    int ID;//Número de identificación del drone
    int state;
    /*Estado del drone
    0->Disponible
    1->Transporte
    2->Inspección
    3->En reparacion*/
    int battery //Porcentaje de batería del drone
    void transport();//F. para transportar pqts
    void inspect();//F. para inspeccionar pqts
    void maintenance();//F. para el mantenimiento del drone
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
    int quantity;//cantidad de paquetes generados
    void generatePkg(); //F. para generar paquetes
};


int main(void){
  std::cout("Hello world");
}
