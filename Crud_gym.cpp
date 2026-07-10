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
        int contrasenia=1234;
        string usu;
        int con;
        switch (opcion){
        case 1:
            int op;
            cin.ignore();
            cout<<"Ingrese el usuario: ";
            getline(cin,usu);
            cout<<"Ingrese la contraseña: ",
            cin>>con;

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
                    break;
                case 3:
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
            break;
        case 2:
            int op1;
            cout<<"===== Usuario ====="<<endl;
            cout<<"1.- Mostrar miembros"<<endl;
            cout<<"2.- Buscar miembro"<<endl;
            cout<<"3.- Salir"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcion;
            break;
            switch (op1){
            case 1:
                break;
            case 2:
                break;
            case 3:
                cout<<"Saliendo...."<<endl;
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
            }
        default:
            break;
        }

    }while(opcion !=3);
    return 0;
}