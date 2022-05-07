#pragma once

#include "Dorek.h"

class ExampleLayer : public Dorek::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Dorek::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Dorek::Event& e) override;
private:
	Dorek::ShaderLibrary m_ShaderLibrary;
	Dorek::Ref<Dorek::Shader> m_Shader;
	Dorek::Ref<Dorek::VertexArray> m_VertexArray;

	Dorek::Ref<Dorek::Shader> m_FlatColorShader;
	Dorek::Ref<Dorek::VertexArray> m_SquareVA;

	Dorek::Ref<Dorek::Texture2D> m_Texture, m_ChernoLogoTexture;

	Dorek::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

