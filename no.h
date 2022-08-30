#ifndef NO_H
#define NO_H


template <typename tipo>
class NO
{
    tipo dado;
    NO<tipo> *proximo;
    NO<tipo>  *anterior;
public:
     NO();
     NO(tipo valor);
    ~NO();
    void setDado(tipo newDado);
    tipo getDado() const;
    void setProximo( NO<tipo> *newProximo);
    NO<tipo>* getProximo() const;
    void setAnterior( NO<tipo> *newAnterior);
    NO<tipo>* getAnterior() const;
};
template <typename tipo>
NO<tipo>::NO():
    dado(0),
    proximo(0),
    anterior(0)
{

}
template <typename tipo>
NO<tipo>::NO(tipo valor):
    dado(valor),
    proximo(0),
    anterior(0)
{

}
template <typename tipo>
NO<tipo>::~NO(){
 proximo=0;
 anterior = 0;

}
template <typename tipo>
tipo NO<tipo>::getDado() const{
  return dado;
}
template <typename tipo>
void NO<tipo>::setDado(tipo newDado){
  dado = newDado;
}
template <typename tipo>
NO<tipo>* NO<tipo>::getProximo() const{
  return proximo;
}
template <typename tipo>
void NO<tipo>::setProximo(NO<tipo> *newProximo){
  proximo = newProximo;
}
template <typename tipo>
NO<tipo>* NO<tipo>::getAnterior() const{
  return anterior;
}
template <typename tipo>
void NO<tipo>::setAnterior(NO<tipo> *newAnterior){
  anterior = newAnterior;
}

#endif // NO_H
