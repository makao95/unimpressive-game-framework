#include "UGF/Actor.h"
namespace ugf{

class Particle{
public:
    sf::Time time;
    sf::Time lifetime;
    sf::Vector2f position;
    sf::Vector2f velocity;
};

class ParticleSystem : public Actor{
public:
    ParticleSystem(sf::PrimitiveType primitiveType = sf::Points);
    void update(sf::Time time);
    void setSystemLifetime(sf::Time time);
    void setTexture(sf::Texture t, sf::FloatRect rect);
    void setPosition(sf::Vector2f pos);
    void setColor(sf::Color color);
    void applyForce(sf::Vector2f f);

    void setColorTransition(sf::Color ct);
    void setParticlesVelocity(float vel);
    void setParticlesAcceleration(float a);
    void setParticlesPerSecond(float p);
    void setParticleLifetime(sf::Time timeMin, sf::Time timeMax);
    void setParticleSize(sf::Vector2f size);
    void setSpread(float degrees);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    unsigned int getParticlesCount();
    //TO implement
    void clear();
    void setColor(sf::Color start, sf::Color end);
    void setColor(sf::Color start, sf::Color mid, sf::Color end);
    void setParticleSize(sf::Vector2f sizeStart, sf::Vector2f sizeEnd);
    void setDistance(float d);
    void setForce(sf::Vector2f forceStart, sf::Vector2f forceEnd);
    void setAttractor(sf::Vector2f attractor, float force);
    void setInterpolate(unsigned int i);

    sf::Color getColorStart();
    sf::Color getColorMid();
    sf::Color getColorEnd();
private:
    void inline createParticle();

    sf::Time ignoredTime;
    std::vector<Particle> particles;
//    std::vector<sf::Vertex> verticles;

    sf::Time systemLifetime;
    sf::Time systemTime;
    sf::Vector2f position;
    sf::Vector2f force;
    sf::Color color;
    sf::Color transColor;
    float particlesPerSecond;
    float particlesVelocity;
    float spread;

    sf::Time particleMinLifetime;
    sf::Time particleMaxLifetime;

    sf::IntRect textureRect;
    sf::Vector2f particleSize;
    sf::PrimitiveType primitiveType;
};

}
