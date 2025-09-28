#include "camera.h"

#include <cmath>

void createCamera(camera *c)
{
    c->imageHeight = (int)(c->imageWidth / c->aspectRatio);
    c->imageHeight = (c->imageHeight < 1) ? 1 : c->imageHeight;

    c->viewportWidth = 2 * c->focalLength * tan(c->hFov / 2); // Set because of isosceles triangle with base viewport width, hieght focal length, and angle hfov
    c->viewportHeight = c->viewportWidth / c->aspectRatio;

    c->w = vec3Normalize(c->lookAt);
    c->u = vec3Normalize(vec3Cross(c->w, c->up));
    c->v = vec3Cross(c->u, c->w);

    c->viewportU = (vec3){c->viewportWidth, 0, 0};
    c->viewportV = (vec3){0, -c->viewportHeight, 0};

    c->pixelDeltaU = vec3Div(c->viewportU, c->imageWidth);
    c->pixelDeltaV = vec3Div(c->viewportV, c->imageHeight);

    vec3 halfViewportU = vec3Div(c->viewportU, 2);
    vec3 halfViewportV = vec3Div(c->viewportV, 2);

    c->viewportUpperLeft = vec3Sub(vec3Sub(vec3Sub(c->position, (vec3){0, 0, c->focalLength}), halfViewportU), halfViewportV);
    c->pixel00Location = vec3Add(c->viewportUpperLeft, vec3Scale(vec3Add(c->pixelDeltaU, c->pixelDeltaV), 0.5));
}