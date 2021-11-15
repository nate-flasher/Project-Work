#L05-1
def aFunction(z):
    addingOne=0
    for i in z:
        print(z[addingOne])
        addingOne=addingOne+1

#L05-2
def aFunction2(z):
    for i in z:
        print(i)

#L05-3
def aFunction3(z):
    aString=""
    for i in z:
        aString=(aString+i)

        print(aString)

#L05-4
def aFunction4(z):
    for i in range(5):
        print(z[0:i+1])

#L05-5
def aFunction5(z):
    aString=""
    for i in z:
        aString=(i+aString)

        print(aString)

#L05-6
def aFunction6(z):
    for i in range(5):
        print(z[::-1][:i+1])

#L05-7
def aFunction7(aString):
    result = 0
    for char in aString:
        result += 1 
    print(result)

#L05-8
def aFunction8(inString,From,To):
    aString=""
    for i in range(From,To):
        aString=(aString+inString[i])

    print(aString)

#L05-9
def aFunction9(findString,targetString):
    for index in range(len(targetString)-len(findString)+1):
        if targetString[index:index+len(findString)]==findString:
            return True
        return False

#L05-10
def aFunction10(firstString,secondString):
    aString="ab"
    aString=aString.replace('a', firstString)
    aString=aString.replace('b', secondString)
    print(aString)
#L05-11
def aFunction11(findString,targetString):
    for iters in range(len(targetString)-len(findString)+1):
        match=True
        location=iters
        for findex in range(len(findString)):
            if findString[findex]!=targetString[findex+iters]:
                match=False
            if match:
                return location
    return -1
#L05-12
def aFunction12(inString,findString,rp1String):
    for i in range(len(inString)):
        idx=inString.find(findString)
        if idx !=-1:
            inString=inString[:idx]+rp1String+inString[idx+len(findString):]
        return inString
    
            
    

def main():
    #aFunction("right")
    #aFunction2("right")
    #aFunction3("right")
    #aFunction4("right")
    #aFunction5("hello")
    #aFunction6("hello")
    #aFunction7("hello")
    #aFunction8("hello my name is nate",2,4)
    aFunction9("all","none at all")
    #aFunction10("Hello123","1234")
    #print(aFunction11("all", "not in this string"))
    #print(aFunction12("I ran ran ran home!", "ran", "walked"))



main()
