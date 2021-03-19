from PIL import Image


'''
This is a challenge from ctftime of Nahamcon CTF2021
First thing that came to mind looking at this picture was that I could follow some path starting from the center arrow, and then use 0 or 1 from the tiles background, which would encode a message. Unfortunaly, I quickly noticed there are some loops in, and therefore took a step back.

I then looked closer: each tile actually has a different grayscale level. Maybe they encode different things? I suspected that we should start still from the red tile, so i checked the next few tiles in the sequence. Got it! They have grayscale values of 0x61, 0x6C, 0x67, 0x7B, which reads "lag{" in ASCII! Therefore the red tile is the "f", and we can read "flag{" to start with.

I took a risk and assumed that if I run the path from here automatically, surely the flag will appear (otherwise, well, F, i can try something different). Next step was to automate things quickly. I took the RGB values of each arrow at position (6, 32) in the tile because that's the position where, for any arrow type, we still hit a unique color identifying the arrow. Then I just use the directions to traverse and read the grayscale code of the tile and convert it to char. Loop until we hit an "}" character!

'''






# parse direction from colors
def getDirection(colorCode):
    r, g, b, _ = colorCode
    if(b > g and b > r and r > g):
        return "up"
    if(r > g and r > b):
        return "down"
    if(r < g and b < g):
        return "left"
    if(b > g and b > r and r < g):
        return "right"
    return "ERROR"

# pixel that always hits the arrow color
def getColorCode(pix, x, y):
    return pix[6+64*x, 32+64*y]

# decode bit to get ascii later
def getBit(pix, x, y):
    r, _, _, _ = pix[1+64*x, 1+64*y]
    return r

# load pixels
im = Image.open('ddr.png')
pix = im.load()
print(im.size)

# start from one step ahead (skip the red square, it's "f")
x = 11
y = 7
curr = 0
flag = "f"

# until you finish the flag
while chr(curr) != '}':
    curr = getBit(pix, x, y)
    flag += chr(curr)
    dir = getDirection(getColorCode(pix, x, y))
    if dir == "down":
        y += 1
    if dir == "up":
        y -= 1
    if dir == "left":
        x -= 1
    if dir == "right":
        x += 1
    x = x % 21
    y = y % 15
    print(flag)

# BINGO
print(f"\nfound it! {flag}")
