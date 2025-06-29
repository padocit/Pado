// Wrapper Container
#pragma once

#include "Pado/Core.h"
#include "Layer.h"

#include <vector>

namespace Pado {

	class PADO_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<Layer*> m_layers; // wrapper of this
		std::vector<Layer*>::iterator m_layerInsert;
	};
}