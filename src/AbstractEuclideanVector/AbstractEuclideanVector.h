#include <VectorAddable.h>
#include <VectorScalarable.h>
#include <cmath>

//Vytvoř abstraktní třídu AbstractEuclideanVector, která implementuje obě tato rozhraní.




template <class T>
class AbstractEuclideanVector :public VectorAddable<T>, public VectorScalarable<T>
{
public: 

    static float norm(const T &other)
     {
        return sqrt(other.scalar(other));
      
    }

 };