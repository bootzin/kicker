#pragma once
#ifndef PARTICLE_FORCE_GEN_INCLUDED_H
#define PARTICLE_FORCE_GEN_INCLUDED_H

#include "Particle.h"
#include "Core.h"

namespace Kicker
{
	class ParticleForceGenerator
	{
	public:
		virtual void UpdateForce(Particle* particle, real deltaTime) = 0;
	};

#pragma region ParticleForceRegistry
    class ParticleForceRegistry
    {
    protected:
        struct ParticleForceRegistration
        {
        public:
            ParticleForceRegistration(Particle* particle, ParticleForceGenerator* fg) : m_Particle(particle), m_ForceGen(fg) {}

            Particle* GetParticle() const { return  m_Particle; }
            ParticleForceGenerator* GetParticleForceGenerator() const { return  m_ForceGen; }

            bool operator==(const ParticleForceRegistration& other)
            {
                return m_Particle == other.GetParticle() && m_ForceGen == other.GetParticleForceGenerator();
            }
        private:
            Particle* m_Particle;
            ParticleForceGenerator* m_ForceGen;
        };

        std::vector<ParticleForceRegistration> m_Registry;

    public:
        void Add(Particle* particle, ParticleForceGenerator* fg);
        void Remove(Particle* particle, ParticleForceGenerator* fg);
        void Clear();

        void UpdateForces(real deltaTime);
    };
#pragma endregion

#pragma region Force Generators
#pragma region Gravity
    class GravityForceGenerator : public ParticleForceGenerator
    {
    public:
        GravityForceGenerator(const glm::vec3& gravity) : m_Gravity(gravity) {}

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        glm::vec3 m_Gravity;
    };
#pragma endregion

#pragma region Drag
    class DragForceGenerator : public ParticleForceGenerator
    {
    public:
        DragForceGenerator(real k1, real k2) : m_K1(k1), m_K2(k2) {}

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        real m_K1;
        real m_K2;
    };
#pragma endregion

#pragma region Spring-likes
#pragma region Particle Spring
    class SpringForceGenerator : public ParticleForceGenerator
    {
    public:
        SpringForceGenerator(Particle* otherEnd, real constant, real restLength, bool isBungee) : m_OtherEnd(otherEnd), m_SpringConstant(constant), m_RestLength(restLength), m_IsBungee(isBungee) {}

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        Particle* m_OtherEnd;
        real m_SpringConstant;
        real m_RestLength;
        bool m_IsBungee;
    };
#pragma endregion

#pragma region Anchored Spring
    class AnchoredSpringForceGenerator : public ParticleForceGenerator
    {
    public:
        AnchoredSpringForceGenerator(glm::vec3* otherEnd, real constant, real restLength, bool isBungee) : m_OtherEnd(otherEnd), m_SpringConstant(constant), m_RestLength(restLength), m_IsBungee(isBungee) {}

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        glm::vec3* m_OtherEnd;
        real m_SpringConstant;
        real m_RestLength;
        bool m_IsBungee;
    };
#pragma endregion

#pragma region Buyoancy
    class BuyoancyForceGenerator : public ParticleForceGenerator
    {
    public:
        BuyoancyForceGenerator(real maxDepth, real volume, real liquidHeight, real liquidDensity = 1000.f) :
            m_MaxDepth(maxDepth), m_Volume(volume), m_LiquidHeight(liquidHeight), m_LiquidDensity(liquidDensity)
        {
        }

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        real m_MaxDepth;
        real m_Volume;
        real m_LiquidHeight;
        real m_LiquidDensity;
    };
#pragma endregion
#pragma endregion
#pragma endregion
}
#endif // !PARTICLE_FORCE_GEN_INCLUDED_H
