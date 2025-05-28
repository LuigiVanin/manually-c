#include "lib/d_array_list.h"
#include "raylib.h"
#include "util.h"
#include <stddef.h>
#include <stdio.h>

int main() {
  ArrayList list = NewArrayList(Color, 18);

  PushItem(&list, LIGHTGRAY);
  PushItem(&list, RED);
  PushItem(&list, BLUE);
  PushItem(&list, BLACK);
  PushItem(&list, GREEN);
  PushItem(&list, BLACK);
  PushItem(&list, BLACK);

  print_list((int *)list.data, list.length);

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example");
  SetTargetFPS(10);

  float gap = screenWidth / (float)list.length;
  float initialPosition = gap / 2;

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText(                        //
        "Clang and Raylib example!", //
        10, 10, 19,                  //
        BLACK                        //
    );

    for (size_t i = 0; i < list.length; i++) {
      auto color = GetAt(Color, list, i);
      DrawCircle(                      //
          initialPosition + (i * gap), //
          screenHeight / 2, 20,        //
          color                        //
      );
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}