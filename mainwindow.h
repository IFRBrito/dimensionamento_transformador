#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <numeric>
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>

#include "transformador.h"
#include "produto.h"
#include "gerenciadordoarquivo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    Produto mercadorias_empresa;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void on_button_limpar_lista_pi_clicked();
    void on_button_salvar_dados_clicked();
    void on_actionsair_triggered();
    void on_button_resultadofinal_clicked();
    void on_button_name_sort_clicked();
    void on_button_potencia_sort_clicked();
    
    void salvar();
    void carregar();


    void on_button_addNewCliente_clicked();

    void on_button_mais_informacoes_clicked();

private:
    Ui::MainWindow *ui;
    void inserirTransformadorNaTabela(transformador transformador, int row);
};

#endif // MAINWINDOW_H
