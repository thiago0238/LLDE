#ifndef LLDE_H
#define LLDE_H
#include "no.h"
#include <QString>
#include <iostream>

template <typename tipo>
class LLDE
{
    NO<tipo> *inicio;
    NO<tipo> *fim;
    int qtd;
public:
     LLDE();
    ~LLDE();
    void inserirInicio(tipo elemento);
    int getQtd() const;
    tipo retirarInicio();
    bool estaVazia() const;
    void inserirFim(tipo elemento);
    tipo retirarFim();
    tipo operator[](int pos);
    tipo retirarQualquer(int pos);
    void inserirQualquer(int pos, tipo elemento);
    void inserirOrdenado(tipo elemento);
};

template <typename tipo>
int LLDE<tipo>::getQtd() const{
    return qtd;
}

template <typename tipo>
 LLDE<tipo>:: LLDE():
    inicio(0),
    fim(0),
    qtd(0)
{

}

 template <typename tipo>
 LLDE<tipo>::~LLDE(){
     while(!estaVazia()){
         retirarInicio();
     }

      //if (inicio) delete inicio;
      //if (fim) delete fim;

  }

 template <typename tipo>
  bool LLDE<tipo>::estaVazia() const{
      if(qtd == 0)
          return true;
      else
          return false;

  }

  template <typename tipo>
  void LLDE<tipo>::inserirInicio(tipo elemento){
      try {
          NO<tipo> *aux = new NO(elemento);
          if(estaVazia()){
              qtd++;
              inicio=fim=aux;
              return;
          }

          aux->setProximo(inicio);
          inicio->setAnterior(aux);
          inicio = aux;
          qtd++;
      }
      catch (std::bad_alloc&) {
          QString("Nao tem memoria");


      }
  }

  template <typename tipo>
  tipo LLDE<tipo>::retirarInicio(){
      if(qtd==1){
         tipo x = inicio->getDado();
         delete inicio;
         qtd--;
         inicio=fim=0;
         return x;
      }
      if(estaVazia()){
          throw QString("esta Vazia");

      }
          NO<tipo> *aux = inicio;
          //inicio->getProximo()->setAnterior(0); //maneira usual, mas comprida.
          inicio= aux ->getProximo();
          inicio->setAnterior(0);
          qtd--;
          tipo valor = aux->getDado();
          delete aux;
          return valor;
      }

  template <typename tipo>
  void LLDE<tipo>::inserirFim(tipo elemento){
      try {
          NO<tipo> *aux = new NO(elemento);
          if(estaVazia()){
              inicio=fim=aux;
              qtd++;
              return;
          }
          fim->setProximo(aux);
          aux->setAnterior(fim);
          fim=aux;
          qtd++;

      }    catch (QString &erro) {
          std:: cout<<"\nERRO : "<<erro.toStdString()<<"\n";

      }

  }

  template <typename tipo>
  tipo LLDE<tipo>::retirarFim(){
      if(estaVazia()) {
          throw QString("esta Vazia");
      }
      if(qtd==1){
          tipo x=fim->getDado();
          delete fim;
          inicio=fim=0;
          qtd=0;
          return x;
      }

       NO<tipo> *aux=fim;
       fim=aux->getAnterior();
       fim->setProximo(0);
       tipo x=aux->getDado();
       qtd--;
       delete aux;
       return x;

      }

  template <typename tipo>
  tipo LLDE<tipo>::operator[](int pos){
      if(estaVazia())
          throw QString("esta Vazia");

         if(pos<0 || pos >=qtd)
             throw QString("Posição invalida");
         if(pos == 0)
             return inicio->getDado();
         if(pos == qtd-1)
             return fim->getDado();
         else{
             NO<tipo> *paux = inicio;
             int cont = 0;
             while(cont < pos){
                 paux = paux->getProximo();
                 cont ++;
             }
             return paux->getDado();

         }
  }

  template <typename tipo>
  tipo LLDE<tipo>::retirarQualquer(int pos){
      if(estaVazia())
          throw QString("esta Vazia");

         if(pos<0 || pos >=qtd)
             throw QString("Posição invalida");
         if(pos ==0)
             return retirarInicio();
         if(pos ==qtd-1)
             return retirarFim();
         else{
             NO<tipo> *paux = inicio;
             int cont = 0;
             while(cont <pos-1){
                 paux = paux->getProximo();
                 cont++;
             }
             NO<tipo> *paux2 = paux->getProximo();
             paux->setProximo(paux2->getProximo());
             tipo valor = paux2 ->getDado();
             delete paux2;
             qtd--;
             return valor;
          }
  }

  template <typename tipo>
  void LLDE<tipo>::inserirQualquer(int pos, tipo elemento){

      try {
          NO<tipo> *aux = new NO(elemento);
          NO<tipo> *paux= inicio;
          int cont = 0;
          if(estaVazia()){
              inicio = aux;
              qtd++;
              return;
          }
          if(pos == qtd){
              while (paux->getProximo() != 0 ){
                  paux= paux->getProximo();
              }
              paux->setProximo(aux);
              qtd++;
              return;
          }

          if(pos ==0)
              return inserirInicio(elemento);
          else {
              while(cont <pos-1){
                  paux = paux->getProximo();
                  cont++;
          }
              NO<tipo> *paux2= paux->getProximo()->getProximo();
              paux->setProximo(aux);
              paux->getProximo()->setProximo(paux2);
              qtd++;


          }

      }    catch (QString &erro) {
          std:: cout<<"\nERRO : "<<erro.toStdString()<<"\n";

      }
  }
  template <typename tipo>
  void LLDE<tipo>::inserirOrdenado(tipo elemento){
      try {

          NO<tipo> *paux= inicio;

          if(estaVazia()){
              inserirInicio(elemento);
              return;
          }
          if(qtd==1 && elemento<=paux->getDado()){
              inserirInicio(elemento);
              return;
          }

          while(elemento>= paux->getDado() && paux!= fim){
              paux=paux->getProximo();
          }
          if(paux==fim){
              if(elemento>=fim->getDado()){
                    inserirFim(elemento);
              }
              else if(elemento< fim->getDado()){
                  inserirQualquer(qtd-1,elemento);
              }

              return;
          }

              NO<tipo> *paux2= new NO(elemento);
              paux2->setProximo(paux->getProximo());
              paux2->setAnterior(paux);
              paux->setProximo(paux2);
              qtd++;
              return;

      }catch (QString &erro) {
          std:: cout<<"\nERRO : "<<erro.toStdString()<<"\n";

      }
  }

#endif // LLDE_H
