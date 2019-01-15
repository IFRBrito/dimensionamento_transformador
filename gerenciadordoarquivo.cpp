#include "gerenciadordoarquivo.h"

gerenciadorDoArquivo::gerenciadorDoArquivo()
{

}
bool gerenciadorDoArquivo::salvarProduto(QString &arquivo, Produto &produto)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<produto.size();i++){
        out << produto[i].getNome()<<","<<produto[i].getPotencia_total()<< ","<< produto[i].getvalor_homologado()<<"\r\n";
    }

    file.close();
    return true;
}
bool gerenciadorDoArquivo::carregarProduto(QString &arquivo, Produto &produto)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        transformador a(dados[0],dados[1].toFloat(), dados[2].toFloat());
        produto.inserirTransformador(a);

    }
    return true;
}
