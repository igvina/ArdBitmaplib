
#include <Arduboy.h>
#include <ArdBitmaplib.h>
#include "bitmaps.h"

// make an instance of arduboy used for many functions
Arduboy arduboy;

ArdBitmaplib ardbitmap (arduboy.getBuffer());

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();
  arduboy.setFrameRate(60);
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  arduboy.clear();

  ardbitmap.drawCompressedResized(WIDTH / 2 ,HEIGHT, BOY, WHITE, ALIGN_H_CENTER | ALIGN_V_BOTTOM, MIRROR_NONE, 0.5);

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}
