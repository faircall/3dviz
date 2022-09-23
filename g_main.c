#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"

int screen_width = 1280;
int screen_height = 800;

float deg_to_rad(float deg)
{
    return (deg * PI) / 180.0f;
}

Vector3 vec3_set(float x, float y, float z)
{
    Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    
    return result;
}

float my_cos(float angle)
{
    return cos(deg_to_rad(angle));
}

float my_sin(float angle)
{
    return sin(deg_to_rad(angle));
}

float my_tan(float angle)
{
    return tan(deg_to_rad(angle));
}

int main(int argc, char **argv)
{
    InitWindow(screen_width, screen_height, "3d viz");

    float angle = 0.0f;

    Camera camera = {0};
    camera.position = vec3_set(5.0f*my_cos(angle),5.0f, 5.0f*my_sin(angle));
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    Vector3 bx = {1.0f, 0.0f, 0.0f};
    Vector3 by = {0.0f, 1.0f, 0.0f};
    Vector3 bz = {0.0f, 0.0f, 1.0f};


    Vector3 v1 = {2.5f, 2.0f, 2.5f};

    // want to be able to rotate the camera

    while (!WindowShouldClose()) {
	float dt = GetFrameTime();
	
	// update camera
	angle += (10.0f*dt);
	camera.position = vec3_set(5.0f*my_cos(angle),5.0f, 5.0f*my_sin(angle));
	
	BeginDrawing();
	
	ClearBackground(RAYWHITE);

	BeginMode3D(camera);
	// draw basis
	DrawLine3D((Vector3){0.0f, 0.0f, 0.0f}, bx, RED);
	DrawLine3D((Vector3){0.0f, 0.0f, 0.0f}, by, GREEN);
	DrawLine3D((Vector3){0.0f, 0.0f, 0.0f}, bz, BLUE);
	// draw others
	DrawLine3D((Vector3){0.0f, 0.0f, 0.0f}, v1, BLACK);
	
	EndMode3D();
	
	EndDrawing();
    }
	
    
    return 0;
}
