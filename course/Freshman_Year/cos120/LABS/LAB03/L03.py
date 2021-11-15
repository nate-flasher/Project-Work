###L03-01
##I predict that when the code is run it will print: 4,4,4,20
##from math import *
##def demoCalls():
##    sqrt(16)
##    print(sqrt(16))
##    x=sqrt(16)
##    print(x)
##    y=sqrt(16) * sqrt(25)
##    print(y)
##demoCalls()
##I was very close. I predicted an extra 4.
##
##def mySQRT(n,iters):
##    X=1
##    for i in range(iters):
##        X=1/2*(X+n/X)
##    return X
##    
##
##def testmySQRT():
##    mySQRT(16,100)
##    print(mySQRT(16,100))
##    x= mySQRT(16,100)
##    print(x)
##    y= mySQRT(16,100) * mySQRT (25,100)
##    print(y)
##
##testmySQRT()

###L03-02
##for i in range(3):
##    print("in the loop")
##for x in range(0,3,1):
##    print("in the loop")
##for x in range(3,0,-1):
##    print("in the loop")
##x=5
##if x>3 and x<7:
##    print("in the loop","in the loop","in the loop")
##else:
##    print("")
##    
##if x>6 and x<7:
##    print("not this")
##else:
##    print("in the loop","in the loop","in the loop")

###L03-03
##def schoolDaze(y):
##    if y<1:
##        print("invalid data")
##    if y>=1 and y<=3:
##        print("they are in nursery")
##    if y>=4 and y<=5:
##        print("they are in preschool")
##    if y>=6 and y<=11:
##        print("they are in elementary")
##    if y>=12 and y<=13:
##        print("they are in middle school")
##    if y>=14 and y<=18:
##        print("they are in high school")
##    if y>18:
##        print("They are over 18")
##           
##schoolDaze(14)
##def schoolDaze2(i):
##    y=int(input("What age?"))
##    if y>=1 and y<=18:
##        if y>3:
##            if y>5:
##                if y>11:
##                    if y>13:
##                        print("The person is in high school")
##                    else:
##                        print("The person is in middle school")
##                else:
##                    print("The person is in elementary")
##            else:
##                print("The person is in preschool")
##        else:
##            print("The person is in nursery")
##
##schoolDaze2(2)

###L03-05
##    y=int(input("What age?"))
##    if y>=1 and y<=3:
##        print("The person is in nursery")
##    elif y==4 or y==5:
##        print("The person is in preschool")
##    elif y>=6 and y<=11:
##        print("The person is in elementary")
##    elif y==12 or y==13:
##        print("The person is in middle school")
##    elif y>=14 and y<=18:
##        print("The person is in high school")
###L03-06
def PRS(p1,p2):
    if p1==p2:
        print("Tie")
    elif (p1=="rock" and p2=="paper") or (p2=="rock" and p1=="paper"):
        print("Paper beats rock")
    elif (p1=="rock" and p2=="scissors") or (p2=="rock" and p1=="scissors"):
        print("Rock beats scissors")
    elif (p1=="scissors" and p2=="paper") or (p2=="scissors" and p1=="paper"):
        print("Scissors beats paper")
    else:
        print("invalid moves")
##        
##        
##PRS("rock","paper")

###L03-07
##def testPRS():
##    PRS("rock","rock")
##    PRS("paper","paper")
##    PRS("scissors","scissors")
##    PRS("rock","paper")
##    PRS("rock","scissors")
##    PRS("paper","rock")
##    PRS("paper","scissors")
##    PRS("scissors","rock")
##    PRS("scissors","paper")
##
##testPRS()

#L03-03
def calcAutoPremium(age,numDoors,gender):
    if age<21:
        if numDoors==2:
            print ("High Risk")
            premium=2500
        else:
            print ("Semi-High Risk")
            premium=1900
    else:
        if numDoors==2:
            print ("Medium Risk")
            premium=1500
        else:
            print ("Low Risk")
            premium=800
    if gender=="female":
        premium=(2/3)*premium
    else:
        premium=premium*2
    monthlyPayment=premium/12.0
    return monthlyPayment
#print (calcAutoPremium(14,4,"male"))

def testAutoPremium():
    age=0
    numDoors=0
    gender="0"
    for i in range(2):
        if i==1:
            gender="male"
        elif i==2:
            gender="female"
        for x in range(2):
            if x==1:
                numDoors=2
            elif x==2:
                numDoors=4
            for y in range(3):
                if y==1:
                    age=18
                elif y==2:
                    age=21
                elif y==3:
                    age=24


                print(calcAutoPremium(age,numDoors,gender))
testAutoPremium()


                     
                   

