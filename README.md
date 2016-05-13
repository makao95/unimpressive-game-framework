# Unimpressive Game Framework #
 is a framework build around SFML and Box2D, it contains some basic reusable tools such as:
 * ResourceManager (for textures, fonts, sounds)
 * ParticleSystem
 * Box2D integration (optional in the future)
 * Ini files support
 * Bitmap based fonts
 * Very basic gui (buttons)
 * Framecounter

 Planned or in development
 * Basic actors system with fast drawing (for quad-based sprites)
 * AngelScript support (optional)
 * Lua support (optional)
 * Lighweight bus/actions system for communication between classes
 * Graphical Console
 * Android support

### Why is it named framework instead of engine? ###
A framework is providing you tools, but it is not forcing you to use all of them. You may find some of these classed too simple.

### Does it have some examples? ###
Yes. And there will be more.

### What's the licence? ###
Libpng/zlib licence. Do what you want (even compile staticly). If you redistrubute the source don't remove information about authors.

### How to build ###
`cd ugf-master
mkdir build && cd build
cmake -DBUILD_EXAMPLES=ON -DCMAKE_SHARED=ON ..
make`
-DBUILD_EXAMPLES=ON and -DCMAKE_SHARED=ON are optional
if you have your libraries in non-default location use
`-DCMAKE_LIBRARY ... =/my/location`
if you want to install UGF in specific location use
`-DCMAKE_INSTALL_PREFIX=/my/location`
