#include <PointAddable.h>
#include <Substractable.h>



//Vytvoř abstraktní třídu AbstractEuclideanPoint, která implementuje výše zmíněné.
//Poskytne obecnou definici funkce distance, která zjistí vzdálenost mezi dvěma body 
//(využije k tomu interface Subtractable a statickou metodu z třídy AbstractEuclideanVector::norm)

template <class T >
class AbstractEuclideanPoint :public PointAddable<T>, public Substractable<T>, public VectorScalarable<T>

//dedim i z VectorScaralable protoze tahle funkce dole pro Pointy bohuzel potrebuje scalar - pouziva ho funkce norm... 
{
public: 

  float distancePoint(const T &other) {
        T difference = this->subs(other); 
        return AbstractEuclideanVector<T>::norm(difference); 
    }

  

 };