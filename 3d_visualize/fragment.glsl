#version 420

in vec3 pass_Normal;
in float pass_Height;

out vec4 out_Color;

void main()
{
    vec3 norm = normalize(pass_Normal);

    vec3 lightDir   = normalize(vec3(0.f, -1.f, 0.f));
    float fac       = max(dot(norm, lightDir), 0.0f);

    vec4 result = vec4(pass_Height / 255.f, .8f, .4f, 1.f) * fac;

    out_Color = result;
}
