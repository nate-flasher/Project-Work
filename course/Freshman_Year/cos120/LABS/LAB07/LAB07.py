


#L07-01
def function1():
    for i in w:
        print(i)

#L07-02
def function2(d):
    x=list(d.items())
    return x

#L07-03
def function3(d):
    p=[]
    for i in d:
        temp=(i,d[i])
        p.append(temp)
    p.sort()
    print(p)
    
#L07-04
def function4(d):
    p=[]
    for i in d:
        temp=(d[i],i)
        p.append(temp)
    p.sort()
    print(p)

#L07-05
def function5(d):
    x=int(input("Enter Value"))
    d.append(x)
    print(d)

#L07-06
def function6(d):
    x=input("Enter Key")
    y=int(input("Enter Value"))
    d.update( {x : y} )
    print(d)
#L07-07
def function7(d):
    x=input("Enter Key")
    if x in d:
        return x
    else:
        return "No such value"

#L07-08
def function8(d):
    y=int(input("Enter Value"))
    if d.count(y) > 0:
        return True
    else:
        return False
#L07-09
def function9(d):
    new_list = []
    while d:
        minimum = d[0]  
        for x in d: 
            if x < minimum:
                minimum = x
        new_list.append(minimum)
        d.remove(minimum)    
    print(new_list)

#L07-10
def function10(d,c):
    mergedList=d+c
    new_list = []
    while mergedList:
        minimum = mergedList[0]  
        for x in mergedList: 
            if x < minimum:
                minimum = x
        new_list.append(minimum)
        mergedList.remove(minimum)    
    print(new_list)

#L07-11
def function11(d,c):
    mergedList=d+c
    mergedList.sort()
    print(mergedList)
#L07-12
##import turtle
def function12(t,aList,s):
    turtle.tracer(False)
    minx=aList[0][0]
    miny=aList[0][0]
    maxx=aList[0][0]
    maxy=aList[0][0]
    for i in range(len(aList)):
        if minx>aList[i][0]:
            minx=aList[i][0]
        if miny>aList[i][1]:
            miny=aList[i][1]
        if maxx<aList[i][0]:
            minx=aList[i][0]
        if maxy<aList[i][1]:
            minx=aList[i][1]
    turtle.setworldcoordinates(minx-10,miny-10,maxx+10,maxy+10)
    t.up()
    t.home()
    t.down()
    t.fd(s.window_height()//2)
    t.bk(s.window_height())
    t.up()
    t.home()
    t.down()
    t.rt(90)
    t.fd(s.window_width()//2)
    t.bk(s.window_width())
    for i in range(len(aList)):
        t.up()
        t.goto(aList[i][0],aList[i][1])
        t.down()
        t.dot()
    turtle.tracer(True)
    t.ht()
#L07-13
def function13(aDict):
    aList=list(aDict.values())
    newDict={}
    for i in aList:
        if aList.count(i)>1:
            return newDict
    for key in aDict:
        newDict[aDict[key]]=key
    return newDict
    
               
        
    
    

def main():
    w=[83,99,2,3,1,7,54,1]
    x=[23,12,67,5,4,11,2,84,12,16]
    y={"staplers":2,"pencils":45,"erasers":12,"paper clips":200, "pens":84,"markers":12}
    z={23012:2,77321:5,32332:234,77656:16,21321:802,99876:3}
    k=[[39,2],[16,5],[14, 99],[2,1],[28,12],[12,28],[20,50],[38,77]]
    q={"a":5, "b":12, "k":13}
    
    
    #function1()
    #print(function2(y))
    #function3(y)
    #function4(y)
    #function5(w)
    #function6(y)
    #print(function7(y))
    #print(function8(w))
    #function9(w)
    #function10(w,x)
    #function11(w,x)
    print(function13(q))


##    s=turtle.getscreen()
##    bob=turtle.Turtle()
    #function12(bob,k,s)


main()
