#ifndef TRANSFORMADOR_H
#define TRANSFORMADOR_H

#include <QObject> // utilizamos para poder usar o QString


class transformador
{

private:

    float potencia_instalada;
    float fator_demanda;
    float fator_potencia;
    float previsao_aumentoCarga;
    float potencia_total;
    QString nome_cliente;
    float valor_calculado_potencia;
    float valor_recomendado_potencia;

public:


    explicit transformador();
    transformador(QString nome, float valor_calculado, float valor_homologado);

    float getvalor_homologado ()const;
    void setvalor_homologado(float valor);

    float getValor_calculado() const ;
    void setValor_calculado(float valor);

    float getPotencia_instalada() const;
    void setPotencia_instalada(float valor);

    float getFator_potencia() const;
    void setFator_potencia(float valor);

    float getFator_demanda() const;
    void setFator_demanda(float valor);

    float getPrevisao_carga() const;
    void setPrevisao_carga(float valor);

    float getPotencia_total() const;
    void setPotencia_total(float valor);

    QString getNome()const;
    void setNome (const QString &valor);




signals:

public slots:

};

#endif // TRANSFORMADOR_H

