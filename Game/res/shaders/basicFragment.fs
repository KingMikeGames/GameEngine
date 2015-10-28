#version 330

in vec4 colour;
in vec2 texCoord0;

out vec4 fragColor;
uniform sampler2D sampler;

void main()
{
	//fragColor = colour;
	gl_FragColor = texture2D(sampler, texCoord0.xy) * colour;
}