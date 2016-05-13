#include "UGF/ParticleSystem.h"
#include <iostream>

ugf::ParticleSystem::ParticleSystem(sf::PrimitiveType primitiveType):primitiveType(primitiveType) {

}

void ugf::ParticleSystem::update(sf::Time time) {
	time += ignoredTime;
	systemTime += time;
	if (systemTime >= systemLifetime) {
		if (particles.size() == 0) {
			//TODO: mark as destroy
			tag("destroy");
			return;
		}
	} else {
		if (time.asSeconds() / particlesPerSecond) {
			for (int i=particlesPerSecond*time.asSeconds(); i>0; i--)
				createParticle();
			ignoredTime = time - sf::seconds(int(time.asSeconds() * particlesPerSecond)/float(particlesPerSecond));

			std::vector<int> particlesToDelete;
		}
	}

	int c = 0;
	for (int a = 0; a<particles.size(); a++) {
		ugf::Particle& particle = particles.at(a);
		if (particle.time > particle.lifetime) {
			particles.erase(particles.begin()+a);
			verticles.erase(verticles.begin()+a);
		} else {
			particle.time += time;
			particle.velocity = particle.velocity + force * time.asSeconds();
			particle.position += time.asSeconds() * particle.velocity;
			sf::Color cl = verticles.at(c).color;
			float life = particle.time.asSeconds()/particle.lifetime.asSeconds();
			if (life > 1)
				life = 1;
			verticles.at(c).color = sf::Color(color.r*(1-life) + transColor.r*life, color.g*(1-life) + transColor.g*life , color.b*(1-life) + transColor.b*life, color.a*(1-life) + transColor.a*life);
			verticles.at(c).position = particle.position;
		}
		c++;
	}
}

void ugf::ParticleSystem::createParticle() {
    int angle = std::rand();
	ugf::Particle particle;
	particle.time = sf::seconds(0);
	particle.position = position;
	particle.velocity = sf::Vector2f(cos(angle), sin(angle)) * particlesVelocity;
	particle.lifetime = particleMinLifetime + sf::seconds(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (particleMaxLifetime.asSeconds() - particleMinLifetime.asSeconds()) )));
	particles.push_back(particle);
	sf::Vertex v;
	v.color = color;
	v.position = particle.position;
	verticles.push_back(v);
	//TODO: Primitives..

}

void ugf::ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(&verticles[0], verticles.size(), primitiveType);
}

void ugf::ParticleSystem::setParticleLifetime(sf::Time timeMin, sf::Time timeMax) {
	assert(timeMin.asSeconds() <= timeMax.asSeconds());
	particleMinLifetime = timeMin;
	particleMaxLifetime = timeMax;
}

void ugf::ParticleSystem::setParticlesPerSecond(float p) {
	particlesPerSecond = p;
}

void ugf::ParticleSystem::setParticlesVelocity(float vel) {
	particlesVelocity = vel;
}

void ugf::ParticleSystem::setSpread(float degrees) {
	spread = degrees;
}

void ugf::ParticleSystem::setSystemLifetime(sf::Time time) {
	systemLifetime = time;
}

void ugf::ParticleSystem::setPosition(sf::Vector2f pos) {
	position = pos;
}

void ugf::ParticleSystem::applyForce(sf::Vector2f f) {
	force = f;
}

void ugf::ParticleSystem::setColor(sf::Color color) {
	this->color = color;
}

void ugf::ParticleSystem::setColorTransition(sf::Color ct) {
	transColor = ct;
}

unsigned int ugf::ParticleSystem::getParticlesCount() {
	return particles.size();
}
