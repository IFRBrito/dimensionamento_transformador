#include "transformador.h"

transformador::transformador()
{

}
transformador::transformador(QString nome, float valor_calculado, float valor_homologado){

    nome_cliente = nome;
    valor_calculado_potencia = valor_calculado;
    valor_recomendado_potencia = valor_homologado;
}

float transformador::getFator_potencia() const {

        return fator_potencia;
}
void transformador::setFator_potencia(const float valor){

    fator_potencia = valor;
}


float transformador::getPotencia_instalada() const {

        return potencia_instalada;

}
void transformador::setPotencia_instalada(const float valor){

    potencia_instalada = valor;

}



float transformador::getFator_demanda() const{

        return fator_demanda;
}
void transformador::setFator_demanda(const float valor){

        fator_demanda = valor;
}


float transformador::getPrevisao_carga() const {

        return previsao_aumentoCarga;

}
void transformador::setPrevisao_carga(const float valor){

        previsao_aumentoCarga = valor;
}



float transformador::getPotencia_total() const{

        return potencia_total;
}
void transformador::setPotencia_total(const float valor){

        potencia_total = valor;
}


QString transformador::getNome() const {

        return nome_cliente;

}
void transformador::setNome(const QString &valor){

        nome_cliente = valor;

}
float transformador::getvalor_homologado ()const{

        return valor_recomendado_potencia;

}
void transformador::setvalor_homologado(float valor){

        valor_recomendado_potencia = valor;

}



