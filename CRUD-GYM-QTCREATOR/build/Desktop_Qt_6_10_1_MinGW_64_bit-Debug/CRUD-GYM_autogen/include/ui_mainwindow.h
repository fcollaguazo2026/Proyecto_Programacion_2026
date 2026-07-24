/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblTitulo;
    QGridLayout *gridLayout;
    QLabel *labelDuracion;
    QLabel *labelPlan;
    QLineEdit *txtEdad;
    QLabel *labelFecha;
    QLabel *labelId;
    QLabel *labelEdad;
    QComboBox *cmbPlan;
    QLineEdit *txtNombre;
    QLineEdit *txtFecha;
    QComboBox *cmbDuracion;
    QLabel *labelNombre;
    QLineEdit *txtId;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGuardar;
    QPushButton *btnEditar;
    QComboBox *cmbBuscar;
    QLineEdit *txtBuscar;
    QPushButton *btnBuscar;
    QPushButton *btnMostrar;
    QPushButton *btnEliminar;
    QPushButton *btnLimpiar;
    QTableWidget *tblClientes;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(850, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lblTitulo = new QLabel(centralwidget);
        lblTitulo->setObjectName("lblTitulo");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        lblTitulo->setFont(font);
        lblTitulo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lblTitulo);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelDuracion = new QLabel(centralwidget);
        labelDuracion->setObjectName("labelDuracion");

        gridLayout->addWidget(labelDuracion, 2, 2, 1, 1);

        labelPlan = new QLabel(centralwidget);
        labelPlan->setObjectName("labelPlan");

        gridLayout->addWidget(labelPlan, 1, 2, 1, 1);

        txtEdad = new QLineEdit(centralwidget);
        txtEdad->setObjectName("txtEdad");

        gridLayout->addWidget(txtEdad, 1, 1, 1, 1);

        labelFecha = new QLabel(centralwidget);
        labelFecha->setObjectName("labelFecha");

        gridLayout->addWidget(labelFecha, 2, 0, 1, 1);

        labelId = new QLabel(centralwidget);
        labelId->setObjectName("labelId");

        gridLayout->addWidget(labelId, 0, 0, 1, 1);

        labelEdad = new QLabel(centralwidget);
        labelEdad->setObjectName("labelEdad");

        gridLayout->addWidget(labelEdad, 1, 0, 1, 1);

        cmbPlan = new QComboBox(centralwidget);
        cmbPlan->addItem(QString());
        cmbPlan->addItem(QString());
        cmbPlan->addItem(QString());
        cmbPlan->addItem(QString());
        cmbPlan->setObjectName("cmbPlan");

        gridLayout->addWidget(cmbPlan, 1, 4, 1, 1);

        txtNombre = new QLineEdit(centralwidget);
        txtNombre->setObjectName("txtNombre");

        gridLayout->addWidget(txtNombre, 0, 4, 1, 1);

        txtFecha = new QLineEdit(centralwidget);
        txtFecha->setObjectName("txtFecha");

        gridLayout->addWidget(txtFecha, 2, 1, 1, 1);

        cmbDuracion = new QComboBox(centralwidget);
        cmbDuracion->addItem(QString());
        cmbDuracion->addItem(QString());
        cmbDuracion->addItem(QString());
        cmbDuracion->addItem(QString());
        cmbDuracion->setObjectName("cmbDuracion");

        gridLayout->addWidget(cmbDuracion, 2, 4, 1, 1);

        labelNombre = new QLabel(centralwidget);
        labelNombre->setObjectName("labelNombre");

        gridLayout->addWidget(labelNombre, 0, 2, 1, 1);

        txtId = new QLineEdit(centralwidget);
        txtId->setObjectName("txtId");

        gridLayout->addWidget(txtId, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGuardar = new QPushButton(centralwidget);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayout->addWidget(btnGuardar);

        btnEditar = new QPushButton(centralwidget);
        btnEditar->setObjectName("btnEditar");

        horizontalLayout->addWidget(btnEditar);

        cmbBuscar = new QComboBox(centralwidget);
        cmbBuscar->addItem(QString());
        cmbBuscar->addItem(QString());
        cmbBuscar->addItem(QString());
        cmbBuscar->addItem(QString());
        cmbBuscar->setObjectName("cmbBuscar");

        horizontalLayout->addWidget(cmbBuscar);

        txtBuscar = new QLineEdit(centralwidget);
        txtBuscar->setObjectName("txtBuscar");

        horizontalLayout->addWidget(txtBuscar);

        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");

        horizontalLayout->addWidget(btnBuscar);

        btnMostrar = new QPushButton(centralwidget);
        btnMostrar->setObjectName("btnMostrar");

        horizontalLayout->addWidget(btnMostrar);

        btnEliminar = new QPushButton(centralwidget);
        btnEliminar->setObjectName("btnEliminar");

        horizontalLayout->addWidget(btnEliminar);

        btnLimpiar = new QPushButton(centralwidget);
        btnLimpiar->setObjectName("btnLimpiar");

        horizontalLayout->addWidget(btnLimpiar);


        verticalLayout->addLayout(horizontalLayout);

        tblClientes = new QTableWidget(centralwidget);
        if (tblClientes->columnCount() < 6)
            tblClientes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblClientes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tblClientes->setObjectName("tblClientes");
        tblClientes->setColumnCount(6);
        tblClientes->horizontalHeader()->setVisible(true);
        tblClientes->verticalHeader()->setVisible(true);

        verticalLayout->addWidget(tblClientes);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gesti\303\263n de Clientes - Gimnasio", nullptr));
        lblTitulo->setText(QCoreApplication::translate("MainWindow", "\360\237\217\213 EPN GYM MANAGER\360\237\217\213\n"
"Sistema de Gesti\303\263n de Clientes", nullptr));
        labelDuracion->setText(QCoreApplication::translate("MainWindow", "Duracion:", nullptr));
        labelPlan->setText(QCoreApplication::translate("MainWindow", "Plan:", nullptr));
        txtEdad->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ej: 30", nullptr));
        labelFecha->setText(QCoreApplication::translate("MainWindow", "Fecha Inscripci\303\263n:", nullptr));
        labelId->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        labelEdad->setText(QCoreApplication::translate("MainWindow", "Edad:", nullptr));
        cmbPlan->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione un plan", nullptr));
        cmbPlan->setItemText(1, QCoreApplication::translate("MainWindow", "Basico", nullptr));
        cmbPlan->setItemText(2, QCoreApplication::translate("MainWindow", "Premium", nullptr));
        cmbPlan->setItemText(3, QCoreApplication::translate("MainWindow", "VIP", nullptr));

        txtNombre->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ej: Carlos P\303\251rez", nullptr));
        txtFecha->setPlaceholderText(QCoreApplication::translate("MainWindow", "DD/MM/AAAA", nullptr));
        cmbDuracion->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione la duracion:", nullptr));
        cmbDuracion->setItemText(1, QCoreApplication::translate("MainWindow", "Mensual", nullptr));
        cmbDuracion->setItemText(2, QCoreApplication::translate("MainWindow", "Trimestral", nullptr));
        cmbDuracion->setItemText(3, QCoreApplication::translate("MainWindow", "Anual", nullptr));

        labelNombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        txtId->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ej: 1", nullptr));
        btnGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        cmbBuscar->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione:", nullptr));
        cmbBuscar->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        cmbBuscar->setItemText(2, QCoreApplication::translate("MainWindow", "Plan", nullptr));
        cmbBuscar->setItemText(3, QCoreApplication::translate("MainWindow", "Fecha", nullptr));

        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnMostrar->setText(QCoreApplication::translate("MainWindow", "Mostrar Todo", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnLimpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblClientes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblClientes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblClientes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Edad", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblClientes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Plan", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblClientes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Duracion", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblClientes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Fecha", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
