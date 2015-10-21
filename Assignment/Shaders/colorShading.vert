#version 330

in vec3 vertexPosition;
in vec4 vertexColor;
in vec3 vertexNormal;
in vec2 vertexUV;

out vec2 fragmentPosition;
out vec4 fragmentColor;
out vec2 fragmentUV;

void main() {

    gl_Position.xyz = vertexPosition;
    
    gl_Position.w = 1.0;
    
    fragmentPosition = vertexPosition.xy;
    
    fragmentColor = vertexColor;

	fragmentUV = vec2(vertexUV.x, -vertexUV.y);
}