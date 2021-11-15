import random
#L10-01
def commonLists(lst1,lst2):
    count=0
    if lst1[0] in lst2:
        count+=1
    if lst1[1] in lst2:
        count+=1
    if lst1[2] in lst2:
        count+=1

    return count

#L10-02
def scrambleEachList(aListOfLists):
    for list in aListOfLists:
        random.shuffle(list)
        
    return aListOfLists

#L10-03
def aListOfListsDupes(aListOfLists):
    duplist1=[]
    duplist2=[]
    newlist=[]
    for lst in aListOfLists:
        duplist1=[]
        duplist2=[]
        for item in lst:
            if item not in duplist1:
                duplist1.append(item)
            elif item not in duplist2:
                duplist2.append(item)
        newlist.append(duplist2)
    return newlist
                      
#L10-04
def sumTheListPositions(ListOfLists1,ListOfLists2):
    newList=[]
    for numList in range(len(ListOfLists1)):
        subList1=ListOfLists1[numList][:]
        subList2=ListOfLists2[numList][:]
        subTemp=[]
        if len(subList1)==0:
            subTemp=subList2[:]
        elif len(subList1)>=len(subList2):
            for numPos in range(len(subList1)):
                if numPos<=(len(subList2)):
                    subTemp.append(subList1[numPos]+subList2[numPos])
            else:
                subTemp.append(subList1[numPos])
        else:
            for numPos in range(len(subList2)):
                if numPos<=len(subList1):
                    subTemp.append(subList2[numPos])
        newList.append(subTemp)
    return newList

#L10-05
def sortCounts(aDictionary):
    for x in aDictionary:
        aDictionary[x].sort()
    return aDictionary
    

        

        
    
    




def main():
    manyLists=[[2,1,3,1,3,2],[3,4,5,6,7],[9,4,2,7,8,6,3,1,9],[12,3,2,1,2]]
    moreLists = [[5,4,6],[2,1,3,9],[6,7,5,8,4]]
    moreListsB = [[5,5,4,6,5,6], [6,7,5,8,4],[2,1,3,9,8]]
    d1={"Bob":[5,4,3,2,1,2],"Sue":[2,3,1,4,4,3,2],"Jill":[6,5,6,4,3,1]}
    d2={"Joe":[3,1,4,4],"Sally":[5,1,3,7],"Bob":[2,2,3,3,2]}

    #print(commonLists(moreLists, moreListsB))
    #print(scrambleEachList(moreLists))
    #print(aListOfListsDupes(moreListsB))
    print(sumTheListPositions([[7,8],[]],[[3,4,2],[6,9]]))
    #print(sortCounts(d1))
main()
