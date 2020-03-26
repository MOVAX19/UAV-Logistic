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
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class drone
{
public:
    int id;//Número de identificación del drone
    int state;
    /*Estado del drone
    0->Disponible
    1->Transporte
    2->Inspección
    3->En reparacion*/
    int battery //Porcentaje de batería del drone
    char pkgId;//Identificador para el paquete transportado actualmente.
    void transport();//F. para transportar pqts
    void inspect();//F. para inspeccionar pqts
    void maintenance();//F. para el mantenimiento del drone
    drone(int, int, int, int);//constructor
    ~drone();//desctructor
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
    package(int, char, bool);//constructor
    ~package();//desctructor
};

class conveyor_belt
{
public:
    int length;//longitud de la banda
    int speed;//velocidad de movmiento de la banda
    int quantity;//cantidad de paquetes generados
    vector<int> pkgList;//lista para guardar los paquetes existentes
    package generatePkg(); //F. para generar paquetes
    conveyor_belt(int,int);//constructor
    ~conveyor_belt();
};

////////////////////////////////////main/////////////////////////////////////////////////////
int main(void){
  conveyor_belt belt(1,10);
  vector<package> pkgs;
  vector<int>::iterator iter=belt.pkgList.begin();
  int w,factor;
  if battery<(battery-(1.5+W/100)){//conocer el estado de bateria

  while (belt.quantity<6) { //genera 5 paquetes

    pkgs.push_back(belt.generatePkg());
  }
}
  //imprime los ids de los paquetes existentes
  while (iter!=belt.pkgList.end()) {
    cout<<"Package: "<<*(iter)<<"\n"<<endl;
  }
  //linea sin importancia
  std::cout("Hello world");
}
////////////////////////////////////drone/////////////////////////////////////////////////////
dorne::package(int _id, int _state, int _battery, char _pkgId))
{
  id = _id;
  state = _state;
  battery = battery;
  pkgId = _pkgId;
}

drone::~drone()
{
  cout<<"Drone "<<id<<" is being destroyed"<<endl;
}

////////////////////////////////////package/////////////////////////////////////////////////////
package::package(int _id, char addss, bool ste)
{
  id=_id;
  address=addss;
  state=ste;
}

package::~package()
{
  cout<<"Package "<<id<<" is being destroyed"<<endl;
}
////////////////////////////////////conveyor_belt/////////////////////////////////////////////////////
conveyor_belt::conveyor_belt(int _length, int _speed)
{
  length=_length;
  speed=_speed;
  quantity=0;
  //Para generar numeros aleatorios
  srand (time(NULL));
}

package conveyor_belt::generatePkg()
{
  bool created=false, coincidence=false;
  int tempId;
  vector<int>::iterator iter=pkgList.begin();
  //Verifica si el ID generado ya fue utilizado
  while (!created && quantity<6) {
    tempId=rand()%100 + 1;
    while (!coincidence || iter!=pkgList.end()) {
      if (*(iter)==tempId)
      coincidence=true;
      iter++;
    }
  //Si no, se agrega a la lista de paquetes
    if (!coincidence) {
      pkgList.push_back(tempId);
      //se lleva el conteo de los paquetes creados.
      quantity++;
    }
  }
  package tempPkg(tempId,A,0);
  return tempPkg;
}
