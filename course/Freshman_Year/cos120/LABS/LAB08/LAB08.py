#L08-01
def function1():
    rainfile = open("rainfall.txt", "r")
    outfile = open("rainfallfmt.txt","w")

    for aline in rainfile:
        values=aline.split()
        a=values[0]
        b=float(values[1])
        x="%+25s %.1f\n" % (a,b)
        outfile.write(x)

    rainfile.close()
    outfile.close()

#L08-02
def function2():
    afile = open("tempconv.txt", "w")

    afile.write("%+10s %10s\n" % ("Fahrenheit","Celsius"))
    for aline in range(-300,212):
        a=aline
        b=(aline-32)*(5/9)
        x="%+10.3f %10.3f\n" % (a,b)
        afile.write(x)
    

    afile.close()

#L08-03

#All the remianing lines that have not been read by the readline() method.

#L08-04

#This time instead of there being lines standing alone, all the lines are put into one huge list. Using readline() calls ones line at a time while using readlines() calls the whole file into one huge line.

#L08-05
def function5():
    psalmfile = open("Psalm112.txt", "r")
    outfile = open("Psalm112Upper.txt","w")
    lines = psalmfile.readline()
    
    for aline in psalmfile:
        
        values=aline.split()
        x=aline.upper()
        outfile.write(x)


    outfile.close()
    psalmfile.close()
    
    
        
#L08-06
def function6():
    psalmfile = open("Psalm112.txt", "r")
    lines=psalmfile.read()
    numOfLines=len(lines)
    numOfWords=len(lines.split())
    numOfLines=len(lines.splitlines())
    
    print("Number of lines:",(numOfLines),"\n"+"Number of words:",(numOfWords),"\n"+"Number of characters:",(numOfLines))

    psalmfile.close()

#L08-07
def concord(filename):
    infile = open(filename, "r")
    outfile=open("concord.txt", "w")
    lines = infile.readlines()
    wordsdict = {}
    #print(lines)
    currentline = 0
    for line in lines:
        #print(line)
        words = line.split()
        for word in words:
            if word in wordsdict:
                if currentline not in wordsdict[word]:
                    wordsdict[word].append(currentline)
            else:
                wordsdict[word] = [currentline]
        currentline = currentline + 1
    print(wordsdict)
    for item in wordsdict:
        #pretty print item key + arrray + new line
        a=item
        b=wordsdict[item]
        x="%s %5s\n" % (a,b)
        outfile.write(x)
        
    outfile.close()
    infile.close()
    


def main():
    #function1()
    #function2()
    #function5()
    #function6()
    concord("restaurant.txt")
    


main()
