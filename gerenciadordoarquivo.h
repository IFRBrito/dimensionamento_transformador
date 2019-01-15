#ifndef GERENCIADORDOARQUIVO_H
#define GERENCIADORDOARQUIVO_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "transformador.h"
#include "produto.h"

class gerenciadorDoArquivo
{
public:
    gerenciadorDoArquivo();
    static bool salvarProduto(QString &arquivo, Produto &produto);
    static bool carregarProduto(QString &arquivo, Produto &produto);
};

#endif // GERENCIADORDOARQUIVO_H
