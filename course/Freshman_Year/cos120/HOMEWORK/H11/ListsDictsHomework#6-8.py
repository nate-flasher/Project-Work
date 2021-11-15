#L10-06
def lookupD(aDictionary):
    x=input("State or capitol name?")
    if x != "quit":
        if x in aDictionary:
            print(aDictionary[x])
            
        else:
            found=False
            for key,value in aDictionary.items():
                if value==x:
                    found=True
                    print(key)
            if not found:
                print("Not found")        

    else:
        print("Program Terminated")

#L10-07
def calcGrades(classD):
    for aClass in classD:
        print(aClass)
        for student in classD[aClass]:
            gradeSum=0
            for grade in classD[aClass][student]:
                gradeSum+=grade
            average=gradeSum/len(classD[aClass][student])
            letter=''
            if average >=90 and average <=100:
                letter="A"
            if average >=80 and average <=90:
                letter="B"
            
                
            
                
                
            print("     ",student,'',letter)
            


#L10-08
def convertD(classD):
    newDict={}
    for aClass in classD:
        for student in classD[aClass]:
            if student not in newDict:
                newDict[student]={aClass:classD[aClass][student]}
            else:
                newDict[student][aClass]=classD[aClass][student]
        
    print(newDict)
                
    


def main():
    classGrades={"COS120":{"Bob":[98,100,100,88],"Sue":[100,88,100,100],"Jill":[100,100,100,100]},"ENG110":{"Sue":[100,100,100,100,88],"Mary":[88,90,88,90,88],"John":[100,100,100,100,100],"Joe":[90,90,70,70,80]},"BIB231":{"Bob":[98,100,100,88],"Sue":[88,88,88,88],"Jill":[100,100,100,100]}}
    #lookupD({"Alaska":"Juneau","Idaho":"Boise","Ohio":"Columbus"})
    #calcGrades(classGrades)
    convertD(classGrades)


main()
