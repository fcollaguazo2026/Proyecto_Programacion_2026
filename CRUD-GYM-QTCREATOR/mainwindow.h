#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "gimnasio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void guardarCliente();
    void editarCliente();
    void eliminarCliente();
    void filtrarClientes();
    void limpiarFormulario();
    void mostrarClientes();
    void seleccionarCliente(int fila, int columna);

private:
    Ui::MainWindow *ui;
    QVector<Cliente> clientes;
    int indiceSeleccionado;

    bool validarFormulario();
    int buscarIndicePorId(int id);
    void actualizarTabla();
    void guardarClientesEnArchivo();
    void cargarClientesDesdeArchivo();
};

#endif // MAINWINDOW_H
