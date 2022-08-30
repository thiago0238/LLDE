#include <QCoreApplication>
#include "llde.h"
#include <iostream>


int main()
{
    LLDE<std::string> teste;
    try {

        teste.inserirInicio("dia");
        teste.inserirInicio("bom");
        teste.inserirInicio("opa");


        std::cout<<"Retirar os elementos do inicio \n";
        std::cout<<teste.retirarInicio()<<" ";
        std::cout<<teste.retirarInicio()<<" ";
        std::cout<<teste.retirarInicio()<<" ";

LLDE<int> teste;
        teste.inserirFim(10);
        teste.inserirFim(20);
        teste.inserirFim(30);


        std::cout<<"\nRetirar os elementos pelo fim \n";
        std::cout<<teste.retirarFim()<<" ";
        std::cout<<teste.retirarFim()<<" ";
        std::cout<<teste.retirarFim()<<" ";
/*
        teste.inserirFim(10);
        teste.inserirInicio(20);
        teste.inserirFim(30);
        teste.inserirInicio(40);

        std::cout<<"\nRetirar os elementos pelo fim \n";
        std::cout<<teste.retirarFim()<<" ";
        std::cout<<teste.retirarInicio()<<" ";
        std::cout<<teste.retirarFim()<<" ";
        std::cout<<teste.retirarInicio()<<" ";


        teste.inserirQualquer(0,10);
        teste.inserirQualquer(1,11);
        teste.inserirQualquer(2,12);


        std::cout<<"\nRetirar os elementos pela posição  \n";
        std::cout<<teste.retirarQualquer(0)<<" ";
        std::cout<<teste.retirarQualquer(0)<<" ";
        std::cout<<teste.retirarQualquer(0)<<" ";

        std::cout<<"\n inserir em ordem\n";
        teste.inserirFim(1);
        teste.inserirFim(2);
        teste.inserirFim(4);
        teste.inserirOrdenado(3);


        std::cout<<teste[0]<<" ";
        std::cout<<teste[1]<<" ";
        std::cout<<teste[2]<<" ";
        std::cout<<teste[3]<<" \n";

*/

    } catch (QString &erro) {
        std:: cout<<"\nERRO : "<<erro.toStdString()<<"\n\n";
    }
}
