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
    int battery; //Porcentaje de batería del drone
    int pkgId;//Identificador para el paquete transportado actualmente.
    bool type;//Define el tipo de drones
    /*
    0->carga ligera. Secciones A,B
    1->carga pesada. Secciones C,D
    */
    void transport();//F. para transportar pqts
    void inspect();//F. para inspeccionar pqts
    void maintenance();//F. para el mantenimiento del drone
    drone(int, int, int, int,bool);//constructor
    ~drone();//desctructor
};

class package
{
public:
    int weight;//Peso del paquete
    char address;// Direccion del paquete: A,B,C,D
    bool priority;
    int id;
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

drone genDrones(int _pkgId);

////////////////////////////////////main/////////////////////////////////////////////////////
int main(void){
  conveyor_belt belt(1,10);
  //Vector para almacenar los paquetes
  vector<package> pkgs;
  //Vector para almacenar los drones
  vector<drone> drons;
  //Iterador para recorrer ambos vectores
  vector<int>::iterator iter;
  //int w,factor;
  //if (battery<(battery-(1.5+W/100))){//conocer el estado de bateria
  //Crear los paqutes
  while (belt.quantity<5) { //genera 5 paquetes
    pkgs.push_back(belt.generatePkg());
    std::cout<<"Paquete creado"<<std::endl;
  }
  //imprime los ids de los paquetes existentes
  iter=belt.pkgList.begin();
  while (iter!=belt.pkgList.end()) {
    //Generacion de drones y asignacion de paquetes
    drons.push_back(genDrones(*(iter)));
    std::cout<<"Drone creado"<<std::endl;
    iter++;
  }
  for(int i=0;i<5;i++){
    cout<<"\n\nEl paquete con el ID-"<<pkgs[i].id<<" tiene direccion: "<<pkgs[i].address<<endl;
  }

  for(int i=0;i<5;i++){
    cout<<"\n\nEl drone con el ID-"<<drons[i].id<<" tiene asignado el paquete con el ID-"<<drons[i].pkgId<<endl;
  }

  //linea sin importancia
  std::cout<<("\n\nHello world\n\n");
}
////////////////////////////////////drone/////////////////////////////////////////////////////
drone::drone(int _id, int _state, int _battery, int _pkgId, bool cargo)
{
  id = _id; //Identificador para el drone
  state = _state; //Estado del drone
  battery = _battery; //bateria
  pkgId = _pkgId; //Identificador del
  type=cargo;
}

drone::~drone()
{
  //cout<<"Drone "<<id<<" is being destroyed"<<endl;
}

////////////////////////////////////package/////////////////////////////////////////////////////
package::package(int _id, char addss, bool ste)
{
  id=_id;
  address=addss;
  priority=ste;
}

package::~package()
{
  //cout<<"Package "<<id<<" is being destroyed"<<endl;
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

//Destructor de la clase de cinta transportadora
conveyor_belt::~conveyor_belt(){
    std::cout<<"Adios,amigos!"<<endl;
}

package conveyor_belt::generatePkg()
{
  //std::cout<<"\nGenerando paquetes\n\n"<<std::endl;
  bool created=false, coincidence=false;
  int tempId;
  char  adresss;
  vector<int>::iterator iter=pkgList.begin();
  //Verifica si el ID generado ya fue utilizado
  while (!created && quantity<6) {
    coincidence=false;
    tempId=rand()%100 + 1;
    while (!coincidence && iter!=pkgList.end()) {
      if (*(iter)==tempId){coincidence=true;}
      iter++;
      //cout<<"Estoy aqui: "<<endl;
    }
  //Si no, se agrega a la lista de paquetes
    if (!coincidence) {
      pkgList.push_back(tempId);
      //se lleva el conteo de los paquetes creados.
      quantity++;
      created=true;
    }
  }
  adresss = 'A' + rand() % (('D' - 'A') + 1);
  package tempPkg(tempId,adresss/*direccion*/,0/*estado*/);
  return tempPkg;
}


/*****************************************************/
drone genDrones(int _pkgId)//Funcion para generar drones
{
  //std::cout<<"\nGenerando paquetes\n\n"<<std::endl;
  //Creacion de un id para cada drone
  int tempId;
  tempId=rand()%100 + 1;
  //Inicializacion del drone
  drone tempDron(tempId, 0, 100,_pkgId,0);
  return tempDron;
}
