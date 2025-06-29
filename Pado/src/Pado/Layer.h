#pragma once

#include "Pado/Core.h"
#include "Pado/Events/Event.h"

namespace Pado {

	class PADO_API Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_debugName; }
	protected:
		std::string m_debugName; // only for debug //TODO: delete
	};
}