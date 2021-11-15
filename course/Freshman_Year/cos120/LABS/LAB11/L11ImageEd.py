from cImage import*
     

def sepiaPixel(p):
    r = p.getRed()
    g = p.getGreen()
    b = p.getBlue()
    r = (r*.393)+(g*.769)+(b*.189)
    g = (r*.349)+(g*.686)+(b*.168)
    b = (r*.272)+(g*.534)+(b*.131)
    if r>255:
        r=255
    if g>255:
        g=255
    if b>255:
        b=255
    return Pixel(int(r),int(g),int(b))
    
    

def blackAndWhite(p,threshold):
    r=p.getRed()
    g=p.getGreen()
    b=p.getBlue()
    if r+g+b>threshold*3:
        r=255
        g=255
        b=255
    else:
        r=0
        g=0
        b=0
    return Pixel(int(r),int(g),int(b))

def grayPixel(p):
    nc=(p.getRed()+p.getGreen()+p.getBlue())//3
    return Pixel(nc,nc,nc)


def negativePixel(p):
    r=255-p.getRed()
    g=255-p.getGreen()
    b=255-p.getBlue()
    return Pixel(r,g,b)


def RGBAdjust(img,redA,greenA,blueA):
    r = img.getRed() * redA
    g = img.getGreen() * greenA
    b = img.getBlue() * blueA
    if r>255:
        r=255
    if g>255:
        g=255
    if b>255:
        b=255
    if r<0:
        r=0
    if g<0:
        g=0
    if b<0:
        b=0
    return img
    

def oneThirdSize():
    pass

def pixelMapper(rgbFunction,oldImage,title):
    if rgbFunction==RGBAdjust:
        redA=float(input("Enter an adjustment for red"))
        greenA=float(input("Enter an adjustment for green"))
        blueA=float(input("Enter an adjustment for blue"))
    if rgbFunction==blackAndWhite:
        threshold=int(input("What's the threshold?"))
    width = oldImage.getWidth() 
    height = oldImage.getHeight() 
    myImageWindow = ImageWin(title, width*2, height)
    oldImage.draw(myImageWindow)
    newIm = EmptyImage(width,height)
    for row in range(height):
        for col in range(width):
            originalPixel = oldImage.getPixel(col,row)
            if rgbFunction==RGBAdjust:
                newPixel = rgbFunction(originalPixel,redA,greenA,blueA)
            elif rgbFunction==blackAndWhite:
                newPixel = rgbFunction(originalPixel,threshold)
            else:
                newPixel = rgbFunction(originalPixel)
            newIm.setPixel(col,row,newPixel)
    newIm.setPosition(width + 1, 0) 
    newIm.draw(myImageWindow)
    myImageWindow.exitOnClick()
    

def imageProc(fname):
    if fname!="":
        myImage=FileImage(fname)
    else:
        myImage=""
    answer=0
    while answer != 9:
        if myImage !="":
            print("1) Load an image\n2) Adjust RGB values\n3) Produce a gray-scale image of the current image\n4) Produce a black and white of the current image\n5) Produce a sepia-toned image of the current image\n6) Produce a negative of the current image\n7) Reduce image size by 2/3 (1/3 the original pixels)\n8) Save the modified image\n9) Exit")
            answer=int(input("Select a menu choice => "))
            while answer not in [1,2,3,4,5,6,7,8,9]:
                print("1) Load an image\n2) Adjust RGB values\n3) Produce a gray-scale image of the current image\n4) Produce a black and white of the current image\n5) Produce a sepia-toned image of the current image\n6) Produce a negative of the current image\n7) Reduce image size by 2/3 (1/3 the original pixels)\n8) Save the modified image\n9) Exit")
                answer=int(input("Select a menu choice => "))
        else: #the default image is not present
            print("1) Load an image\n9) Exit")
            answer=int(input("Select a menu choice => "))
            while answer not in [1,9]:
                print("1) Load an image\n9) Exit")
                answer=int(input("Select a menu choice => "))
            
        if answer==1:
            image1 = input("Enter an image file")
            myImage = FileImage(image1)
            myWin = ImageWin(myImage,800,400)
            myImage.draw(myWin)
            
        elif answer==2:
            pixelMapper(RGBAdjust,myImage,"RGBAdjusted Image")
        elif answer==3:   
            pixelMapper(grayPixel,myImage,"Grayscale Image")
        elif answer==4:
            pixelMapper(blackAndWhite,myImage,"BlackWhite")
        elif answer==5:
            pixelMapper(sepiaPixel,myImage,"Sepia Image")
        elif answer==6:
            pixelMapper(negativePixel,myImage,"Negative Image")
        elif answer==7:
            pass #Your code here
        elif answer==8:
            myImage.save("pencils.gif")
        elif answer==9:
            print("Terminating program")
            return

#imageProc("stmarks.gif")
imageProc("")
