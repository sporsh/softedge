#ifndef RENDERCONTEXT_H_
#define RENDERCONTEXT_H_

namespace softedge {

enum RasterizationMode {
    POINT, WIRE, FILL
};

enum ShadingMethod {
    FLAT, // Use the same color over entire surface.
    GOURAUD, // Interpolate colors between vertices.
    PHONG, // Interpolate normals and calculate illumination for each pixel.
    REAL
// Calculate normals and illumination for each pixel.
};

enum ReflectionModel {
    NONE,       // Use whatever color we have.
    LAMBERT,
    PHONG,
    BLINN_PHONG,
    COOK_TORRANCE,
    OREN_NAYAR
};

struct RenderContext {
    RasterizationMode rasterization_mode;
    ShadingMethod shading_method;
    ReflectionModel reflection_model;
};

} /* namespace softedge */
#endif /* RENDERCONTEXT_H_ */
