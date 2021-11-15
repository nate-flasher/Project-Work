#L06-1
def showListFunctions(myClasses):
    print(myClasses[1:4])
    print("COS120" in myClasses)
    print(myClasses[2]+myClasses[3])
    print(myClasses[2])
    print(len(myClasses[2]))
    print(myClasses*2)
    print(myClasses.index("CAS120"))

#L06-2
def showTimeForClass(classes,times):  
    x=input("Class?")
    classes.index(x)
    print(times[classes.index(x)])
    
#L06-3
def showTimeForClass2(classList):
    print(classList[(classList.index(input("Class destination?"))+5)])
list2=["900","1200","200","300"]
list1=["COS120","CAS120","IAS110","BIBLIT"]
combined=list1+list2

    
#L06-4
def demoListMethods(aList):
    aList.append('whyamidoingthisloljk')
    print(aList)
    aList.insert(2,"sorryforpartyrockin")
    print(aList)
    aList.pop(2)
    print(aList)
    aList.sort()
    print(aList)
    aList.reverse()
    print(aList)
    print(aList[1])
    print(aList.count("COS120"))
    aList.remove("COS120")
    print(aList)
#L06-5
def reverseList(aList):   
    print(aList[::-1])
    print(aList[4]+aList[3]+aList[2]+aList[1]+aList[0])
    print(aList.pop()+aList.pop()+aList.pop()+aList.pop()+aList.pop())
#L06-6
def shuffleToNewList(aList):
    import random
    result = ["COS120","CAS120","IAS110","BIBLIT"]
    result2 = []
    while len(aList) > 0:
        index = random.randrange(0,len(aList))
        result2.append(aList.pop(index))
    print(result,result2) 
#L06-7
def shuffleInList(aList):
    import random
    result = []
    while len(aList) > 0:
        index = random.randrange(0,len(aList))
        result.append(aList.pop(index))
    print(result) 







def main():
    list1=["COS120","CAS120","IAS110","BIBLIT"]
    #showListFunctions(list1)
    #list2=["900","1200","200","300"]
    #showTimeForClass(list1,list2)
    #showTimeForClass2(combined)
    #demoListMethods(list1)
    #list3=["1","2","3","4","5"]
    #reverseList(list3)
    shuffleToNewList(list1)
    #shuffleInList(list1)



main()
