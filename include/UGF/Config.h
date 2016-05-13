/*
    Unimpressive Game Framework
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
        Libpng/zlib licence. Do what you want (even compile staticly). If you redistrubute the source don't remove information about authors.
  */


/*  POMYSLY:
 * - DEBUG MODE (Wizualny)
 * - Akcje
 * /?- Aktorzy właściwości
 * - Logger
 * * * * * * *
 * - AngelScript
 * - Savable
 * - SYaml
 * /
 *
 * /

 /*
  * ActorsSystem as;
  * PlayerController pc
  * Actor a = as.create(pc);
  * a.attachToBody(pc.getDefaultBody());
  *

/*
GUI:
Window
    name: "main_window"
    size:
        x: 400px
        y: 500px
    background:
        color:
            red: 100
            blue: 200
            green: 300
            alpha: 255

___________________________________
|top_left|    top    |top_right   |
|center_left|        |center_right|
|center_left|CENTER  |            |
|center_left|        |            |
|bottom_left|bottom  |bottom_right|

File = GUISkins/DefaultSkin.syaml

Skin:
    name: "monokai"
    img: "default_skin.png"
    for: "window"
    inherit: "default_window"
    bar:
        font: "Times New Roman"
        buttons: MXC
        side: right

    top:
        height: 10px

    left:
        width: 10px
        ima_arena:
            position: [20,20]
            size: [10,10]
        fill_mode:
            x: repeat
            y: repeat
    top_left:
        img_arena
    center:
        img: "different_img.png"
        img_arena:
            position:
                x: 100
                y: 100
            size:
                x: 200
                y: 400
        fill_mode:
            x: strech #or strech_when_bigger
            y: repeat
*/

/*
 *
 * TextureQuad : texture, rect
 PhysicsHelpers:
 PlatformerBody(b2Vector);
 Rope(b2Vec bpos, b2Vec2 epos, float lenght = -1, b2Body, b2Body);
    setTextureForAll();
    vector<Chain> getChains();

    ugf::Box2D::CreatePlatformerCharacter(world, position, size);

 Controllers:
    BoxController
    StaticBoxController
