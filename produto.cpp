#include "produto.h"

Produto::Produto(QObject *parent ) : QObject(parent){


}
void Produto::inserirTransformador(const transformador a){

    produto.push_back(a);
}

int Produto::size(){

    return produto.size();
}

void Produto::ordenarPorNome(){

    std::sort(produto.begin(), produto.end(), [] (transformador a, transformador b){return a.getNome()<b.getNome();});
}

transformador Produto::operator[](int i){

    return produto[i];

}
void Produto::ordenarPorPotencia(){

   std::stable_sort(produto.begin(),produto.end(),[](transformador a, transformador b){return a.getPotencia_total()<b.getPotencia_total();});
}

void Produto::clear(){

    return produto.clear();
}





