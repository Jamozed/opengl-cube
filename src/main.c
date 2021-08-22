// main.c
// Main source file for opengl-cube
// Copyright (C) 2021, Jakob Wakeling
// All rights reserved.

#include <raylib.h>
#include <raymath.h>

int main(int ac, char *av[]) {
	InitWindow(640, 480, "OpenGL-Cube");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	// SetTargetFPS(240);
	
	Camera3D camera = { 0 };
	camera.position   = (Vector3){ 8.0f, 8.0f, 8.0f };
	camera.target     = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up         = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy       = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	
	Model cube = LoadModelFromMesh(GenMeshCube(4.0f, 4.0f, 4.0f));
	Vector3 cubePos = { 0.0f, 0.0f, 0.0f }, cubeRot = { 0.0f, 0.0f, 0.0f };
	
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		
		cubeRot.x += 1.0f * dt; cubeRot.y += 1.0f * dt; cubeRot.z += 1.0f * dt;
		cube.transform = MatrixRotateXYZ(cubeRot);
		
		BeginDrawing(); ClearBackground(BLACK);
		BeginMode3D(camera);
		
		DrawModel(cube, cubePos, 1.0f, DARKBROWN);
		DrawModelWires(cube, cubePos, 1.0f, (Color){ 106, 93, 77, 255 });
		
		EndMode3D();
		
		DrawText("OpenGL-Cube", 10, 10, 16, WHITE);
		DrawFPS(10, 32);
		
		EndDrawing();
	}
	
	CloseWindow(); return 0;
}
