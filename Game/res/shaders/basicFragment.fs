#version 330

in vec2 texCoord0;
in vec4 colour;

uniform vec3 color;
uniform sampler2D sampler;

void main()
{
	vec4 textureColor = texture2D(sampler, texCoord0.xy);
	//gl_FragColor = textureColor * vec4(color, 1);
	gl_FragColor = colour;
}