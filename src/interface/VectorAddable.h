//Vytvoř interface (třídu s Pure virtual funkci) VectorAddable,
// které zaručí že půjdou sečíst dva vektory.

template <class T>
class VectorAddable
{
    virtual T operator+(const T &other) const = 0; // sercita dva vectory
};
