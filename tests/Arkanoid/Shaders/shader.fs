#version 330 core

out vec4 FragColor;

in vec3 normal;
in vec3 fragPos;

vec3 objectColor = vec3(1.0f, 1.0f, 1.0f);
vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

float ambientStrenght = 1.0f;
uniform vec3 lightPos;

uniform vec3 viewPos;
int shininess = 64;
float specularStrength = 0.5f;

void main(){

	vec3 ambient = ambientStrenght * lightColor;

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), shininess);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 phong = (ambient + diffuse + specular) * objectColor;

	FragColor = vec4(phong, 1.0f);
}