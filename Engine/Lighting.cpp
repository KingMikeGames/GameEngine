#include "Lighting.h"
#include "renderingEngine.h"
#include "engine.h"
#include <glm\gtx\transform.hpp>

#define COLOR_DEPTH 256

void BaseLight::AddToEngine(Engine* engine)
{
	engine->GetRenderingEngine()->AddLight(*this);
}

ShadowCameraTransform BaseLight::CalcShadowCameraTransform(const glm::vec3& mainCameraPos, const glm::quat& mainCameraRot)
{
	return ShadowCameraTransform(GetParent()->GetTransform().getPosition(), GetParent()->GetTransform().getRotation());
}

DirectionalLight::DirectionalLight(const glm::vec3& color, float intensity, int shadowMapSizeAsPowerOf2,
	float shadowArea, float shadowSoftness, float lightBleedReductionAmount, float minVariance) :
	BaseLight(color, intensity, Shader()),
	m_halfShadowArea(shadowArea / 2.0f)
{
	if (shadowMapSizeAsPowerOf2 != 0)
	{
		SetShadowInfo(ShadowInfo(glm::ortho(-m_halfShadowArea, m_halfShadowArea, -m_halfShadowArea,
			m_halfShadowArea, -m_halfShadowArea, m_halfShadowArea),
			true, shadowMapSizeAsPowerOf2, shadowSoftness, lightBleedReductionAmount, minVariance));
	}
}


ShadowCameraTransform DirectionalLight::CalcShadowCameraTransform(const glm::vec3& mainCameraPos, const glm::quat& mainCameraRot)
{
	glm::vec3 resultPos = mainCameraPos + (mainCameraRot * glm::vec3(0,0,1) * glm::conjugate(mainCameraRot)) * GetHalfShadowArea();
	glm::quat resultRot = GetParent()->GetTransform().getRotation();

	float worldTexelSize = (GetHalfShadowArea() * 2) / ((float)(1 << GetShadowInfo().GetShadowMapSizeAsPowerOf2()));

	glm::vec3 lightSpaceCameraPos = glm::rotate(glm::conjugate(resultRot), resultPos);

	lightSpaceCameraPos.x = worldTexelSize * floor(lightSpaceCameraPos.x / worldTexelSize);
	lightSpaceCameraPos.y = worldTexelSize * floor(lightSpaceCameraPos.y / worldTexelSize);

	resultPos = glm::rotate(glm::conjugate(resultRot), lightSpaceCameraPos);

	return ShadowCameraTransform(resultPos, resultRot);
}


PointLight::PointLight(const glm::vec3& color, float intensity, const Attenuation& attenuation, const Shader& shader) :
	BaseLight(color, intensity, shader),
	m_attenuation(attenuation)
{
	float maxColorVal = color[0];

		for (int i = 0; i < 3; i++)
			if (color[i] > maxColorVal)
				maxColorVal = color[i];

	float a = m_attenuation.GetExponent();
	float b = m_attenuation.GetLinear();
	float c = m_attenuation.GetConstant() - COLOR_DEPTH * intensity * maxColorVal;

	m_range = (-b + sqrtf(b*b - 4 * a*c)) / (2 * a);
}

SpotLight::SpotLight(const glm::vec3& color, float intensity, const Attenuation& attenuation, float viewAngle,
	int shadowMapSizeAsPowerOf2, float shadowSoftness, float lightBleedReductionAmount, float minVariance) :
	PointLight(color, intensity, attenuation, Shader()),
	m_cutoff(cos(viewAngle / 2))
{
	if (shadowMapSizeAsPowerOf2 != 0)
	{
		SetShadowInfo(ShadowInfo(glm::perspective(viewAngle, 1.0f, 0.1f, GetRange()), false, shadowMapSizeAsPowerOf2,
			shadowSoftness, lightBleedReductionAmount, minVariance));
	}
}