# Unimpressive Game Framework #
 is a framework build around SFML and Box2D, it contains some basic reusable tools such as:
 * ResourceManager (for textures, fonts, sounds)
 * ParticleSystem
 * Box2D integration (optional in the future)
 * Basic actors system with fast drawing (for quad-based sprites)
 * Ini files support
 * AngelScript support (optional)
 * Lua support (optional)
 * Bitmap based fonts
 * Lighweight bus/actions system for communication between classes
 * Console
 * Very basic gui (buttons)
 * Framecounter
 * Android support

### Why is it named framework instead of engine? ###
A framework is providing you tools, but it is not forcing you to use all of them. You may find some of these classed too simple.

### Does it have some examples? ###
Yes. The sources are in examples folder and there you can see some video: youtube/adf42d

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



### What is this repository for? ###

* Quick summary
* Version
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

    # Unimpressive Game Framework #
    is a framework build around SFML and Box2D, it contains some basic reusable tools such as:
    * ResourceManager (for textures, fonts, sounds)
    * ParticleSystem
    * Box2D integration (optional in the future)
    * Basic actors system with fast drawing (for quad-based sprites)
    * Ini files support
    * AngelScript support (optional)
    * Lua support (optional)
    * Bitmap based fonts
    * Lighweight bus/actions system for communication between classes
    * Console
    * Very basic gui (buttons)
    * Framecounter
    * Android support
    Why is it named framework instead of engine?
        A framework is providing you tools, but it is not forcing you to use all of them. You may find some of these classed too simple.
    Does it have some examples?
        Yes. The sources are in examples folder and there you can see some video: youtube/adf42d
    What's the licence?
        Libpng/zlib licence. Do what you want (even compile staticly). If you redistrubute the source don't remove information about authors
