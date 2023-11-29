template <class T>
//asi nejaka metoda na odecitani ... musi brat dva ty objekty, abychom se od sebe mohli preci odecist... 
class Substractable
{
    public:
    virtual T subs(const T &other) const = 0; 
};
