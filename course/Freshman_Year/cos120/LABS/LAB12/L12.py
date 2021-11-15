#L12-01
def mergeLists(list1,list2):
    return list1+list2

#L12-02
def averageOfEachList(aListOfLists):
    newList=[]
    for aList in aListOfLists:
        aList=sum(aList)/len(aList)
        newList.append(aList)
    return newList

#L12-03
def howManyHaveDupes(aListOfLists):
    newList=[]
    count=0
    for aList in aListOfLists:
        newList=[]
        for number in aList:
            if number not in newList:
                newList.append(number)
            else:
                count+=1
                break
    return count

#L12-04
def arrangeTheLists(aListOfLists):
    aListOfLists.sort(key=sum,reverse=True)
    return aListOfLists

#L12-05
def printReport(aDictionary):
    for key in aDictionary:
        average=0
        for value in aDictionary[key]:
            average+=value
        x=average/len(aDictionary[key])
        print(key,round(x,1))

#L12-06
def createDictionary(aDictionary):
    newDict={}
    for key in aDictionary:
        average=0
        for value in aDictionary[key]:
            average+=value
        x=average/len(aDictionary[key])
        newDict[key]=round(x,1)
    return newDict

#L12-07
def mergeDictionaries(dict1,dict2):
    newDict={}
    for key in dict1:
        if key in dict2:
            dict2[key]=dict2[key]+dict1[key]
    newDict.update(dict1)
    newDict.update(dict2)
    return newDict

#L12-08
def howManyWordOccurrences(sentence1,sentence2):
    x=sentence1.lower()
    y=sentence2.lower()
    sentenceSplit=x.split()
    sentence2Split=y.split()
    newDict={}
    for word in sentenceSplit:
        newDict[word]=0
    for word in sentence2Split:
        if word in sentenceSplit:
            newDict[word]+=1
    for key in newDict:
        print(key,newDict[key])

#L12-09
def compFiles(file1, file2):
    f1 = open(file1, "r")
    f2 = open(file2, "r")
    for line1 in f1:
        for line2 in f2:
            if line1==line2:
                return True
            else:
                return False
    f1.close()
    f2.close()

#L12-10
def readAndProcess(inFileName, outFileName):
    f1=open(inFileName, "r")
    f2=open(outFileName, "w")
    answer=0
    for line in f1:
        random=list("".join(line.split()))
        for char in random:
            answer+= int(char)
        print(answer)
        f2.write(str(answer)+'\n')
    f1.close()
    f2.close()

#L12-11
def intMultiply(multiplicand, multiplier):
    if multiplier == 0:
        return 0
    return multiplicand + (intMultiply(multiplicand, multiplier - 1))

#L12-12
def showGrades(classD):
    userInput=input("What class?")
    for aPerson in classD[userInput]:
        grades=classD[userInput][aPerson]
        avg=sum(grades)/len(grades)
        print(aPerson,avg)
    

#L12-13
def studentInMoreThanOneClass(classD):
    newDict={}
    newList=[]
    for aClass in classD:
        for aPerson in classD[aClass]:
            if aPerson in newDict:
                newDict[aPerson] += 1
            else:
                newDict[aPerson]=1
    for key in newDict:
        if newDict[key]>1:
            newList.append(key)
    return newList
            


#L12-14
def translateLtoD(inList):
    newDict={}
    newDict2={}
    for alist in inList:
        newDict[alist[1]]=alist[0]
        newDict2[alist[0]]=alist[1]
    newDict2.update(newDict)
        
    return newDict2


    
            
    
    


def main():
    manyLists=[[2,1,3,1,3,2],[3,4,5,6,7],[9,4,2,7,8,6,3,1,9],[12,3,2,1,2]]
    moreLists = [[5,4,6],[2,1,3,9],[6,7,5,8,4]]
    d1={"Bob":[5,4,3,2,1,2],"Sue":[2,3,1,4,4,3,2],"Jill":[6,5,6,4,3,1]}
    d2={"Joe":[3,1,4,4],"Sally":[5,1,3,7],"Bob":[2,2,3,3,2]}
    a="This is a test of my python skills"
    b="Python is my natural language"
    #print(mergeLists(manyLists,moreLists))
    #print(averageOfEachList(manyLists))
    #print(howManyHaveDupes(manyLists))
    #print(arrangeTheLists(manyLists))
    #printReport(d1)
    #print(createDictionary(d1))
    #print(mergeDictionaries(d1,d2))
    #howManyWordOccurrences(a,b)
    #print(compFiles("first1.txt", "second1.txt"))
    #readAndProcess("afile1.txt", "afile2.txt")
    print(intMultiply(5, 0))
    #showGrades({"COS120":{"Bob":[98,100,100,88],"Sue":[100,88,100,100],"Jill":[100,100,100,100]},"ENG110":{"Sue":[100,100,100,100,88],"Mary":[88,90,88,90,88],"John":[100,100,100,100,100],"Joe":[90,90,70,70,80]},"BIB231":{"Bob":[98,100,100,88],"Sue":[88,88,88,88],"Jill":[100,100,100,100]}}) 
    #print(studentInMoreThanOneClass({"COS120":{"Bob":[98,100,100,88],"Sue":[100,88,100,100],"Jill":[100,100,100,100]},"ENG110":{"Sue":[100,100,100,100,88],"Mary":[88,90,88,90,88],"John":[100,100,100,100,100],"Joe":[90,90,70,70,80]},"BIB231":{"Bob":[98,100,100,88],"Sue":[88,88,88,88],"Jill":[100,100,100,100]}})) 
    #print(translateLtoD([['Indiana','Indianapolis'],['Ohio','Columbus'],['New York','New York'],['Virginia','Richmond']]))

main()
