#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transformador.h"
#include "produto.h"
#include "gerenciadordoarquivo.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Botão destinado a limpar os espaços de dados da primeira etapa

void MainWindow::on_button_limpar_lista_pi_clicked()
{
    ui->line_nomeCliente->clear();
    ui->line_equipamentos_aquecimento->clear();
    ui->line_iluminacao->clear();
    ui->line_empilhadeira->clear();
    ui->line_tomadas->clear();
    ui->line_motores->clear();
    ui->line_condicionadores_ar->clear();

    ui->line_nomeCliente->setFocus();

}

//button destinado a passar da primeira etapa para a segunda

void MainWindow::on_button_salvar_dados_clicked()
{

    ui->tabWidget->setCurrentWidget(ui->tab_2);

}

// sinal para sair do programa
void MainWindow::on_actionsair_triggered()
{

    close(); // sair

}

//Botão destinado a salvar os dados, fazer o calculo da potencia total e salvar os dados do transformador

void MainWindow::on_button_resultadofinal_clicked()
{


    if(ui->line_nomeCliente->text().size() !=0 && ui->line_valor_demandaInstalacao->text().size() !=0){


        transformador transformador;


        transformador.setPrevisao_carga(ui->line_aumentoCarga->text().toFloat());
        transformador.setFator_demanda(ui->line_valor_demandaInstalacao->text().toFloat());
        transformador.setPotencia_instalada(ui->line_equipamentos_aquecimento->text().toFloat()+ui->line_iluminacao->text().toFloat()+ui->line_empilhadeira->text().toFloat()+ui->line_tomadas->text().toFloat()+ui->line_motores->text().toFloat()+ui->line_condicionadores_ar->text().toFloat());
        transformador.setNome(ui->line_nomeCliente->text());
        transformador.setFator_potencia(ui->comboBox_fator_Potencia_2->currentText().toFloat());
        transformador.setFator_demanda(ui->line_valor_demandaInstalacao->text().toFloat());

        qDebug()<<transformador.getFator_demanda();
        qDebug()<<transformador.getPotencia_instalada();
        qDebug()<<transformador.getNome();
        qDebug()<<transformador.getFator_potencia();
        qDebug()<<transformador.getPrevisao_carga();

        ui->line_nomeCliente->clear();
        ui->line_equipamentos_aquecimento->clear();
        ui->line_iluminacao->clear();
        ui->line_empilhadeira->clear();
        ui->line_tomadas->clear();
        ui->line_motores->clear();
        ui->line_condicionadores_ar->clear();

        ui->line_nomeCliente->setFocus(); // colocar o foco na primeira pergunta


        transformador.setPotencia_total(transformador.getPotencia_instalada()*transformador.getFator_demanda()*transformador.getPrevisao_carga()/transformador.getFator_potencia());


        if(transformador.getPotencia_total()<300.00){

                       float valor = 300;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();


                   }
                   else if(transformador.getPotencia_total()<500.00 && transformador.getPotencia_total()>=300.00){

                       float valor = 500;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                   else if(transformador.getPotencia_total()<750 && transformador.getPotencia_total()>=500.00){

                       float valor = 750;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                 else if(transformador.getPotencia_total()<1000.00 && transformador.getPotencia_total()>=750.00){

                       float valor = 1000;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                   else if(transformador.getPotencia_total()<1500.00 && transformador.getPotencia_total()>=1000.00){

                       float valor = 1500;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                  else if(transformador.getPotencia_total()<2000.00 && transformador.getPotencia_total()>=1500.00){

                       float valor = 2000;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                   else if(transformador.getPotencia_total()<2500.00 && transformador.getPotencia_total()>=2000.00 ){

                       float valor = 2500;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   }
                   else if(transformador.getPotencia_total()<3000.00 && transformador.getPotencia_total()>=2500.00){

                       float valor = 3000;
                       transformador.setvalor_homologado(valor);
                       qDebug() << transformador.getvalor_homologado();

                   } else {

                       ui->tabWidget->setCurrentWidget(ui->tab);
                       ui->line_aumentoCarga->clear();
                       ui->line_valor_demandaInstalacao->clear();
                   }


        qDebug()<<transformador.getPotencia_total();

// adicionando dados na tabela e salvando os dados no vector

        if (transformador.getPotencia_total()!=0 && transformador.getPotencia_total()<3000){

                int quantidade_row = ui->tbl_dados->rowCount();
                ui->tbl_dados->insertRow(quantidade_row);
                inserirTransformadorNaTabela(transformador, quantidade_row);
                mercadorias_empresa.inserirTransformador(transformador);
                qDebug()<< mercadorias_empresa.size();
                ui->tabWidget->setCurrentWidget(ui->tab_valores);
                ui->line_aumentoCarga->clear();
                ui->line_valor_demandaInstalacao->clear();



        } else {

            ui->tabWidget->setCurrentWidget(ui->tab);
            ui->line_aumentoCarga->clear();
            ui->line_valor_demandaInstalacao->clear();
        }

    }



}

// adicionar os dados na tabela

void MainWindow::inserirTransformadorNaTabela(transformador transformador, int row){


               ui->tbl_dados->setItem(row,0,new QTableWidgetItem(transformador.getNome()));
               ui->tbl_dados->setItem(row,1, new QTableWidgetItem(QString::number(transformador.getPotencia_total())));
               ui->tbl_dados->setItem(row, 2, new QTableWidgetItem(QString::number(transformador.getvalor_homologado())));

}

// Ordenar pelo nome do cliente
void MainWindow::on_button_name_sort_clicked()
{

    ui->tbl_dados->clearContents();

    mercadorias_empresa.ordenarPorNome();
    for(int i = 0; i<mercadorias_empresa.size(); i++){

        inserirTransformadorNaTabela(mercadorias_empresa[i],i);
    }

}

// ordenar por potência calculada
void MainWindow::on_button_potencia_sort_clicked()
{


    ui->tbl_dados->clearContents();

   mercadorias_empresa.ordenarPorPotencia();
    for(int i = 0; i<mercadorias_empresa.size();i++){
        inserirTransformadorNaTabela(mercadorias_empresa[i],i);
    }

}

// adicionar novo cliente
void MainWindow::on_button_addNewCliente_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->tab);
}

// salvar arquivo
void MainWindow::salvar(){

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Transformadores","","Texto(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( gerenciadorDoArquivo::salvarProduto(nomeArquivo,mercadorias_empresa) ){
        QMessageBox::information(this, "Salvar Informações","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar Informações","Não foi possível salvar os dados");
    }

}

// Carregar arquivo
void MainWindow::carregar(){

    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Transformadores","","Texto(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    mercadorias_empresa.clear();

    if(gerenciadorDoArquivo::carregarProduto(nomeArquivo,mercadorias_empresa)){

        ui->tbl_dados->clearContents();
        for(int i=0;i<mercadorias_empresa.size();i++){

            if(i >= ui->tbl_dados->rowCount())
                ui->tbl_dados->insertRow(i);

            inserirTransformadorNaTabela(mercadorias_empresa[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar lista de produtos","Não foi possível carregar os dados");
    }
}



void MainWindow::on_button_mais_informacoes_clicked()
{

    QString link="https://github.com/IFRBrito/dimensionamento_transformador/blob/master/README.md";
    QDesktopServices::openUrl(QUrl(link));


}
