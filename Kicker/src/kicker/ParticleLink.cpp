#include "kckpch.h"
#include "ParticleLink.h"
namespace Kicker
{
	unsigned int ParticleCable::FillContact(ParticleContact* contact, unsigned int limit) const
	{
		real length = GetCurrentLength();

		if (length < m_MaxLength)
			return 0;

		contact->SetParticles(m_Particles);
		contact->SetContactNormal(glm::normalize(m_Particles[1]->GetPosition() - m_Particles[0]->GetPosition()));
		contact->SetPenetrationDepth(length - m_MaxLength);
		contact->SetRestitutionCoefficient(m_RestitutionCoeff);

		return 1;
	}
	unsigned int ParticleRod::FillContact(ParticleContact* contact, unsigned int limit) const
	{
		real currentLength = GetCurrentLength();

		if (currentLength == m_Length)
			return 0;

		contact->SetParticles(m_Particles);
		
		if (currentLength > m_Length)
		{
			contact->SetContactNormal(glm::normalize(m_Particles[1]->GetPosition() - m_Particles[0]->GetPosition()));
			contact->SetPenetrationDepth(currentLength - m_Length);
		}
		else
		{
			contact->SetContactNormal(-glm::normalize(m_Particles[1]->GetPosition() - m_Particles[0]->GetPosition()));
			contact->SetPenetrationDepth(m_Length - currentLength);
		}

		contact->SetRestitutionCoefficient(0);
		
		return 1;
	}
}