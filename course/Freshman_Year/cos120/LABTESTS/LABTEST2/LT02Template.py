testProblems={"raiseToPowerRecurse":True,
              "findPowLocations":False,
              "processByOffset":False,
              "sortBy100Counts":False,
              "findScoresLessThan":False,
              "findOddsEvens":False,
              "parallelListProc":False,
              "revChars":False,
              "revWordsChars":False,
              "displayClipRegion":False}

#LT02-01
def raiseToPowerRecurse(base,power):
    if power ==0:
        return 1
    return base*(raiseToPowerRecurse(base,power-1))

if testProblems["raiseToPowerRecurse"]:
    print(raiseToPowerRecurse(2,3),pow(2,3))
    print(raiseToPowerRecurse(2,4),pow(2,4))
    print(raiseToPowerRecurse(2,0),pow(2,0))
    print(raiseToPowerRecurse(-2,0),pow(-2,0))
    print(raiseToPowerRecurse(5,3),pow(5,3))
    print(raiseToPowerRecurse(-5,3),pow(-5,3))
    print(raiseToPowerRecurse(5,4),pow(5,4))
    print(raiseToPowerRecurse(-5,4),pow(-5,4))



#LT02-02
def findPowLocations(strng, base, maxPower):
    pass

if testProblems["findPowLocations"]:
    strng="Thequickbrownfoxjumpsoverthelazydog"
    print(findPowLocations(strng,2,0))
    print(findPowLocations(strng,2,1))
    print(findPowLocations(strng,2,2))
    print(findPowLocations(strng,2,3))
    print(findPowLocations(strng,2,4))
    print(findPowLocations(strng,2,5))
    print(findPowLocations(strng,2,6))
    print(findPowLocations(strng,4,0))
    print(findPowLocations(strng,4,1))
    print(findPowLocations(strng,4,2))
    print(findPowLocations(strng,4,3))



#LT02-03
def processByOffset(lst):
    newList=[]
    emptyList=[]
    if len(lst)%2==0:
        for letter in lst[:len(lst)//2]:
            x=chr(ord(letter.upper()))
            newList.append(letter+x)
        return newList
    else:
        return emptyList

if testProblems["processByOffset"]:
    aList=list("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    bList=aList[:-1]
    print(processByOffset(bList))
    print(processByOffset(["a"]))
    print(processByOffset(["abc"]))
    print(processByOffset(aList))



#LT02-04
def sortBy100Counts(LoL):
    LoL.sort(key=lambda x: x.count(100))
    return LoL

if testProblems["sortBy100Counts"]:
    s=[[67,100,100,100,88],[100,90,100,90,88],[100,29,88],[90,100,70,80]]
    print(sortBy100Counts(s))



#LT02-05
def findScoresLessThan(scoresD):
    x=int(input("Enter a score=>"))
    for aPerson in scoresD:
        newList=[]
        for grades in scoresD[aPerson]:
            if grades<=x:
                newList.append(grades)
        print(aPerson,newList)
        
                
if testProblems["findScoresLessThan"]:
    sD={"Sue":[67,100,100,100,88],"Mary":[88,90,65,90,88],"John":[77,29,100,32,88],"Joe":[90,90,70,70,80]}
    findScoresLessThan(sD)



#LT02-06
def findOddsEvens(LoL): 
    evenList=[]
    oddList=[]
    randomList=[]
    randomList2=[]
    newDict={}
    for aList in LoL:
        for number in aList:
            if number%2==0:
                randomList.append(number)
            else:
                randomList2.append(number)
            for aNumber in randomList2:
                if aNumber not in oddList:
                    oddList.append(aNumber)
                    newDict["odds"]=oddList
            for aNumber in randomList:
                if aNumber not in evenList:
                    evenList.append(aNumber)
                    newDict["evens"]=evenList
            
    return newDict

if testProblems["findOddsEvens"]:
    LoL=[[1,2,1,3,42,11],[16,1,3],[3,7,42],[67,7,76,8],[2,16,3,67]]
    print(findOddsEvens(LoL))



#LT02-07
def parallelListProc(nList,aList):
    pass

if testProblems["parallelListProc"]:
    nameList=["Sue","Joe","Bob","Ann","Tom","Hal"]
    ageList=[3,2,3,7,4,9]
    parallelListProc(nameList,ageList)



#LT02-08
def revChars(fileIn,fileOut):
    f2 = open(fileOut, "w")
    for line in open(fileIn, 'r').readlines():
        f2.write((line[::-1]))

    f2.close()

if testProblems["revChars"]:
    revChars("t1.txt","t2.txt")



#LT02-09
def revWordsChars(fileIn,fileOut):
    f1 = open(fileIn, "r")
    f2 = open(fileOut, "w")
    for line in f1:
        values=line.split()
        values.reverse()
        f2.write(line[::-1])
    
        
    
    
    f1.close()
    f2.close()

if testProblems["revWordsChars"]:
    revWordsChars("t1.txt","t2.txt")



#LT02-10
def displayClipRegion(inFile,llcol,llrow,urcol,urrow):
    pass

if testProblems["displayClipRegion"]:
    from cImage import *
    displayClipRegion("pencils.gif",50,200,200,50)
