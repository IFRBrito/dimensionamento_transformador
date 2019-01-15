#ifndef PRODUTO_H
#define PRODUTO_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>


#include "transformador.h"

class Produto : public QObject
{

    Q_OBJECT

private:

    QVector <transformador> produto;

public:


    explicit Produto(QObject *parent = nullptr);
    void inserirTransformador(const transformador a);
    void ordenarPorNome();
    void ordenarPorPotencia();


    int size();
    void clear();
    
    transformador operator[](int i);

signals:

public slots:

};

#endif // PRODUTO_H
