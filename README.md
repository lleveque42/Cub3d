# Cub3d for 42cursus.
This project is inspired by the world-famous eponymous 90's game "wolf3d", which was the first FPS ever. 
The goal is to explore ray-casting making dynamic view inside a maze, in which we'll have to find our way, 
improving our skills in differents areas : windows, colors, events, fill shapes, etc. 
We had to work as a duo with @Rudyar to realise this project.

### Prerequisites :wrench:

    sudo apt-get install libx11-dev
    sudo apt-get install libxext-dev
    sudo apt-get install zlib1g-dev

### Our grade :mortar_board:
[![lleveque's 42 cub3d Score](https://badge42.vercel.app/api/v2/clc6bxaur00060fmon220zhly/project/2595433)](https://github.com/JaeSeoKim/badge42)

### Usage :desktop_computer:

#### :warning: Only works on linux :warning:

First:

    git clone https://github.com/lleveque42/Cub3d
    cd Cub3d
    
Then:
    
    make
    
<p align="center">
    <img src="https://github.com/Rudyar/Cub3d/blob/master/readme/make-cub3d.gif">
</p>

And finally:

    ./cub3d maps/map.cub

It will create a new window where you'll be able to play the game.

<p align="center">
    <img src="https://github.com/Rudyar/Cub3d/blob/master/readme/run-cub3d.gif">
</p>

The W, A, S, and D keys can be used to move the character, and the left and right arrows to look left or right.
You can go forward, backward, left and right. 
Pressing ESC or clicking the cross on the window's frame will close the game.

You can design your own maps by modifying map.cub or creating a new .cub file :

- You can add your own textures by changing the NO, SO, WE and EA paths. Textures must be XPM files.

- You can choose the floor and ceiling color by modifying respectively the RGB behind F and C.

- The map can be composed of only 3 characters:
  - 0 for an empty space  
  - 1 for a wall
  - And one of these 4 characters:
    - N for a player facing North
    - E for a player facing East
    - W for a player facing West
    - S for a player facing South

The map must at least be surrounded by walls and contain a player.  

This is a valid map:
   
    NO ./assets/greystone.xpm
    SO ./assets/redbrick.xpm
    WE ./assets/mossy.xpm
    EA ./assets/eagle.xpm
    F 142,95,39
    C 15,99,153

    111 111111111  
    10111000001  
    1000001110011  
    1N00111000001  
    11111 1111111  

This is not a valid map:

    NO ./assets/greystone.xpm
    SO ./assets/redbrick.jpg
    WE ./assets/mossy.xpm
    EA ./assets/eagle.xpm
    F 142
    C 15,99,153
    
    111111111  
    1001000001111  
    1000011111001  
     11011E000001  
    1111111100111  
