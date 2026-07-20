#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QIntValidator>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , indiceSeleccionado(-1)
{
    ui->setupUi(this);

    // Validadores para ID, Edad y Fecha
    ui->txtId->setValidator(new QIntValidator(1, 999999, this));
    ui->txtEdad->setValidator(new QIntValidator(1, 150, this));

    QRegularExpressionValidator *validadorFecha = new QRegularExpressionValidator(
        QRegularExpression("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$"), this);
    ui->txtFecha->setValidator(validadorFecha);

    // Configuración de la tabla
    ui->tblClientes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblClientes->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblClientes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblClientes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Estado inicial de botones
    ui->btnEditar->setEnabled(false);
    ui->btnEliminar->setEnabled(false);

    // Conexiones de señales y slots
    connect(ui->btnGuardar, &QPushButton::clicked, this, &MainWindow::guardarCliente);
    connect(ui->btnEditar, &QPushButton::clicked, this, &MainWindow::editarCliente);
    connect(ui->btnEliminar, &QPushButton::clicked, this, &MainWindow::eliminarCliente);
    connect(ui->btnBuscar, &QPushButton::clicked, this, &MainWindow::buscarCliente);
    connect(ui->btnLimpiar, &QPushButton::clicked, this, &MainWindow::limpiarFormulario);
    connect(ui->tblClientes, &QTableWidget::cellClicked, this, &MainWindow::seleccionarCliente);

    // Cargar datos al iniciar
    cargarClientesDesdeArchivo();
    actualizarTabla();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ------------------------------------------------------------
// Validar que todos los campos estén llenos y con formato correcto
bool MainWindow::validarFormulario()
{
    if (ui->txtId->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campo obligatorio", "Ingrese el ID del cliente.");
        ui->txtId->setFocus();
        return false;
    }
    if (ui->txtNombre->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campo obligatorio", "Ingrese el nombre del cliente.");
        ui->txtNombre->setFocus();
        return false;
    }
    if (ui->txtEdad->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campo obligatorio", "Ingrese la edad del cliente.");
        ui->txtEdad->setFocus();
        return false;
    }
    if (ui->cmbPlan->currentIndex() == 0) {
        QMessageBox::warning(this, "Campo obligatorio", "Seleccione un plan.");
        return false;
    }
    if (ui->txtFecha->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campo obligatorio", "Ingrese la fecha de inscripción (DD/MM/AAAA).");
        ui->txtFecha->setFocus();
        return false;
    }
    return true;
}

// ------------------------------------------------------------
// Buscar índice por ID dentro del vector
int MainWindow::buscarIndicePorId(int id)
{
    for (int i = 0; i < clientes.size(); ++i) {
        if (clientes[i].id == id)
            return i;
    }
    return -1;
}

// ------------------------------------------------------------
// Guardar cliente (CREATE)
void MainWindow::guardarCliente()
{
    if (!validarFormulario())
        return;

    int id = ui->txtId->text().toInt();
    if (buscarIndicePorId(id) != -1) {
        QMessageBox::warning(this, "ID duplicado", "Ya existe un cliente con ese ID.");
        return;
    }

    Cliente cliente;
    cliente.id = id;
    cliente.nombre = ui->txtNombre->text().trimmed();
    cliente.edad = ui->txtEdad->text().toInt();
    cliente.plan = ui->cmbPlan->currentText();
    cliente.fecha = ui->txtFecha->text().trimmed();

    clientes.append(cliente);
    guardarClientesEnArchivo();
    actualizarTabla();
    limpiarFormulario();

    QMessageBox::information(this, "Cliente guardado", "El cliente se guardó correctamente.");
}

// ------------------------------------------------------------
// Mostrar todos los clientes en la tabla
void MainWindow::actualizarTabla()
{
    ui->tblClientes->setRowCount(clientes.size());
    for (int fila = 0; fila < clientes.size(); ++fila) {
        const Cliente &c = clientes[fila];
        ui->tblClientes->setItem(fila, 0, new QTableWidgetItem(QString::number(c.id)));
        ui->tblClientes->setItem(fila, 1, new QTableWidgetItem(c.nombre));
        ui->tblClientes->setItem(fila, 2, new QTableWidgetItem(QString::number(c.edad)));
        ui->tblClientes->setItem(fila, 3, new QTableWidgetItem(c.plan));
        ui->tblClientes->setItem(fila, 4, new QTableWidgetItem(c.fecha));
    }
}

// ------------------------------------------------------------
// Seleccionar un cliente al hacer clic en la tabla
void MainWindow::seleccionarCliente(int fila, int columna)
{
    Q_UNUSED(columna);
    if (fila < 0 || fila >= clientes.size())
        return;

    indiceSeleccionado = fila;
    const Cliente &c = clientes[fila];

    ui->txtId->setText(QString::number(c.id));
    ui->txtNombre->setText(c.nombre);
    ui->txtEdad->setText(QString::number(c.edad));
    ui->cmbPlan->setCurrentText(c.plan);
    ui->txtFecha->setText(c.fecha);

    ui->btnGuardar->setEnabled(false);
    ui->btnEditar->setEnabled(true);
    ui->btnEliminar->setEnabled(true);
}

// ------------------------------------------------------------
// Editar cliente
void MainWindow::editarCliente()
{
    if (indiceSeleccionado == -1) {
        QMessageBox::warning(this, "Sin selección", "Seleccione un cliente de la tabla.");
        return;
    }
    if (!validarFormulario())
        return;

    int nuevoId = ui->txtId->text().toInt();
    int indiceExistente = buscarIndicePorId(nuevoId);
    if (indiceExistente != -1 && indiceExistente != indiceSeleccionado) {
        QMessageBox::warning(this, "ID duplicado", "Ya existe otro cliente con ese ID.");
        return;
    }

    Cliente &c = clientes[indiceSeleccionado];
    c.id = nuevoId;
    c.nombre = ui->txtNombre->text().trimmed();
    c.edad = ui->txtEdad->text().toInt();
    c.plan = ui->cmbPlan->currentText();
    c.fecha = ui->txtFecha->text().trimmed();

    guardarClientesEnArchivo();
    actualizarTabla();
    limpiarFormulario();

    QMessageBox::information(this, "Cliente actualizado", "El cliente se actualizó correctamente.");
}

// ------------------------------------------------------------
// Eliminar cliente
void MainWindow::eliminarCliente()
{
    if (indiceSeleccionado == -1) {
        QMessageBox::warning(this, "Sin selección", "Seleccione un cliente de la tabla.");
        return;
    }

    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmar eliminación",
                                      "¿Desea eliminar este cliente?",
                                      QMessageBox::Yes | QMessageBox::No);
    if (respuesta == QMessageBox::Yes) {
        clientes.removeAt(indiceSeleccionado);
        guardarClientesEnArchivo();
        actualizarTabla();
        limpiarFormulario();
        QMessageBox::information(this, "Cliente eliminado", "El cliente fue eliminado.");
    }
}

// ------------------------------------------------------------
// Buscar cliente por ID
void MainWindow::buscarCliente()
{
    if (ui->txtId->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "ID requerido", "Ingrese el ID a buscar.");
        return;
    }

    int id = ui->txtId->text().toInt();
    int indice = buscarIndicePorId(id);
    if (indice == -1) {
        QMessageBox::information(this, "No encontrado", "No existe un cliente con ese ID.");
        return;
    }

    indiceSeleccionado = indice;
    const Cliente &c = clientes[indice];
    ui->txtNombre->setText(c.nombre);
    ui->txtEdad->setText(QString::number(c.edad));
    ui->cmbPlan->setCurrentText(c.plan);
    ui->txtFecha->setText(c.fecha);
    ui->tblClientes->selectRow(indice);

    ui->btnGuardar->setEnabled(false);
    ui->btnEditar->setEnabled(true);
    ui->btnEliminar->setEnabled(true);

    QMessageBox::information(this, "Cliente encontrado", "El cliente se encontró correctamente.");
}

// ------------------------------------------------------------
// Limpiar formulario y resetear estados
void MainWindow::limpiarFormulario()
{
    ui->txtId->clear();
    ui->txtNombre->clear();
    ui->txtEdad->clear();
    ui->cmbPlan->setCurrentIndex(0);
    ui->txtFecha->clear();
    ui->tblClientes->clearSelection();
    indiceSeleccionado = -1;
    ui->btnGuardar->setEnabled(true);
    ui->btnEditar->setEnabled(false);
    ui->btnEliminar->setEnabled(false);
    ui->txtId->setFocus();
}

// ------------------------------------------------------------
// Guardar todos los clientes en archivo de texto
void MainWindow::guardarClientesEnArchivo()
{
    QString ruta = QDir::currentPath() + "/clientes.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo.");
        return;
    }

    QTextStream salida(&archivo);
    for (const Cliente &c : clientes) {
        salida << c.id << ";" << c.nombre << ";" << c.edad << ";"
               << c.plan << ";" << c.fecha << "\n";
    }
    archivo.close();
}

// ------------------------------------------------------------
// Cargar clientes desde archivo al iniciar
void MainWindow::cargarClientesDesdeArchivo()
{
    QString ruta = QDir::currentPath() + "/clientes.txt";
    QFile archivo(ruta);
    if (!archivo.exists())
        return;

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        return;
    }

    clientes.clear();
    QTextStream entrada(&archivo);
    while (!entrada.atEnd()) {
        QString linea = entrada.readLine();
        if (linea.trimmed().isEmpty())
            continue;
        QStringList datos = linea.split(";");
        if (datos.size() != 5)
            continue;

        Cliente c;
        c.id = datos[0].toInt();
        c.nombre = datos[1];
        c.edad = datos[2].toInt();
        c.plan = datos[3];
        c.fecha = datos[4];
        clientes.append(c);
    }
    archivo.close();
}
