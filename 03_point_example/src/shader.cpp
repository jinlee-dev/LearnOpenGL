#include "shader.h"

Shader::~Shader()
{
    if (m_shader) 
    {
        glDeleteShader(m_shader);
    }
}

ShaderUPtr Shader::CreateFromFile(const std::string& filename,
  GLenum shaderType) 
  {
    // 내부에서 Shader를 생성.
    // 생성 완료된 정보를 std::move를 이용하여 반환
    auto shader = ShaderUPtr(new Shader());
    if (!shader->LoadFile(filename, shaderType))
        return nullptr;
    return std::move(shader);
}

bool Shader::LoadFile(const std::string& filename, GLenum shaderType) 
{
    auto result = LoadTextFile(filename);
    if (!result.has_value())
        return false;

    // Reference로 해서 복사가 안일어나도록 했음. Reference를 안쓰면 그냥 string으로 취급함
    auto& code = result.value();
    const char* codePtr = code.c_str();
    int32_t codeLength = (int32_t)code.length();

    // create and compile shader
    // Create 하면 정수값으로 나옴.
    m_shader = glCreateShader(shaderType);
    
    // Shader의 코드를 로딩함.
    glShaderSource(m_shader, 1, (const GLchar* const*)&codePtr, &codeLength);
    
    // Shader Compile
    glCompileShader(m_shader);

    // check compile error
    int success = 0;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);
    
    if (!success) 
    {
        char infoLog[1024];
        // Compile 결과를 가지고 옴
        glGetShaderInfoLog(m_shader, 1024, nullptr, infoLog);
        SPDLOG_ERROR("failed to compile shader: \"{}\"", filename);
        SPDLOG_ERROR("reason: {}", infoLog);
        return false;
    }
    return true;
}



