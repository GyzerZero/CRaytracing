#include "vec3.h"
#include "camera.h"

int main()
{
    camera cam;

    cam.imageWidth = 1920;
    cam.aspectRatio = 16.0 / 9.0;
    cam.hFov = 90;
    cam.focalLength = 1.0;
    cam.lookAt = (vec3){0, 0, 1};
    cam.position = (vec3){0, 0, 0};
    cam.up = (vec3){0, 1, 0};
}