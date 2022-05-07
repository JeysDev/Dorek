#pragma once

#include "Dorek/Core/Layer.h"

#include "Dorek/Events/ApplicationEvent.h"
#include "Dorek/Events/KeyEvent.h"
#include "Dorek/Events/MouseEvent.h"

namespace Dorek {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
