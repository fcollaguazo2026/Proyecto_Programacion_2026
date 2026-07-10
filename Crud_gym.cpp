#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Miembro{
    int id;
    string nombre;
    int edad;
    string plan;
    string duracion;
    string fecha_inscripcion;
};

istream& operator>>(istream& entrada, Miembro& m){//aqui ocupamos operadores para optimizar el codigo
    string id,edad;
    if(getline(entrada,id,';')&&
    getline(entrada,m.nombre,';')&&
    getline(entrada,edad,';')&&
    getline(entrada,m.plan,';')&&
    getline(entrada,m.duracion,';')&&
    getline(entrada,m.fecha_inscripcion)){
        m.id=stoi(id);
        m.edad=stoi(edad);
    }
    return entrada;
    
}
ostream& operator<<(ostream& salida, Miembro& m){
    salida<<m.id<<";"
    <<m.nombre<<";"
    <<m.edad<<";"
    <<m.plan<<";"
    <<m.duracion<<";"
    <<m.fecha_inscripcion;
    return salida;
}

const string gym="Crud_Gym.txt";
void leer_Archivo(vector<Miembro>& miembros){
    ifstream archivo(gym);
    Miembro m;
    miembros.clear();

    if(archivo.is_open()){
        while(archivo>>m){
            miembros.push_back(m);
        }
        archivo.close();
    }

}
void guardar_archivo(vector <Miembro>& miembros){
    ofstream archivo(gym);
    if(archivo.is_open()){
        for(size_t i=0;i<miembros.size();i++){
            archivo<<miembros[i]<<endl;
        }
        archivo.close();
    }
}

void registrar_Miembro(vector <Miembro>& miembros){
    ofstream archivo(gym,ios::app);
    Miembro m;

    cout<<"Ingrese el codigo: ";
    cin>>m.id;
    cin.ignore();
    cout<<"Ingrese el nombre: ";
    getline(cin,m.nombre);
    cout<<"Ingrese la edad: ";
    cin>>m.edad;
    while(m.edad<=0){
        cout<<"Debe ser mayor que 0"<<endl;
        cout<<"Ingrese la edad: ";
        cin>>m.edad;
        break;
    }
    cin.ignore(),
    cout<<"-----Plan-----"<<endl;
    cout<<"1.- Basico"<<endl;
    cout<<"2.- Premiun"<<endl;
    cout<<"3.- VIP"<<endl;
    cout<<"Elija un plan: ";
    getline(cin,m.plan);

    cout<<"-----Duracion-----"<<endl;
    cout<<"1.- Mensual"<<endl;
    cout<<"2.- Trimestral"<<endl;
    cout<<"3.- Anual"<<endl;
    cout<<"Elija la duracion: ";
    getline(cin,m.duracion);
    cout<<"Ingrese la fecha de inscripcion: ";
    getline(cin,m.fecha_inscripcion);

    miembros.push_back(m);
    if(archivo.is_open()){
        archivo<<m<<endl;
        archivo.close();
        cout<<"Miembro Registrado correctamente"<<endl;
        
    }else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }

}

void mostrar_Miembros(vector <Miembro> miembros){
    ifstream archivo(gym);

    Miembro m;
    cout<<" ---- Lista De Miembros ----"<<endl;
    if(archivo.is_open()){
        while (archivo>>m){
            cout<<"ID: "<<m.id<<endl;
            cout<<"Nombre: "<<m.nombre<<endl;
            cout<<"Edad: "<<m.edad<<endl;
            cout<<"Plan: "<<m.plan<<endl;
            cout<<"Duracion: "<<m.duracion<<endl;
            cout<<"Fecha de Inscripcion: "<<m.fecha_inscripcion<<endl;
            cout<<"---------------------------"<<endl;
        }
        archivo.close();
    }else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
}

void buscar_miemmbro(vector <Miembro> miembros){
    ifstream archivo(gym);
    int id;
    Miembro m;
    bool encontrar=false;
    cout<<"Ingrese el id del miembro: ";
    cin>>id;
    if(archivo.is_open()){
        while (archivo>>m){
            if(m.id==id){
                encontrar=true;
                cout<<"Nombre: "<<m.nombre<<endl;
                cout<<"Edad: "<<m.edad<<endl;
                cout<<"Plan: "<<m.plan<<endl;
                cout<<"Duracion: "<<m.duracion<<endl;
                cout<<"Fecha de Inscripcion: "<<m.fecha_inscripcion<<endl;
                cout<<"---------------------------"<<endl;
                break;
            }
        }
        if(!encontrar){
            cout<<"ID incorrecto"<<endl;
        }
        archivo.close();
    }else{
        cout<<"No se pudo abrir el archvio"<<endl; // creo que esto de is open esta demas
    }
}



int main(){
    vector<Miembro> miembros;
    leer_Archivo(miembros);
    int opcion;
    do{
        cout<<"======= Gimnasio Fitnes ======"<<endl;
        cout<<"1.- Administrador"<<endl;
        cout<<"2.- Usuario"<<endl;
        cout<<"3.- Salir"<<endl;
        cout<<"Ingrese la opcion: ";
        cin>>opcion;
        string usuario="admin";
        string contrasenia="1234";
        string usu;
        string con;
        int contador=0;
        int op=0;
        int op1=0;
        switch (opcion){
        case 1:
            cin.ignore();
            cout<<"Ingrese el usuario: ";
            getline(cin,usu);
            cout<<"Ingrese la contraseña: ";
            getline(cin,con);
            do{
                if(usuario==usu && contrasenia==con){
                    cout<<"===== Aministrador ======"<<endl;
                    cout<<"1.- Registrar miembro"<<endl;
                    cout<<"2.- Mostrar miembro"<<endl;
                    cout<<"3.- Buscar miembro"<<endl;
                    cout<<"4.- Actualizar miembro"<<endl;
                    cout<<"5.- Eliminar miembro"<<endl;
                    cout<<"6.- Salir"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>op;
            
                    switch (op){
                    case 1:
                        registrar_Miembro(miembros);
                        break;
                    case 2:
                        mostrar_Miembros(miembros);
                        break;
                    case 3:
                        buscar_miemmbro(miembros);
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        cout<<"Saliendo....."<<endl;
                        break;
                    default:
                        cout<<"Opcion Invalida"<<endl;
                        break;
                    }
                }else{
                    cout<<"Usuario o Contrasenia Incorrecta"<<endl;
                }
            }while(op !=6);
            break;
        case 2:
            do{
                cout<<"===== Usuario ====="<<endl;
                cout<<"1.- Mostrar miembros"<<endl;
                cout<<"2.- Buscar miembro"<<endl;
                cout<<"3.- Salir"<<endl;
                cout<<"Ingrese una opcion: ";
                cin>>op1;
                switch (op1){
                    case 1:
                    mostrar_Miembros(miembros);
                    break;
                case 2:
                    buscar_miemmbro(miembros);
                    break;
                case 3:
                    cout<<"Saliendo...."<<endl;
                    break;
                default:
                    cout<<"Opcion Invalida"<<endl;
                    break;
                }
            }while(op1 !=3);
            break;
        default:
            cout<<"Opcion Invalida"<<endl;
            break;
        }
    }while(opcion !=3);
    return 0;
}