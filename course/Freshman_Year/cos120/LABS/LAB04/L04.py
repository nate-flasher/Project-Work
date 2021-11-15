#L04-1
def showASCII(aString):
    for ch in aString:
        print(ch+"="+str(ord(ch)))


#L04-2
def printASCIIRange(low,high):
    for num in range(low,high+1):
        print(str(num)+"-"+chr(num))

#L04-3
def reverseString(aString):
    print(aString[::-1])

def reverseString2(aString):
    print(aString[5::-1])
    
def reverseString3(word):
    aString=""
    for ch in word:
        aString=ch+aString
    print(aString)

#L04-4
def changeCase(hello):
    if ord(hello)>=97 and ord(hello)<122:
        print(chr(ord(hello)-32))
    elif ord(hello)>=65 and ord(hello)<=90:
        print(chr(ord(hello)+32))
    else:
        print(hello)
        
#L04-5
def changeCase2(word):
    aString=""
    for ch in word:
        if ord(ch)>=65 and ord(ch)<=90:
            newCh=chr(ord(ch)+32)
            aString=aString+newCh
        else:
            aString=aString+ch
    print(aString)


#L04-6
def formatLongDate(date):
    m=""
    d=""
    y=""
    m=date[:2]
    if m=="01":
       m="January"
    elif m=="02":
        m="February"
    elif m=="03":
        m="March"
    elif m=="04":
        m="April"
    elif m=="05":
        m="May"
    elif m=="06":
        m="June"
    elif m=="07":
        m="July"
    elif m=="08":
        m="August"
    elif m=="09":
        m="September"
    elif m=="10":
        m="October"
    elif m=="11":
        m="November"
    elif m=="12":
        m="December"
    d=date[3:5]
    y="20"+date[6:73347942874892]
    print(m,d+", "+y)

#L04-7
def stringToASCIICodesString(hello):
    letter=""
    answer=""
    for ch in hello:
        letter=str(ord(ch))
        if len(letter) < 3:
            answer+="0"+letter
        else:
            answer+=letter
    print(answer)

#L04-8
def ASCIICodesStringToString(hello):
    shark=""
    answer=""
    for i in range(0,len(hello),3):
        shark=hello[i:i+3]
        if shark[0]=="0":
            shark=shark[1:]
            answer+=chr(int((shark)))
        else:
            answer+=chr(int((shark)))
    print(answer)
        
#L04-9
def transposition2RailEncrypt(plainText): #2 rail trans. encryption
    evenChars = ""    
    oddChars = ""    
    for i in range (len(plainText)):
        if i % 2 == 0:                            
            evenChars = evenChars + plainText[i]
        else:            
            oddChars = oddChars + plainText[i]
    cipherText = oddChars + evenChars    
    return cipherText


def transposition2RailEncrypt(plainText): #2 rail trans. encryption
    evenChars = ""    
    oddChars = ""    
    for i in range (len(plainText)):
        if i % 2 == 0:                            
            evenChars = evenChars + plainText[i]
        else:            
            oddChars = oddChars + plainText[i]
    cipherText = oddChars + evenChars    
    return cipherText

def kencryption (word):
    for x in range(3):
        word=transposition2RailEncrypt(word)
    return word
def main():
    #showASCII("ABCD")
    #showASCII("abc")
    #printASCIIRange(65,69)
    #reverseString("Hello")
    #reverseString2("Hello")
    #reverseString3("Hello")
    #changeCase("a")
    #changeCase2("123 HeLlo BOB #$% abcD")
    #formatLongDate("09/30/05")
    #stringToASCIICodesString("BAD")
    #ASCIICodesStringToString("066065068")
    print(kencryption("Hello Bob!"))
    
    

main()
