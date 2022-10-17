#include "kckpch.h"
#include "ParticleContact.h"

namespace Kicker
{
    void ParticleContact::Resolve(const real deltaTime)
    {
        ResolveVelocity(deltaTime);
        ResolveInterpenetration(deltaTime);
    }

    real ParticleContact::CalculateSeparatingVelocity() const
    {
        glm::vec3 relativeVelocity = m_Particles[0]->GetVelocity();
        if (m_Particles[1])
            relativeVelocity -= m_Particles[1]->GetVelocity();

        return glm::dot(relativeVelocity, m_ContactNormal);
    }

    void ParticleContact::ResolveVelocity(const real deltaTime)
    {
        real separatingVelocity = CalculateSeparatingVelocity();

        if (separatingVelocity > 0)
            return;

        real adjustedSepVelocity = -separatingVelocity * m_RestitutionCoeff;

        glm::vec3 accCausedVel = m_Particles[0]->GetAcceleration();

        if (m_Particles[1])
            accCausedVel -= m_Particles[1]->GetAcceleration();

        real accCausedSeparatingVelocity = glm::dot(accCausedVel, m_ContactNormal) * deltaTime;

        if (accCausedSeparatingVelocity < 0)
        {
            adjustedSepVelocity += m_RestitutionCoeff * accCausedSeparatingVelocity;

            if (adjustedSepVelocity < 0) 
                adjustedSepVelocity = 0;
        }

        real deltaVel = adjustedSepVelocity - separatingVelocity;

        real totalInverseMass = m_Particles[0]->GetInverseMass();

        if (m_Particles[1])
            totalInverseMass += m_Particles[1]->GetInverseMass();

        if (totalInverseMass <= 0)
            return;

        real impulse = deltaVel / totalInverseMass;

        glm::vec3 impulsePerInverseMass = m_ContactNormal * impulse;

        m_Particles[0]->SetVelocity(m_Particles[0]->GetVelocity() + (impulsePerInverseMass * m_Particles[0]->GetInverseMass()));

        if (m_Particles[1])
            m_Particles[1]->SetVelocity(m_Particles[1]->GetVelocity() + (impulsePerInverseMass * -m_Particles[1]->GetInverseMass()));
    }

    void ParticleContact::ResolveInterpenetration(const real deltaTime)
    {
        if (m_PenetrationDepth <= 0)
            return;

        real totalInverseMass = m_Particles[0]->GetInverseMass();

        if (m_Particles[1])
            totalInverseMass += m_Particles[1]->GetInverseMass();

        if (totalInverseMass <= 0)
            return;

        glm::vec3 movePerInverseMass = m_ContactNormal * (-m_PenetrationDepth / totalInverseMass);
        
        m_Particles[0]->SetPosition(m_Particles[0]->GetPosition() + (movePerInverseMass * m_Particles[0]->GetInverseMass()));

        if (m_Particles[1])
        {
            m_Particles[1]->SetPosition(m_Particles[1]->GetPosition() + (movePerInverseMass * -m_Particles[1]->GetInverseMass()));
        }
    }

    void ParticleContactResolver::ResolveContacts(ParticleContact* contacts, unsigned int numContacts, const real deltaTime)
    {
        m_IterationsUsed = 0;
        while (m_IterationsUsed < m_Iterations)
        {
            real max = REAL_MAX;
            unsigned int maxIndex = numContacts;
            for (unsigned int i = 0; i < numContacts; i++)
            {
                real sepVel = contacts[i].CalculateSeparatingVelocity();
                if (sepVel < max)
                {
                    max = sepVel;
                    maxIndex = i;
                }
            }

            contacts[maxIndex].Resolve(deltaTime);
            m_IterationsUsed++;
        }
    }
}