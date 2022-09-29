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

		const char* vertexSource = read_file(m_vertexPath).c_str();
		const char* fragSource = read_file(m_fragPath).c_str();

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

}}
