#include "lib/d_array_list.h"
#include "raylib.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x = NULL;
  int arraySize = 10;

  ArrayList b = NewArrayList(int, 18);

  int value = 90;
  int value2 = 10909;

  PushItemInternal(&b, &value);
  PushItem(&b, value);
  PushItem(&b, 20);
  PushItem(&b, 10);
  PushItem(&b, 30);
  PushItem(&b, value);
  PushItem(&b, value2);
  PushItem(&b, 80);
  PushItem(&b, 30);
  PushItem(&b, 60);
  PushItem(&b, 30);
  PushItem(&b, 20);
  PushItem(&b, 10);

  print_list((int *)b.data, b.length);

  PopItem(&b);
  PopItem(&b);
  PopItem(&b);

  print_list((int *)b.data, b.length);

  RemoveAt(&b, 1);
  RemoveAt(&b, 1);
  // RemoveAt(&b, 3);

  print_list((int *)b.data, b.length);

  int y = GetAt(int, b, 2);

  printf("Type size %zu: \n", b.element_size);

  printf("Value %d: \n", y);

  x = (int *)calloc(arraySize, sizeof(int));

  if (x == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  for (int i = 0; i < arraySize; i++) {
    printf("Number at %d equals to %d\n", i, x[i]);
  }

  printf("\n");
  InsertAt(x, 3, 1000);
  printf("\n\n");

  for (int i = 0; i < arraySize; i++) {
    printf("Number at %d equals to %d\n", i, x[i]);
  }

  printf("\nFinished Program!\n");

  // const int screenWidth = 800;
  // const int screenHeight = 450;

  // InitWindow(screenWidth, screenHeight, "raylib [core] example -
  // basicwindow"); SetTargetFPS(60);

  // while (!WindowShouldClose()) {
  //   BeginDrawing();
  //   ClearBackground(RAYWHITE);
  //   DrawText("Congrats! You created your first window!", 190, 200, 20,
  //            LIGHTGRAY);
  //   EndDrawing();
  // }

  // CloseWindow();
  return 0;
}