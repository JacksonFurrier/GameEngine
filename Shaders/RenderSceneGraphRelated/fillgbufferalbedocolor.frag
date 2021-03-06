#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(early_fragment_tests) in;

layout(set = 1, binding = 0, std140) uniform block {
	vec4 albedoColor;
};

layout(location = 0) in struct FS_IN {
	vec3 position;	
	vec3 tangent;
	vec3 normal;
	vec2 textureCoordinate;
}fs_in;

layout(location = 0) out vec4 outAlbedo;
layout(location = 1) out vec4 outTangent;
layout(location = 2) out vec4 outNormal;

void main() {
    outAlbedo = pow(albedoColor, vec4(2.2));
	outTangent = vec4(normalize(fs_in.tangent), 0.0);
	outNormal = vec4(normalize(fs_in.normal), 0.0);
}
