#pragma once

#include <glm/glm.hpp>

namespace Dorek::Math {

	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale);

}
