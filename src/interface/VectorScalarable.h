//Vytvoř interface VectorScalarable, které zaručí že vektor půjde skalárně vynásobit s jiným
template <class T>
class VectorScalarable {
public:
    virtual float scalar(const T &other) const = 0; // Must be const for const objects
  
    };