
#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
   
// ambient
    float ambStrength = 0.1;
    vec3 ambient = ambStrength * lightColor;

    // calculate diffuse 
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - FragPos);
    float difference = max(dot(normal, lightDirection), 0.0);
    vec3 diffuse = difference * lightColor;

    // calculate specular
    float specStrength = 0.5;
    vec3 viewDirection = normalize(viewPos - FragPos);
    vec3 reflectDirection = reflect(-lightDirection, normal);  
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0),32);
    vec3 specular = specStrength * spec * lightColor;  

//combine them all together
    vec3 result = (ambient + diffuse + specular ) * objectColor;
    color = vec4(result, 1.0);

    
} 
