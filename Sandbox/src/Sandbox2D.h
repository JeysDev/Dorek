#pragma once

#include "Dorek.h"

class Sandbox2D : public Dorek::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Dorek::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Dorek::Event& e) override;
private:
	Dorek::OrthographicCameraController m_CameraController;
	
	// Temp
	Dorek::Ref<Dorek::VertexArray> m_SquareVA;
	Dorek::Ref<Dorek::Shader> m_FlatColorShader;

	Dorek::Ref<Dorek::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};