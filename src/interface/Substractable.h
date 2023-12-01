template <class T, class U> 
//asi nejaka metoda na odecitani ... musi brat dva ty objekty, abychom se od sebe mohli preci odecist... 
class Substractable
{
    public:
    virtual U subs(const T &other) const = 0; 
};
