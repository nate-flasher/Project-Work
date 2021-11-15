#L09-1
def intDivR(dividend, divisor):
    if dividend-divisor<=divisor:
        return 1
    else:
        return intDivR(dividend-divisor,divisor)+1

#L09-2
def modulusR(dividend, divisor):
    if dividend-divisor<=divisor:
        return dividend-divisor
    else:
        return modulusR(dividend-divisor,divisor)

#L09-3

#Don't need to do I was told

#L09-4
def reverseFile(inFileName, outFileName):
    infile=open(inFileName, "r")
    outfile=open(outFileName, "w")
    L1=[]
    for line in infile:
        L1.append(line)
    L1.reverse()
    for i in L1:
        outfile.write(i)
        print(i)
    infile.close()
    outfile.close()

#L09-5
def rewriteFile(inFileName):
    infile=open(inFileName, "r")
    newlist=[]
    anotherlist=[]
    for line in infile:
        values=line.split()
        newlist.append(values)
    while len(newlist)>=1:
        smallest=newlist[0]
        for item in newlist:
            if item[1]<smallest[1]:
                smallest=item
        newlist.remove(smallest)
        anotherlist.append(smallest)
    infile.close()
    outfile=open(inFileName, "w")
    for something in anotherlist:
        string=""
        for i in range(len(something)):
            string+=something[i]
            string+=" "
        outfile.write(string+"\n")
    outfile.close()

#L09-6
def printAirlines(airD):
    for key in airD:
        print(key)
#L09-7
def printAirlinesWithFlight(airD,withFlight): 
    for key in airD:
        for i in airD[key]:
            if withFlight==i:
                print(key, withFlight)

#L09-8
def printAirlineFlightNums(airD): 
    for airline in airD:
        for flightNumber in airD[airline]:
                print(airline,flightNumber)

#L09-9
def printAirlineFlightsDepartFrom(airD,fromCity): 
    for airline in airD:
        for flightNumber in airD[airline]:
            if fromCity==airD[airline][flightNumber][0][0]:
                print(airline,flightNumber)

#L09-10
def printAirlineFlightNumsSorted(airD): 
    for airline in airD:
        newlist=[]
        for flightNumber in airD[airline]:
            newlist.append(flightNumber)
        newlist.sort()
        print(airline,newlist)
            
    
def main():
    #print(intDivR(13,3))
    #print(modulusR(13,3))
    #reverseFile("earthquakes.txt","reversed.txt")
    #rewriteFile("earthquakes.txt")
    flightsD={"Delta":{1102:[["IND",1850],["MDW",1955]],
                   1096:[["PHX",900],["MDW",1255]],
                   1445:[["ATL",1135],["LAX",1810]],
                   1776:[["PHL",1350],["RAP",1610]],
                   1226:[["PHX",950],["MDW",1345]],
                   1885:[["ATL",1305],["LAX",2000]],
                   1009:[["MDW",1850],["IND",1955]],
                   9001:[["MDW",2145],["IND",2255]]},
          "Southwestern":{1111:[["SAT",430],["MDW",825]],
                          2121:[["MDW",430],["SAT",825]],
                          4335:[["PHX",450],["MDW",745]],
                          1102:[["MDW",1100],["PHX",1450]]},
          "American":{7765:[["IND",1850],["CHA",2105]],
                   2133:[["BNA",900],["IND",1115]],
                   3321:[["HOU",1335],["ATL",1615]],
                   2100:[["BNA",900],["IND",1115]],
                   4311:[["HOU",905],["ATL",1255]],
                   5577:[["ATL",1100],["HOU",1350]],
                   1102:[["BNA",1100],["HOU",1450]]}}
    #printAirlines(flightsD)
    #printAirlinesWithFlight(flightsD,1102)
    #printAirlineFlightNums(flightsD)
    #printAirlineFlightsDepartFrom(flightsD,"PHX")
    printAirlineFlightNumsSorted(flightsD)
    
    





main()
