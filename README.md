# First Pong

My first game using sdl3. This is a simplified version of the original clasic "PONG!" and its rules are as follows

1. Only one life.
2. Speed increases by a factor after each swing (plus a correction depending on the paddle speed at impact)
3. Hitting the incoming ball with the side of the paddle closer to it will reflect it back while hitting it with the farther side will reflect it without changing its vertical speed
4. It gets a bit buggy when the upper part of the paddle hits xd

To build the project

-   Install the dependencies (SDL3, SDL3_image and zlib). I personally built them with cmake for windows.
-   Use cmake to build the project in a build folder
-   Make sure to copy SDL3.dll and SDL3_image.dll into the build folder

Once this is done, it should be able to be compiled and executed.
