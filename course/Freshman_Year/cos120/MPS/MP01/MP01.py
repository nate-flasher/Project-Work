import random

def guessingGame(start,stop,step):

    randomNumber=random.randrange(start,stop,step)

    
    print("You are to guess a number between 0 and 200 inclusive, in 10 guesses or less!")
    for i in range(10):
        a=int(input("Guess?"))
        if a==randomNumber:
            print("You guessed it!")
            return
        if a<randomNumber:
            print("LOW guess")
        if a>randomNumber:
            print("High guess")
    print("Out of guesses!")
        
#guessingGame(0,200,1)


def guessingGame(start,stop,step):

    randomNumber=random.randrange(start,stop,step)

    
    print("You are to guess a number between 50 and 20234 inclusive, in 3 guesses or less!")
    for i in range(3):
        a=int(input("Guess?"))
        if a==randomNumber:
            print("You guessed it!")
            return
        if a<randomNumber:
            print("LOW guess")
        if a>randomNumber:
            print("High guess")
    print("Out of guesses!")



guessingGame(50,20234,3)
   
