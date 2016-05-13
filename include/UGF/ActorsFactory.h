#include "UGF/Actor.h"
#include <Box2D/Box2D.h>

namespace ugf{

class ActorsFactory{
    static void createActor();
    static Actor createActor(b2Body* body);
    static Actor createQuadActor();
    static Actor createQuadActor(b2Body* body);
};
}
