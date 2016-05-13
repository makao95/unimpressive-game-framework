#include "UGF/Actor.h"

class Controller{
public:
    Controller();
    
    void addActor(uint id);

    virtual void update() = 0;
    
};
