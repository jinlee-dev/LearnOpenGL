#ifndef __COMMON_H__
#define __COMMON_H__

#include <memory>
#include <vector>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>

/* Macro로 되어 있는 함수를 선언
    Define을 여러 줄로 쓰고 싶을 경우, 역슬래쉬를 붙여줌
## : 붙여주는 역할을 수행
E.g)
아래와 같이 선언을 해 놓으면,
CLASS_PTR(Shader);
아래와 동일한 코드가 전처리 시점에 붙는다.
using ShaderUPtr = std::unique_ptr<Shader>;
using ShaderPtr = std::shared_ptr<Shader>;
using ShaderWPtr = std::weak_ptr<Shader>;
*/ 
#define CLASS_PTR(klassName) \
class klassName; \
using klassName ## UPtr = std::unique_ptr<klassName>; \
using klassName ## Ptr = std::shared_ptr<klassName>; \
using klassName ## WPtr = std::weak_ptr<klassName>;
std::optional<std::string> LoadTextFile(const std::string &fileName);

#endif // __COMMON_H__
