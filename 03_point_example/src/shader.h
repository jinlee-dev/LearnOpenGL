#ifndef __SHADER_H__
#define __SHADER_H__

#include "common.h"

CLASS_PTR(Shader);
class Shader 
{
 public:
    /*
    Shader Unique Pointer 외에는 생성할 수 없도록 구현함.
    생성자가 Private 이기 때문.
    */
    // Shader 생성 함수
    static ShaderUPtr CreateFromFile(const std::string& filename,
        GLenum shaderType);

    ~Shader();
    // Shader 내부에서만 관련된 정보를 관리하기 위해 Set이 없음
    uint32_t Get() const { return m_shader; }    
private:
    Shader() {}
    bool LoadFile(const std::string& filename, GLenum shaderType);
    uint32_t m_shader { 0 };
};

#endif // __SHADER_H__