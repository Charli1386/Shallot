#include "shader.h"
#include "../utils/fileutils.h"

namespace shallot { namespace graphics {

	Shader::Shader(const char* vertexPath, const char* fragPath){
		m_vertexPath = vertexPath;
		m_fragPath = fragPath;

		m_ShaderID = load();		
	}

	Shader::~Shader(){
		glDeleteProgram(m_ShaderID);
	}

	GLuint Shader::load(){
		GLuint program = glCreateProgram(); // create shader program
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertexSourceString = read_file(m_vertexPath);
		std::string fragSourceString = read_file(m_fragPath);

		const char* vertexSource = vertexSourceString.c_str();
		const char* fragSource = fragSourceString.c_str();

		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE){
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length); 
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cerr << &error[0] << std::endl;
			std::cout << "Shader build fail..." << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(frag, 1, &fragSource, NULL);
		glCompileShader(frag);

		glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE){
			GLint length;
			glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length); 
			std::vector<char> error(length);
			glGetShaderInfoLog(frag, length, &length, &error[0]);
			std::cerr << &error[0] << std::endl;
			std::cout << "Shader Fragment build fail..." << std::endl;
			glDeleteShader(frag);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, frag);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(frag);

		return program;
	}

	void Shader::enable() const{
		glUseProgram(m_ShaderID);
	}

	void Shader::disable() const{
		glUseProgram(0);
	}

	GLint Shader::getUniformLocation(const GLchar* name){
		return glGetUniformLocation(m_ShaderID, name);
	}

	void Shader::setUniform1i(const char* name, int value){
		glUniform1i(getUniformLocation(name), value);
	}
	void Shader::setUniform2f(const char* name, const maths::vec2& vector){
		glUniform2f(getUniformLocation(name), vector.x, vector.y);
	}
	void Shader::setUniform3f(const char* name, const maths::vec3& vector){
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}
	void Shader::setUniform4f(const char* name, const maths::vec4& vector){
		glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	void Shader::setUniformMat4(const char* name, const maths::mat4& matrix){
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}


}}
